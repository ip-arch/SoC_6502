#include "amap.h"


int COLOR   = 0xF000;
int VGACLS  = 0x0FEC;

unsigned char *vgaGetAdrs(int xin, int yin) {
	return VGA + (((yin & 0x1F)<<7) | (xin & 0x7F));
}

void vgaCls() {
	*(VGA+VGACLS) = COLOR&0xff;
	*(VGAA+VGACLS) = COLOR>>8;
	while (*(VGA+VGACLS));
}

int main () {
	int x,y;
	vgaCls();
	while(1)
		for(y = 0 ; y < 30 ; y++)
			for(x = 0 ; x < 80 ; x++)
				*vgaGetAdrs(x,y)=*SW;
}

