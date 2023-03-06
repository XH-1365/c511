#include "sys.h"
#include "smg.h"
#include "adc.h"

/*------------------------*/
#include "stdio.h"

void main()
{
	char str[10];
	unsigned char Rb2;
	// Init
	Cls_Periphreal();
	init_pcf8591();
	SMG_Init();
	// Start
	while(1)
	{
		// Loop
		Rb2 = adc_pcf8591();
		sprintf(str," %3d",(unsigned int)Rb2);
		SMG_ShowStr(0, str);
	}
}
