#ifndef _12864_h
#define _12864_h

#define uchar unsigned char
#define uint unsigned int

/******************cpu delay*****************/
#define CPU_F ((double)1000000)
#define delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0))
/*********************************************/


/*********************************************/

#define SCLK_lcd1  P2OUT |=BIT0          //
#define SCLK_lcd0  P2OUT &=~BIT0
#define SID_lcd1   P2OUT |=BIT1          //
#define SID_lcd0   P2OUT &=~BIT1
#define CS_lcd1    P2OUT |=BIT2          //
#define CS_lcd0    P2OUT &=~BIT2

void Delay_nus(uint num);
void Delay_nms(uint num);
void SInit_12864(void);                                         /*Һ��LCD12864��ʼ��*/
void LCD12864_Clear(void);                                      /*LCD12864 ����*/
void write_12864_byte(uchar R_S,uchar   com);                   /*��LCD12864д��һ��ָ���������*/
void LCD12864_str(uchar   hang,uchar   lie,  uchar  *s) ;       /*��1602��hang�е�lie�п�ʼ��ʾ*s �ַ��� */
void LCD12864_str_ram(uchar   hang,uchar   lie, uchar  *s) ;    /*��1602��hang�е�lie�п�ʼ��ʾ*s �ַ��� */
void LCD12864_Chinese(uchar   hang,uchar   lie, uchar  *s);     /*��1602��hang�е�lie�п�ʼ��ʾ*s ����*/
void LCD12864_Long(uchar   hang,uchar   lie,long   dws);        /*��12864��hang�е�lie�п�ʼ��ʾlong ���� */
void LCD12864_ULong(uchar   hang,uchar   lie,unsigned long   dws);
void LCD12864_Float(uchar   hang,uchar   lie,float   ft);       /*��12864��hang�е�lie�п�ʼ��ʾFloat ���� */
void LCD12864_Float4(uchar   hang,uchar   lie,double   ft);     //// 1-4�У�1-16��
void LCD_12864_P(uchar  *a);                                    //��ʾͼƬ����128*64
void LCD12864_Uint(uchar   hang,uchar   lie,uint   zs);

unsigned int adstart(char k);                                   //ads8341�ĺ���ԭ��
#endif
