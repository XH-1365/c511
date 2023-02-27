#include "smg.h"

#include "138.h"

#include "STC15F2K60S2.h"

typedef struct
{
	char pattern;
	unsigned char brightness;
} SMG_Unit;

SMG_Unit units[8] = {0};

void _SMG_SetTimeout(unsigned char timeout)
{
	TL0 = -timeout;		//设置定时初值
	TH0 = 0xff;		//设置定时初值
}

void Timer0Init(void)		//5微秒@11.0592MHz
{
	AUXR &= 0x80;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;
	TL0 = 0xFB;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
}

void SMG_Init(void)
{
	char i;
	for(i = 0; i < 8; ++i)
	{
		units[i].pattern = 0xff;
		units[i].brightness = 0;
	}
	
	Timer0Init();
	EA = ET0 = 1;
}

void SMG_Deinit(void)
{
	TR0 = 0;
}

void SMG_ShowPattern(unsigned char pos, unsigned char pattern, unsigned char brightness)
{
	units[pos].pattern = pattern;
	units[pos].brightness = brightness;
}

const unsigned char CHAR_PATTERN[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

void SMG_ShowChar(unsigned char pos, char ch, unsigned char brightness)
{
	char pattern = 0xff;
	if (ch >= '0' && ch <= '9')
	{
		pattern = CHAR_PATTERN[ch - '0'];
	}
	SMG_ShowPattern(pos, pattern, brightness);
}

void SMG_SetBrightness(unsigned char pos, unsigned char brightness)
{
	units[pos].brightness = brightness;
}

void SMG_ShowStr(unsigned char pos, char * str)
{
	char i;
	for(i = 0; i + pos < 8; ++i)
	{
		if (!str[i])
			return;
		SMG_ShowChar(pos + i, str[i], 100);
	}
}

void SMG_TurnOff()
{
	SendTo(SMG_POS, 0);
}

void _SMG_Flash() interrupt 1
{
	static char i = 0;
	static bit on = 0;

	if (on)
	{
		SendTo(SMG_CHAR, 0xff);
		_SMG_SetTimeout(-units[i].brightness);
		i = (i + 1) % 8;
	}
	else
	{
		SendTo(SMG_POS, 1 << i);
		SendTo(SMG_CHAR, units[i].pattern);
		_SMG_SetTimeout(units[i].brightness);
	}
	
	on = !on;
}
