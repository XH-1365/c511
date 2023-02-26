#include "sys.h"

#include "uln2003.h"
#include "138.h"

void Cls_Periphreal()
{
	SendTo(LED, 0xff);
	BUZZ_Power(ON);
}
