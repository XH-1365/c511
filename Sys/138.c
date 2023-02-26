#include "138.h"

#include "STC15F2K60S2.h"

void SendTo(unsigned char select, unsigned char dat)
{
	unsigned char p0 = P0, p2 = P2;
	
	P0 = dat;
	P2 = (P2 & 0x1f) | (select << 5);
	
	P2 = p2;
	P0 = p0;
}
