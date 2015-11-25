/*
 * Dht11.h
 *
 *  Created on: 2014Äê12ÔÂ12ÈÕ
 *      Author: lenovo
 */

#ifndef DHT11_H_
#define DHT11_H_
#define uchar unsigned char
#define uint unsigned int
/******************cpu delay*****************/
#define CPU_F ((double)1000000.0)
#define delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0))
/*********************************************/

#define DCLR         P1DIR&=~BIT5
#define DSET         P1DIR|=BIT5
#define DataPort     P1OUT
#define CLR          P1OUT&=~BIT5
#define SET          P1OUT|=BIT5
extern uchar FLAG;
extern uchar TEMP;
extern uchar T_DATA_H;
extern uchar T_DATA_L;
extern uchar RH_DATA_H;
extern uchar RH_DATA_L;
extern uchar CHECKDATA;
extern uchar T_DATA_H_TEMP;
extern uchar RH_DATA_H_TEMP;
extern uchar T_DATA_L_TEMP;
extern uchar RH_DATA_L_TEMP;
extern uchar str[];
#define ensureh      P1IN&BIT5
void readdht11();
uchar COM();
void delay_20ms();
void delay_30us();
void delay_40us();
/*
 * main.c
 */

#endif /* DHT11_H_ */
