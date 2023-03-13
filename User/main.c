#include "sys.h"
#include "smg.h"

#include "STC15F2K60S2.h"

void main()
{
	// Init
	Cls_Periphreal();
	
	// Start
	SMG_ShowStr(".1 2.3.4.5-");
	
	while(1)
	{
		// Loop
		SMG_Flash();
	}
}
