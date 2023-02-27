#include "keyboard.h"

#include "STC15F2K60S2.h"

sbit c1 = P4^4;
sbit c2 = P4^2;
sbit c3 = P3^5;
sbit c4 = P3^4;

/**
 * 读矩阵键盘
 * 按LSB到MSB，按键从左到右，每列从上到下
 */
unsigned int KEYBOARD_Read()
{
	unsigned int result = 0;
	
	// 读第1列
	c2 = c3 = c4 = 1;
	c1 = 0;
	result |= ((P3 & 0xf) << 0);
	// 2
	c1 = 1;
	c2 = 0;
	result |= ((P3 & 0xf) << 4);
	// 3
	c2 = 1;
	c3 = 0;
	result |= ((P3 & 0xf) << 8);
	// 4
	c3 = 1;
	c4 = 0;
	result |= ((P3 & 0xf) << 12);
	
	return result;
}
