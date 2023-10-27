/*
 * LCD_private.c
 *
 * Created: 10/26/2023 11:34:36 AM
 *  Author: Sarah saeed
 */ 
#include "LCD_interface.h"
#include "../BIT_MATH.h"
#include "util/delay.h"
const u8 data_pins[]={B4,B2,B1,B0};
void H_LCD_void_Init(void)
{
	EN_DIR(1);
	RS_DIR(1);
	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,EN,1);
	for (int i=0;i<4;i++)
	{
		DIO_voidSetPinDirection(PERIPHERAL_B_BASE,data_pins[i],1);	
	}
	_delay_ms(50);
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,RS,0);
	H_LCD_void_sendCommand(0x22);
	H_LCD_void_sendCommand(0x02);
	H_LCD_void_sendCommand(0x08);
	_delay_ms(1);
	H_LCD_void_sendCommand(0x00);
	H_LCD_void_sendCommand(0x0C);//display on off 0E
	_delay_ms(1);
	H_LCD_void_sendCommand(0x00);
	H_LCD_void_sendCommand(0x01);
	_delay_ms(3);
	H_LCD_void_sendCommand(0x00);
	H_LCD_void_sendCommand(0x06);

}
void H_LCD_void_sendData(u8 copy_u8data )
{
	//put RS(1)
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,RS,1);
	H_LCD_void_latchByte(copy_u8data);
	_delay_ms(1);
	
}
void H_LCD_void_sendCommand(u8 copy_u8command)
{
	//put RS(0)
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,RS,0);
	H_LCD_void_latchByte(copy_u8command);
	_delay_ms(1);
	
}

static void H_LCD_void_latchByte(u8 copy_u8Byte)
{
	int p=7;
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<4;j++)
		{
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,data_pins[j],READBIT(copy_u8Byte,p));
			p--;
		}
		DIO_voidSetPinValue(PERIPHERAL_A_BASE,EN,1);
		_delay_ms(1);
		DIO_voidSetPinValue(PERIPHERAL_A_BASE,EN,0);
		_delay_ms(5);
	}
}

void H_LCD_void_sendString(const s8 * pstr)
{
	int i=0;
	while(pstr[i] != '\0'){
		H_LCD_void_sendData(pstr[i]);
		i++;
	}
	
}
void H_LCD_void_sendIntNum(s32 copy_s32Num)
{
	u8 data ;
	if (copy_s32Num >= 10){
		if (copy_s32Num>=100){
			if(copy_s32Num >= 1000){//%0.2f 4.50 0.5  4.5000
				data = (copy_s32Num/1000)%10;//3555->3
				H_LCD_void_sendData(data + 0x30);// add the number into its ascii
			}
			data = (copy_s32Num/100)%10;
			H_LCD_void_sendData(data + 0x30);
		}
		data = (copy_s32Num/10)%10;//50
		H_LCD_void_sendData(data + 0x30);
	}
	data = copy_s32Num %10;//5
	H_LCD_void_sendData(data+0x30);
}
void LCD_Clear(void)
{
	H_LCD_void_sendCommand(0x01);
	H_LCD_void_sendCommand(0x80);
}



