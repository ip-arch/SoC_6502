#include "amap.h"

int count=0;

int edge[2]={1,1};

int dec[16]={
 0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x58,
 0x00, 0x18, 0x08, 0x03, 0x27, 0x21, 0x06, 0x0e};

int digit[4]={0,0,0,0};

int digitmax[4]={9,9,5,9};

int edgeDetect(){
	edge[1]=edge[0];
	edge[0]=(*KEY)&0x1;
	if(edge[0]==0)
		if(edge[1]==1) return 1;
	return 0;
}

int segDec(int in){
	if (in>0xF) {
		return dec[in & 0x0F];
	} else {
		return dec[in] | 0x80;
	}
}  

void dispDigit(){
	int i;
	for( i = 0 ; i < 4 ; i++){
		*(HEX+i)=segDec(digit[i]);
	}
}

void countup(){
	int i;
	for (i = 0; i < 4; i++) {
		if (digit[i] < digitmax[i]) {
			digit[i] = digit[i] + 1;
			return;
		} else {
			digit[i] = 0;
		}
	}
}

int main () {

	while(1){
		dispDigit();
		if(edgeDetect()) countup();
	}
}
