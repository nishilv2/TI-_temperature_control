/*ool
 * DHT11.c
 *
 *  Created on: 2014Äê12ÔÂ17ÈÕ
 *      Author: lenovo
 */
#include "DHT11.h"
#include <msp430g2553.h>
#include <math.h>
#ifndef DHT11_C_
#define DHT11_C_
 uchar FLAG;
 uchar TEMP;
 uchar T_DATA_H=0;
 uchar T_DATA_L=0;
 uchar RH_DATA_H=0;
 uchar RH_DATA_L=0;
 uchar CHECKDATA;
 uchar T_DATA_H_TEMP;
 uchar RH_DATA_H_TEMP;
 uchar T_DATA_L_TEMP;
 uchar RH_DATA_L_TEMP;
 uchar str[5];
void delay_20ms()
{
	unsigned char i,j;

	for(j=0;j<34;j++)
	{
		for(i = 150;i > 0;i--)  _NOP();
	}

}
void delay_30us()
{
	unsigned char i,j=0;
    for(i=0;i<2;i++)
    {
    	_NOP();_NOP();
    }
    _NOP();
}
void delay_40us()
{
	unsigned char i,j=0;
    for(i=0;i<3;i++)
    {
    	_NOP();
    }
    _NOP();
    _NOP();
    _NOP();
    _NOP();

}

uchar COM()
{
	uchar i,comdata;
	for(i=0;i<8;i++)
	{
		FLAG=2;
		while((!(P1IN&BIT5))&&FLAG++);
        delay_40us();
		TEMP=0;
		if(P1IN&BIT5)
		{
			TEMP=1;
		}
		FLAG=2;
		while((P1IN&BIT5)&&FLAG++);
		if(FLAG==1)
		{
			return 255;
		}
		comdata<<=1;
		comdata|=TEMP;

	}
	return comdata;
}
void readdht11()
{
	uchar TEMP;
	DSET;
	CLR;
	delay_20ms();
	SET;
	delay_40us();
    SET;
	DCLR;
	if(!(P1IN&BIT5));
	{
		FLAG=2;
		while((!(P1IN&BIT5))&&FLAG++);
		FLAG=2;
		while((P1IN&BIT5)&&FLAG++);
		RH_DATA_H_TEMP=COM();
		RH_DATA_L_TEMP=COM();
		T_DATA_H_TEMP=COM();
		T_DATA_L_TEMP=COM();
		CHECKDATA=COM();

		TEMP=(T_DATA_H_TEMP+T_DATA_L_TEMP+RH_DATA_H_TEMP+RH_DATA_L_TEMP);
		if(TEMP==CHECKDATA)
		{
			RH_DATA_H=RH_DATA_H_TEMP;
			RH_DATA_L=RH_DATA_L_TEMP;
			T_DATA_H=T_DATA_H_TEMP;
			T_DATA_L=T_DATA_L_TEMP;

		}

	}
}




#endif /* DHT11_C_ */
