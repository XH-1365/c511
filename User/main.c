#include "sys.h"
#include "smg.h"
#include "138.h"
#include "delay.h"
#include "DS18B20.h"

#include "STC15F2K60S2.h"

#include "stdio.h"

void main()
{
	char str[10];

	// Init
	Cls_Periphreal();
	SMG_Init();
	
	// Start
	
	while(1)
	{
		sprintf(str,"     %04.2f",rd_temperature()/16.0);
		SMG_ShowStr(0, str);
	}
}
