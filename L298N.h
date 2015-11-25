/*
 * L298N.h
 *
 *  Created on: 2014Äê12ÔÂ26ÈÕ
 *      Author: lenovo
 */

#ifndef L298N_H_
#define L298N_H_
#define uint unsigned int
#define uchar unsigned char
void delay(uint z);
void m_single_pos();
void m_single_rev();
void m_double_pos();
void m_double_rev();
void m_eight_pos();
void m_eight_rev();
extern uint i,j,k;

extern uchar  single_pos[];
extern uchar  single_rev[];
extern uchar  double_pos[];
extern uchar  double_rev[];
extern uchar  eight_pos[];
extern uchar  eight_rev[];
void delay_200ms();
void delay_2ms();
void delay_5ms();
void delay_8ms();
#define DATA P1OUT

#endif /* L298N_H_ */
