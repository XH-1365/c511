#include "smg.h"

#include "138.h"

#include "STC15F2K60S2.h"

unsigned char patterns[8] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

const unsigned char SMG_NUMBERS[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

void SMG_ShowChar(unsigned char pos, char ch, bit dot)
{
	char pattern = 0xff;
	if (ch >= '0' && ch <= '9')
	{
		pattern = SMG_NUMBERS[ch - '0'];
	}
	else
	{
		switch (ch) {
			case '-':
				pattern = 0xbf;
				break;
			case '.':
				pattern = ~0x80;
				break;
		}
	}
	if (dot)
	{
		pattern &= ~0x80;
	}
	patterns[pos] = pattern;
}

void SMG_ShowStr(char * str)
{
	char i;
	for(i = 0; i < 8; ++i)
	{
		bit nextIsDot = str[1] == '.';
		SMG_ShowChar(i, *str, nextIsDot);
		if (*str)
		{
			++str;
			if (nextIsDot) ++str;
		}
	}
}

void SMG_Flash()
{
	static char i = 0;
	SendTo(SMG_CHAR, 0xff);
	SendTo(SMG_POS, 1 << i);
	SendTo(SMG_CHAR, patterns[i]);
	if(++i >= 8) i = 0;
}
