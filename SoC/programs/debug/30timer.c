#define TIMER_CNTEN  0x01
#define TIMER_INTEN  0x02
#define TIMER_RD     0x04
#define TIMER_LD     0x08
#define TIMER_INTREQ 0x80


void sei();
void cli();
extern int *irqvec;
char  *printstr = "Hello World!\n";

int count;
long long int time;

void foo () {
  sei();
  *(TIMER+4) &= ~TIMER_INTRQ;
  count++;
  *LED=count;
  
  *(TIMER+4)|= TIMER_LD;
  cli();
  return ;
}


int main () {
	char c;
	sei();
	time=50000000;
	irqvec = (void*)foo;
	*TIMER=time;

	count=0;
	*LED=count;

	*(TIMER+4) |= TIMER_LD | TIMER_INTEN | TIMER_CNTEN;
	cli();
	while(1);
	return 0;
}


