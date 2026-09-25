#include "amap.h"

int main() {
	while(1) 
		if (*KEY&0x1) *LED=0; 
		else              *LED=1;
}
