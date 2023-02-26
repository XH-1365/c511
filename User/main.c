#include "sys.h"
#include "138.h"
#include "delay.h"
#include "STC15F2K60S2.h"

void main()
{
	// Init
	Cls_Periphreal();
	
	// Start
	
	while(1)
	{
		// Loop
		LED_Set(~0x01);
		Delay(1000);
		LED_Set(~0x00);
		Delay(1000);
	}
}
