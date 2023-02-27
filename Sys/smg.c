#include "smg.h"

#include "138.h"

#include "STC15F2K60S2.h"

typedef struct
{
	char pattern;
	unsigned int brightness;
} SMG_Unit;

SMG_Unit units[8] = {0};

void _SMG_SetTimeout(unsigned int timeout)
{
	// timeout = 0x4000 - (timeout >> 2);
	timeout = ~timeout;
	TL0 = timeout & 0xff;		//���ö�ʱ��ֵ
	TH0 = ((timeout >> 8) & 0xff);		//���ö�ʱ��ֵ
}

void Timer0Init(void)		//5΢��@11.0592MHz
{
	AUXR |= 0x80;		//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0xF5;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
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

void SMG_ShowPattern(unsigned char pos, unsigned char pattern, unsigned int brightness)
{
	units[pos].pattern = pattern;
	units[pos].brightness = brightness;
}

const unsigned char CHAR_PATTERN[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

void SMG_ShowChar(unsigned char pos, char ch, unsigned int brightness)
{
	char pattern = 0xff;
	if (ch >= '0' && ch <= '9')
	{
		pattern = CHAR_PATTERN[ch - '0'];
	}
	else if(ch == '-')
	{
		pattern = 0xbf;
	}
	SMG_ShowPattern(pos, pattern, brightness);
}

void SMG_SetBrightness(unsigned char pos, unsigned int brightness)
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
		SMG_ShowChar(pos + i, str[i], 60000);
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
		if (units[i].brightness)
		{
			SendTo(SMG_POS, 1 << i);
			SendTo(SMG_CHAR, units[i].pattern);
		}
		_SMG_SetTimeout(units[i].brightness);
	}
	
	on = !on;
}