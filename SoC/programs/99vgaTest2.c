#include "amap.h"

int COLOR=0xF800;

unsigned char * vgaGetAdrs(int xin, int yin){
	return VGA + (((yin & 0x1F)<<7) | (xin & 0x7F));
}

void cls() {
  int x,y;
  *VGAUB=0xf0;

  for (y=0;y<32;y++)
       for (x=0;x<80;x++)
	 *vgaGetAdrs(x,y) = 0x20;
}

int main () {
	int x,y, count;
	cls();

	*VGAUB=0xf0;
	for (y = 0; y < 16; y++) {
		for (x = 0; x < 16; x++) {
			*vgaGetAdrs(x,y) =  (y << 4) | x;
		}
	}

	count=0;
	for (x = 0; x < 80; x++) {
		*vgaGetAdrs(x,20) =  0x30 | count;
		if (count < 9) {
			count++;
		} else {
			count = 0;
		}
	}

	while(1);
}
