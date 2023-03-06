#include "adc.h"

#define DELAY_TIME 5

/** ����I2C����ʱ���ߺ������� */
sbit scl = P2^0;
sbit sda = P2^1;

/**
* @brief I2C������һЩ��Ҫ����ʱ
*
* @param[in] i - ��ʱʱ�����.
* @return none
*/
void i2c_delay(unsigned char i)
{
    do
    {
        _nop_();
    }
    while(i--);        
}

/**
* @brief ����I2C������������.
*
* @param[in] none
* @param[out] none
* @return none
*/
void i2c_start(void)
{
    sda = 1;
    scl = 1;
    i2c_delay(DELAY_TIME);
    sda = 0;
    i2c_delay(DELAY_TIME);
    scl = 0;    
}

/**
* @brief ����I2C����ֹͣ����
*
* @param[in] none
* @param[out] none.
* @return none
*/
void i2c_stop(void)
{
    sda = 0;
    scl = 1;
    i2c_delay(DELAY_TIME);
    sda = 1;
    i2c_delay(DELAY_TIME);   
}

/**
* @brief I2C����һ���ֽڵ�����
*
* @param[in] byt - �����͵��ֽ�
* @return none
*/
void i2c_sendbyte(unsigned char byt)
{
    unsigned char i;
//
	EA = 0;
    for(i=0; i<8; i++){
        scl = 0;
        i2c_delay(DELAY_TIME);
        if(byt & 0x80){
            sda = 1;
        }
        else{
            sda = 0;
        }
        i2c_delay(DELAY_TIME);
        scl = 1;
        byt <<= 1;
        i2c_delay(DELAY_TIME);
    }
	EA = 1;
//
    scl = 0;  
}

/**
* @brief �ȴ�Ӧ��
*
* @param[in] none
* @param[out] none
* @return none
*/
unsigned char i2c_waitack(void)
{
	unsigned char ackbit;
	
    scl = 1;
    i2c_delay(DELAY_TIME);
    ackbit = sda; //while(sda);  //wait ack
    scl = 0;
    i2c_delay(DELAY_TIME);
	
	return ackbit;
}

/**
* @brief I2C����һ���ֽ�����
*
* @param[in] none
* @param[out] da
* @return da - ��I2C�����Ͻ��յ�������
*/
unsigned char i2c_receivebyte(void)
{
	unsigned char da;
	unsigned char i;
	EA = 0;	
	for(i=0;i<8;i++){   
		scl = 1;
		i2c_delay(DELAY_TIME);
		da <<= 1;
		if(sda) 
			da |= 0x01;
		scl = 0;
		i2c_delay(DELAY_TIME);
	}
	EA = 1;
	return da;    
}

/**
* @brief ����Ӧ��
*
* @param[in] ackbit - �趨�Ƿ���Ӧ��
* @return - none
*/
void i2c_sendack(unsigned char ackbit)
{
    scl = 0;
    sda = ackbit;  //0������Ӧ���źţ�1�����ͷ�Ӧ���ź�
    i2c_delay(DELAY_TIME);
    scl = 1;
    i2c_delay(DELAY_TIME);
    scl = 0; 
	sda = 1;
    i2c_delay(DELAY_TIME);
}

/**
* @brief ��д����������һЩ��Ҫ����ʱ
*
* @param[in] i - ָ����ʱʱ��
* @return - none
*/
void operate_delay(unsigned char t)
{
	unsigned char i;
	
	while(t--){
		for(i=0; i<112; i++);
	}
}

/**
* @brief PCF8591��ʼ��
*
* @param[in] none
* @param[out] none
* @return none
*/
void init_pcf8591(void)
{
	i2c_start();
	i2c_sendbyte(0x90);
	i2c_waitack();
	i2c_sendbyte(0x03);  //ADCͨ��3
	i2c_waitack();
	i2c_stop();
	operate_delay(10);
}

/**
* @brief ͨ��I2C���߶�ȡADC���
*
* @param[in] none
* @param[out] temp - ADת�����
* @return - temp
*/
unsigned char adc_pcf8591(void)
{
	unsigned char temp;

	i2c_start();
	i2c_sendbyte(0x91);
	i2c_waitack();
	temp = i2c_receivebyte();
	i2c_sendack(1);
	i2c_stop();
	
	return temp;
}

