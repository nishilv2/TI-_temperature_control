/*
 * L298N.c
 *
 *  Created on: 2014Äê12ÔÂ26ÈÕ
 *      Author: lenovo
 */
#include "L298N.h"
#include <msp430g2553.h>
#ifndef L298N_C_
#define L298N_C_
uint i,j,k;

uchar  single_pos[4]={0x07,0x0b,0x0d,0x0e};
uchar  single_rev[4]={0x0e,0x0d,0x0b,0x07};
uchar  double_pos[4]={0x06,0x03,0x09,0x0c};
uchar  double_rev[4]={0x0c,0x09,0x03,0x06};
uchar  eight_pos[8]={0x06,0x07,0x03,0x0b,0x09,0x0d,0x0c,0x0e};
uchar  eight_rev[8]={0x0e,0x0c,0x0d,0x09,0x0b,0x03,0x07,0x06};

void delay_200ms()
{
	uint i1,j1;

	for(j1=0;j1<220;j1++)
	{
		for(i1 = 220;i1 > 0;i1--)  _NOP();
	}

}
void delay_2ms()
{
	unsigned char i2,j2;

	for(j2=0;j2<34;j2++)
	{
		for(i2 = 13;i2 > 0;i2--)  _NOP();
	}

}
void delay_5ms()
{
	unsigned char i3,j3;

	for(j3=0;j3<34;j3++)
	{
		for(i3 = 35;i3 > 0;i3--)  _NOP();
	}

}
void delay_8ms()
{
	unsigned char i4,j4;

	for(j4=0;j4<34;j4++)
	{
		for(i4 = 57;i4 > 0;i4--)  _NOP();
	}

}
void m_single_pos()
{
	for(k=0;k<128;k++)
	{
		j=0;
		for(i=0;i<4;i++)
		{
			DATA|=single_pos[j];
			delay_8ms();
			DATA&=~single_pos[j];
			j++;
		}
	}
}
void m_single_rev()
{
	for(k=0;k<128;k++)
	{
		j=0;
		for(i=0;i<4;i++)
		{
			DATA|=single_rev[j];
			delay_5ms();
			DATA&=~single_rev[j];
			j++;
		}
	}
}
void m_double_pos()
{
	for(k=0;k<128;k++)
	{
		j=0;
		for(i=0;i<4;i++)
		{
			DATA|=double_pos[j];
			delay_8ms();
			DATA&=~double_pos[j];
			j++;
		}
	}
}
void m_double_rev()
{
	for(k=0;k<128;k++)
	{
		j=0;
		for(i=0;i<4;i++)
		{
			DATA|=double_rev[j];
			delay_8ms();
			DATA&=~double_rev[j];
			j++;
		}
	}
}
void m_eight_pos()
{
	for(k=0;k<128;k++)
	{
		j=0;
		for(i=0;i<8;i++)
		{
			DATA|=eight_pos[j];
			delay_2ms();
			DATA&=~eight_pos[j];
			j++;
		}
	}
}
void m_eight_rev()
{
	for(k=0;k<128;k++)
	{
		j=0;
		for(i=0;i<8;i++)
		{
			DATA|=eight_rev[j];
			delay_2ms();
			DATA&=~eight_rev[j];
			j++;
		}
	}
}


#endif /* L298N_C_ */
