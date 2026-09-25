#define DISP	(*(unsigned char *)0xd012)
void sei();
void cli();
extern int *irqvec;
char  *printstr = "Hello World!\n";
void foo () {
  DISP='I';
  return ;
}
int main () {
	char c;
sei();
  irqvec = (int*)foo;
cli();
	while(c=*printstr++) {
		while(!(DISP & 0x80));
		DISP=c;
	}
	return 0;
}


