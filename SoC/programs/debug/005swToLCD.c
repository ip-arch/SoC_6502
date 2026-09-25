#include "amap.h"

int main () {
	unsigned char i;
	for(i=0;i<32;i++) *(LCD+i)=0x20;
	while(1) {
	   for(i=0;i<10;i++) {
		*LED = i;
		LCD[i]=*SW;
	  //*(LCD+i)=*SW; //
	}
	  /*	  *(LCD+1)=*SW;
	  *(LCD+2)=*SW;
	  *(LCD+3)=*SW;
	  *(LCD+4)=*SW;
	  *(LCD+5)=*SW;
	  *(LCD+6)=*SW;
	  *(LCD+7)=*SW;
	  *(LCD+8)=*SW;
	  *(LCD+9)=*SW;
	  *(LCD+10)=*SW;*/

	}
	return 0 ;
}
