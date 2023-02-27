#include "sys.h"
#include "smg.h"
#include "138.h"
#include "delay.h"

#include "STC15F2K60S2.h"

#include "stdio.h"

void main()
{
	char offset = 0;
	char str[] = " 114514\0 ";
	char i;
	
	// Init
	Cls_Periphreal();
	SMG_Init();
	
	// Start
	SMG_ShowStr(0, str);
	
	while(1)
	{
		// Loop
		
			for(i = 0; i < 8; ++i)
			{
				SMG_SetBrightness((offset + i) % 8, 1 << i);
			}
			offset = (offset + 1) % 8;
		
			Delay(50);
	}
}
