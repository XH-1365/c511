#include "sys.h"
#include "smg.h"
#include "138.h"
#include "delay.h"

#include "STC15F2K60S2.h"

#include "stdio.h"
#include "math.h"

#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)

void main()
{
	int o;
	char str[] = "-114514-\0 ";
	//char str[] = "88888888";
	char i;
	
	// Init
	Cls_Periphreal();
	SMG_Init();
	
	// Start
	SMG_ShowStr(0, str);
	
	
	
	while(1)
	{
		// Loop
		
		// 渐入
		for(o = -12600; o <= 20000; ++o)
		{
			for(i = 0; i < 8; ++i)
			{
				SMG_SetBrightness(i, max(min(o + i * 1800, 20000), 0) << 1);
			}
		}
		
		// 维持
		Delay(4000);
		
		// 渐出
		for(o = 0; o <= 32600; ++o)
		{
			for(i = 0; i < 8; ++i)
			{
				SMG_SetBrightness(i, max(min(32600 - o - i * 1800, 20000), 0) << 1);
			}
		}
		
		// 维持
		Delay(2000);
	}
}
