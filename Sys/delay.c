#include "delay.h"
#include "intrins.h"

//���������ȴ����� 
//���룺��ʱ����ֵ��2���ֽڣ�16λ
//�������
//�������ܣ��ȴ�

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