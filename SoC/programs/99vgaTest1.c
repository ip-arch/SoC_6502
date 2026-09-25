#include "amap.h"

int numToAscii=0x30;

char *vgaGetAdrs(int xin, int yin) {
	return VGA +( ((yin & 0x1F)<<7) | (xin & 0x7F));
}
int inc10(int in) {
	if (in>8) return 0;
	else return in+1;
}

int main () {
	int count=0;
	int x,y;
	*VGAUB=0xf0;
	for(y = 0 ; y < 30 ; y++){
		count = 0;
		for(x = 0; x < 80; x++){
			*vgaGetAdrs(x,y)=  numToAscii | count;
			count = inc10(count);
		}
	}
	while(1);
}

