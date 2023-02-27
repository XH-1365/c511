#include "sys.h"

#include "uln2003.h"
#include "138.h"

#include "STC15F2K60S2.h"

void Cls_Periphreal()
{
	P2 &= 0x1f; // 138 选中空设备
	SendTo(LED, 0xff);
	BUZZ_Power(OFF);
}
