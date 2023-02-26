#include "delay.h"
#include "intrins.h"

//函数名：等待函数 
//输入：延时的数值，2个字节，16位
//输出：无
//函数功能：等待

void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}

void Delay(unsigned int num) 
{
  while(num--)
		Delay1ms(); 
} 