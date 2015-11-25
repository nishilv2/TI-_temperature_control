#include "DHT11.h"
#include "12864.h"
#include <msp430g2553.h>
#include <math.h>
#include "L298N.h"
/******************cpu delay*****************/
#define CPU_F ((double)1000000.0)
#define delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0))
/*********************************************/
void main()
{
 	WDTCTL = WDTPW | WDTHOLD;
	P1DIR=BIT5;
    P2DIR=BIT0+BIT1+BIT2+BIT3;
    P2DIR&=~BIT4;

    while(1)
	{
		SInit_12864();

	    LCD12864_Clear();
	    readdht11();
	    str[0]=RH_DATA_H_TEMP;
	    str[1]=RH_DATA_L_TEMP;
	    str[2]=T_DATA_H_TEMP;
	    str[3]=T_DATA_L_TEMP;
	LCD12864_Chinese(1,3,"综合调控");
    LCD12864_Chinese(2,1,"温度  度");
	LCD12864_Chinese(3,1,"湿度  百分比");

	    LCD12864_Long(2,13,str[0]);
	    //LCD12864_Long(2,1,str[1]);
	    LCD12864_Long(3,13,str[2]);
	    //LCD12864_Long(4,1,str[3]);


	    if((str[0]>=50))
	    {
	    	P2OUT|=BIT3;
	    }
	    else
	    {
	    	P2OUT&=~BIT3;
	    }
	    if(P2IN&BIT4)
	    {
	    	LCD12864_Chinese(4,1,"此时光照较弱  ");
	    }
	    else
	    {
	    	LCD12864_Chinese(4,1,"此时光照正常   ");
	    }
	    delay_ms(2000);

	}

}
