################################################################################
# Makefile : sof file generation using Quartus II
# Usage:
#		make compile for synthesis all files
#       make download for download .sof file to FPGA board
################################################################################
# 2011-09-12,13 Initial version by Y.Okuyama (based on PICO's makefile)
# 2012-10-08    CABLE is modified for linux environment
# 2013-03-20    Adopted for snx2013
# 2014-02-28    Adopted for m65 by N.Shimizu
# 2014-03-11    PS/2 keyboard and timer by N.Shimizu and Y.Okuyama
# 2014-04-07	DE0 is Supported
################################################################################

ifndef SRCDIR
SRCDIR	= .
endif
M65DIR		= $(SRCDIR)/../../m65nsl
WORKDIR		= synth
VPATH		= $(SRCDIR):$(SRCDIR)/MEM:$(SRCDIR)/LCD:$(SRCDIR)/VGA:$(M65DIR)
ifndef DESIGN
DESIGN		= DE10
endif
NSL2VL    	= nsl2vl
NSLFLAGS  	= -sim -neg_res -I$(SRCDIR) -I$(SRCDIR)/MEM -I$(SRCDIR)/LCD -I$(SRCDIR)/VGA
MKPROJ		= $(SRCDIR)/mkproj-$(DESIGN).tcl
Q2SH		= quartus_sh
Q2PGM		= quartus_pgm
#CABLE		= "USB-Blaster [USB 1-1.4]"
CABLE		= "USB-Blaster"
PMODE		= JTAG

#SRCS		= DE2_115.nsl HEX.nsl LED.nsl key.nsl sw.nsl \
		  m65.nsl m65_system.nsl VGA_ctrl.nsl ps2in.nsl timer.nsl
SRCS		= $(DESIGN).nsl HEX.nsl LED.nsl key.nsl sw.nsl sound.nsl\
		  m65.nsl m65_system.nsl VGA_ctrl.nsl ps2in.nsl timer.nsl
VFILES 		= $(SRCS:%.nsl=%.v)
LIBS		= imem.v dmem.v \
		  LCD_controller.v dpram8x32.v \
		  RAM2P_16x4K.v ROM_8x4K.v
MIFS		= VGA/VRAM.mif VGA/CGROM.mif
RESULT		= result.txt

########

all:
	@if [ ! -d $(WORKDIR) ]; then \
		echo mkdir $(WORKDIR); \
		mkdir $(WORKDIR); \
	fi
	( cd $(WORKDIR); make -f ../Makefile SRCDIR=.. compile )

########

.SUFFIXES: .v .nsl

.nsl.v:
	$(NSL2VL) $(NSLFLAGS) $< -o $@

$(DESIGN).qsf: $(VFILES) $(LIBS)
	$(Q2SH) -t $(MKPROJ) -project $(DESIGN) $^

$(DESIGN).sof: $(DESIGN).qsf $(MIFS)
	$(Q2SH) --flow compile $(DESIGN)

########

compile: $(DESIGN).sof
	@echo "**** $(DESIGN).fit.summary" | tee -a $(RESULT)
	@cat $(DESIGN).fit.summary | tee -a $(RESULT)
	@echo "**** $(DESIGN).tan.rpt" | tee -a $(RESULT)
#	@grep "Info: Fmax" $(DESIGN).tan.rpt | tee -a $(RESULT)

download: config-n

config: all
	$(Q2PGM) -c $(CABLE) -m $(PMODE) -o "p;$(WORKDIR)/$(DESIGN).sof"
config-n: # without re-compile
	$(Q2PGM) -c $(CABLE) -m $(PMODE) -o "p;$(WORKDIR)/$(DESIGN).sof"

clean:
	rm -rf - $(WORKDIR)

########

DE2_115.v	: DE2_115.nsl m65.inc m65_system.inc dmem.inc imem.inc \
		  HEX.inc LED.inc key.inc sw.inc ps2in.inc timer.inc \
		  LCD_controller.inc VGA_ctrl.inc
DE0.v		: DE0.nsl m65.inc m65_system.inc dmem.inc imem.inc \
		  HEX.inc LED.inc key.inc sw.inc ps2in.inc timer.inc \
		  LCD_controller.inc VGA_ctrl.inc
HEX.v		: HEX.inc HEX.nsl
LED.v		: LED.inc LED.nsl
key.v		: key.inc key.nsl
sw.v		: sw.inc sw.nsl
ps2in.v		: ps2in.inc ps2in.nsl
timer.v		: timer.inc timer.nsl
VGA_ctrl.v	: VGA_ctrl.inc VGA_ctrl.nsl
