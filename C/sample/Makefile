TARGET = main
CFLAGS=
# cc65 for Apple-I compile sample
M65CC=../../cc65/bin/cc65$(EXE)
AS=../../cc65/bin/ca65
LD=../../cc65/bin/ld65
LIB=../../cc65-local/lib/soc6502.lib
LIBNONE=../../cc65/lib/none.lib
TYPE=../../cc65-local/cfg/soc6502.cfg

CLEANS=$(TARGET).s $(TARGET).o $(TARGET).hex $(TARGET)$(EXE) $(TARGET).map 

.c.o: $(M65CC)
	$(M65CC) -O $<
	$(AS) $*.s

.s.o:
	$(AS) $<

all:	$(M65CC) $(TARGET).hex
clean:
	-rm -f $(CLEANS)


$(TARGET)$(EXE):	$(TARGET).o
	$(LD) -o $@ -C $(TYPE) -m $(TARGET).map $(TARGET).o $(LIB) $(LIBNONE)

$(TARGET).hex:	$(TARGET)$(EXE)
	od -v -An -t x1 $< > $@
$(LIB):
	(cd ../../cc65-local; make all)

$(M65CC): $(LIB)
	(cd ../../cc65; make bin lib TARGET=none)


