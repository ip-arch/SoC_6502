CC65DIR=../cc65
CC65= $(CC65DIR)/bin/cc65
CA65= $(CC65DIR)/bin/ca65
AR65= $(CC65DIR)/bin/ar65
LIBLOCAL=lib/soc6502.lib



all: $(LIBLOCAL) $(CC65)
	mkdir -p lib

SUFFIXES:

%.o : %.s
	$(CA65) $< 

$(LIBLOCAL): libsrc/soc6502/crt0.o
	mkdir -p lib
	$(AR65) a $(LIBLOCAL) $<

$(CC65):
	(cd $(CC65DIR); make bin lib TARGETS=none)

clean:
	rm -fr lib
	rm -f libsrc/soc6502/crt0.o

