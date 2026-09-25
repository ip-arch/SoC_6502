; ---------------------------------------------------------------------------
; crt0.s
; ---------------------------------------------------------------------------
;
; Startup code for cc65 (Single Board Computer version)

.export   _init, _exit
.export   _irqvec, _nmivec, _brkvec
.export   _sei, _cli
.import   _main

.export   __STARTUP__ : absolute = 1        ; Mark as startup
.import   __RAM_START__, __RAM_SIZE__       ; Linker generated
.import   __DATA_LOAD__, _DATA_RUN__, __DATA_SIZE__ ; Linker generated values

.import    copydata, zerobss, initlib, donelib

.include  "zeropage.inc"

; ---------------------------------------------------------------------------
; Place the startup code in a special segment

.bss
_irqvec: .word	0
_brkvec: .word	0
_nmivec: .word	0

.segment  "STARTUP"

; ---------------------------------------------------------------------------
; A little light 6502 housekeeping

_init:    LDX     #$FF                 ; Initialize stack pointer to $01FF
          TXS
          CLD                          ; Clear decimal mode
          SEI                          ; Set interrupt disable

; ---------------------------------------------------------------------------
; Set cc65 argument stack pointer

          LDA     #<(__RAM_START__ + __RAM_SIZE__)
          STA     sp
          LDA     #>(__RAM_START__ + __RAM_SIZE__)
          STA     sp+1

; ---------------------------------------------------------------------------
; Initialize memory storage

          JSR     zerobss              ; Clear BSS segment
          JSR     copydata             ; Initialize DATA segment
          JSR     initlib              ; Run constructors
;
; ---------------------------------------------------------------------------
; Set interrupts vectors
	  LDA     #<(_rts)
          STA     _irqvec  
	  LDA     #>(_rts)
          STA     _irqvec+1
	  LDA     #<(_rts)
          STA     _nmivec  
	  LDA     #>(_rts)
          STA     _nmivec+1
	  LDA     #<(_rts)
          STA     _brkvec  
	  LDA     #>(_rts)
          STA     _brkvec+1
; ---------------------------------------------------------------------------
	  CLI			       ; Clear interrupt disable

; ---------------------------------------------------------------------------
; Call main()

          JSR     _main

; ---------------------------------------------------------------------------
; Back from main (this is also the _exit entry):  force a software break

_exit:    JSR     donelib              ; Run destructors
	  BRK

; ---------------------------------------------------------------------------
; interrupt.s
; ---------------------------------------------------------------------------
;
; Interrupt handler.
;
; Checks for a BRK instruction and returns from all valid interrupts.

.import   _stop
.export   _irq_int, _nmi_int

.segment  "CODE"

.P02                             ; Force 65C02 assembly mode

; ---------------------------------------------------------------------------
; Non-maskable interrupt (NMI) service routine

_nmi_int:  
	CLD
	PHA
	TXA
	PHA
	TYA
	PHA
	JSR	_nmired
_nmi:
	PLA
	TAY
	PLA
	TAX
	PLA
	RTI                    ; Return from all NMI interrupts
_nmired:
	JMP	(_nmivec)

; ---------------------------------------------------------------------------
; Maskable interrupt (IRQ) service routine

_irq_int:  
	   CLD
           PHA
           TXA
           PHA
	   TYA
	   PHA
           TSX                    ; Transfer stack pointer to X
           INX			  ; P is on the stack
           INX			  ; We need to use INX because
           INX			  ; $103,X will not work on wrap around.
           INX			  ; 
           LDA $100,X             ; Load status register contents
           AND #$10               ; Isolate B status bit
           BNE break              ; If B = 1, BRK detected

; ---------------------------------------------------------------------------
; IRQ detected, return

irq:       
	   JSR _irqred
_irq:      
	   PLA
	   TAY
	   PLA
	   TAX
	   PLA
	   RTI                    ; Return from all IRQ interrupts
_irqred:
           JMP	(_irqvec)

; ---------------------------------------------------------------------------
; BRK detected, redirect to brkvec and rti

break:     
	JSR _brkred
_brk:	
	   PLA
	   TAY
	   PLA
	   TAX
	   PLA
	   RTI
_brkred:
	JMP (_brkvec)

_rts:
	  RTS
_sei:
	  SEI
	  RTS
_cli:
	  CLI
	  RTS
; ---------------------------------------------------------------------------
; vectors.s
; ---------------------------------------------------------------------------
;
; Defines the interrupt vector table.

;.import    _init
;.import    _nmi_int, _irq_int

.segment  "VECTORS"

.addr      _nmi_int    ; NMI vector
.addr      _init       ; Reset vector
.addr      _irq_int    ; IRQ/BRK vector

