#include "amap.h"
void wait(){
	int i,j;
	for(j=0; j< 0x3; j++)
		for(i=0; i< 0x7FFF; i++);
}
int main () {
	int c=0;
	while(1){
		wait();
		*LED=c;
		c++;
	}
}

