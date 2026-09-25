#include "amap.h"

int main () {

	while(1) {
	  *(LED+2)=*SW;
	  *(LED+3)=*(SW+1);
	}
}
