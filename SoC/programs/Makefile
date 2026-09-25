###############################################################################
# Makefile for exercise in 17th PARTHENON Workshop
# (GNU make is required)
# Usage:
#      To compile all .c files   : make
#      To compile .c to .s     : make <xxxx.hex>
#      To write .hex file to FPGA : make <xxxx.write>
#          The contents of xxx.hex is stored in instruction memory (imem)
#      To read .hex file from FPGA: make FILE=<xxx.hex> <xxx.hex>
#          The contents of data memory (dmem) is stored in xxx.hex
###############################################################################
# 2014-02-28 : modified to use with m65 by N.Shimizu
# 2010-09-12 : Initial version by Y.Okuyama
###############################################################################
M65CDIR		= ../../cc65
M65LDIR		= ../../cc65-local
M65C		= $(M65CDIR)/bin/cc65
M65ASM		= $(M65CDIR)/bin/ca65 --include-dir $(M65CDIR)/asminc
M65LD		= $(M65CDIR)/bin/ld65
M65CFG		= $(M65LDIR)/cfg/soc6502.cfg
M65LIB		= $(M65LDIR)/lib/soc6502.lib
M65NONELIB	= $(M65CDIR)/lib/none.lib
INPUTS		= $(wildcard *.c)
OUTPUTS		= $(INPUTS:.c=.hex)
FILE=

all: $(M65C) $(OUTPUTS)

$(M65C):
	cd $(M65CDIR); make bin lib TARGETS=none

$(M65LIB):
	cd $(M65LDIR); make all

$(FILE):
	quratus_stp -t ./mem_read rom $(FILE)

download:
	cd ../rtl; make download
clean:
	rm -f *.s *.o *.exe *.hex *~


################################
# suffix rules
################################
.SUFFIXES:  .c .hex .s .s .o .exe .write

%.s: %.c $(M65C)
	$(M65C) $<
%.exe: %.s $(M65C)
	$(M65ASM) $< 
	$(M65LD) -o $*.exe -C $(M65CFG) $*.o $(M65LIB) $(M65NONELIB)
%.hex: %.exe
#	od -v -An -t x1 $< > $@
	od -v -An -t x1 $< | gawk -f od2hex.awk > $@
.hex.write:
	quartus_stp -t ./mem_write imem $<

