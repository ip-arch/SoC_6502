#include "vga.h"
/*
// 25MHz
#define CLKDIV 0xa2 // serial baud rate
#include "vga25.nsl"
*/

// 12.5MHz
#define CLKDIV 0x51 // serial baud rate
#include "vga12.nsl"
