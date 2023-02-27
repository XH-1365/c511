#include "sys.h"
#include "138.h"
#include "keyboard.h"

#include "STC15F2K60S2.h"

void main()
{
	// Init
	Cls_Periphreal();
	
	// Start
	
	while(1)
	{
		// Loop
		unsigned int key = KEYBOARD_Read();
		SendTo(LED, key >> 4);
	}
}
