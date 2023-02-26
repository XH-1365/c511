#include "uln2003.h"

#include "138.h"

void ULN2003_Turn(unsigned char component, bit turn_on)
{
	static uln2003 = 0;
	
	if (turn_on)
	{
		uln2003 |= component;
	}
	else
	{
		uln2003 &= ~component;
	}
	
	SendTo(ULN2003, uln2003);
}

void BUZZ_Power(bit turn_on)
{
	ULN2003_Turn(BUZZ, turn_on);
}
