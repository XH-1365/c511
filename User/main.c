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
	/*
		
	*/
	//char str[] = "-114514-\0 ";
	//char str[] = "88888888";
	
	// Init
	Cls_Periphreal();
	SMG_Init();
	
	// Start
	//SMG_ShowStr(0, str);
	
	
	
	while(1)
	{
		
	}
}
