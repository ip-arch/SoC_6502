#include "amap.h"

int main () {

	while(1) {
		*LED=*SW;
		*(LED+1)=*(SW+1);
	}
}
