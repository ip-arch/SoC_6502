M65DIR=../../m65nsl
M65SRC=$(addprefix $(M65DIR)/, model.h m65.nsl alu65.nsl cpa.nsl inc16.nsl)
AP1SRC=ap1.nsl
AP1DAT=
CLEANS=ap1.v ap1.vvp ap1.log ap1.vcd
TARGET=../sample/main.hex

all: ap1.log

clean:
	-rm $(CLEANS)

ap1.v: $(M65SRC) $(AP1SRC)
	nsl2vl ap1.nsl -verisim2 -target ap1

ap1.vvp: ap1.v
	iverilog -o ap1.vvp ap1.v

ap1.log: ap1.vvp $(AP1DAT) $(TARGET)
	vvp ap1.vvp | tee ap1.log

$(TARGET):
	(cd ../sample; make)

