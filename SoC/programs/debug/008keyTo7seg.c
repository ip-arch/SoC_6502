#include "amap.h"



char segDec(int in){
  switch (in & 0xF){
  case 0 : return 0x40;
  case 1 : return 0x79;
  case 2 : return 0x24; 
  case 3 : return 0x30;
  case 4 : return  0x19;
  case 5 : return  0x12;
  default : return 0xff;
  }
}

int main () {
	while(1)
		*HEX=segDec(*SW);
	return 0;
}
