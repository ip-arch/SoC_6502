#include <6502.h>
#include "amap.h"
#define TIMER_CNTEN  0x01
#define TIMER_INTEN  0x02
#define TIMER_RD     0x04
#define TIMER_LD     0x08
#define TIMER_INTREQ 0x80

int count;
long time;

unsigned char foo () {
    *(TIMER+4) &= ~TIMER_INTREQ;
    count++;
    *LED=count;
    *(TIMER+4)|= TIMER_LD;
  return IRQ_HANDLED;
}


int main () {
extern int* irqvec;
	SEI();
	  time=50000000;
	  irqvec=(int*)foo;
	  count=0;
	  *LED=count;
	  *(long*)TIMER = time;
	  *(TIMER+4) |= TIMER_LD | TIMER_INTEN | TIMER_CNTEN;
	CLI();
	while(1);
}


