/*
 * LCD_private.c
 *
 * Created: 10/26/2023 11:34:36 AM
 *  Author: Sarah saeed
 */ 
#include "LCD_interface.h"
#include "../../BIT_MATH.h"
#include "util/delay.h"
const u8 data_pins[]={D7,D6,D5,D4};
 u8 Character0[] = { 0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00 };
 u8 Character1[] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };
 u8 Character2[] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00 };
 u8 Character3[] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 };
 u8 Character4[] = { 0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18 };
 u8 Character5[] = { 0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04 };
 u8 Character6[] = { 0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00 };
 u8 Character7[] = { 0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 };
void H_LCD_void_Init(void)
{
	EN_DIR(1);
	RS_DIR(1);
	DIO_voidSetPinDirection(PERIPHERAL_C_BASE,EN,1);
	for (int i=0;i<4;i++)
	{
		DIO_voidSetPinDirection(PERIPHERAL_C_BASE,data_pins[i],1);	
	}
	DIO_voidSetPinValue(PERIPHERAL_C_BASE,RS,0);
	H_LCD_void_sendCommand(0x3);
	_delay_ms(4);
	H_LCD_void_sendCommand(0x3);
	_delay_ms(4);
	H_LCD_void_sendCommand(0x3);
	_delay_ms(4);
	
	H_LCD_void_sendCommand(0x2);
	H_LCD_void_sendCommand(0x28);//display on off 0E
	H_LCD_void_sendCommand(0x08);
	H_LCD_void_sendCommand(0x1);
	H_LCD_void_sendCommand(0x6);
	H_LCD_void_sendCommand(0xc);
	_delay_ms(20);

}
void H_LCD_void_sendData(u8 copy_u8data )
{
	//put RS(1)
	DIO_voidSetPinValue(PERIPHERAL_C_BASE,RS,1);
	H_LCD_void_latchByte(copy_u8data);
	_delay_ms(1);
	
}
void H_LCD_void_sendCommand(u8 copy_u8command)
{
	//put RS(0)
	DIO_voidSetPinValue(PERIPHERAL_C_BASE,RS,0);
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
			DIO_voidSetPinValue(PERIPHERAL_C_BASE,data_pins[j],READBIT(copy_u8Byte,p));
			p--;
		}
		DIO_voidSetPinValue(PERIPHERAL_C_BASE,EN,1);
		_delay_ms(1);
		DIO_voidSetPinValue(PERIPHERAL_C_BASE,EN,0);
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
}
void H_LCD_void_gotoXY(u8 row,u8 pos)
{
	switch (row)
	{
		case 1:
		if (pos <16)
		{
			H_LCD_void_sendCommand((pos & 0x0F)|0x80);
		}
		break;
		case 2:
		if (pos <16)
		{
			H_LCD_void_sendCommand((pos & 0x0F)|0xC0);
		}
		break;
		case 3:
		if (pos <16)
		{
			H_LCD_void_sendCommand((0x80|0x14)+pos);
		}
		break;
		case 4:
		if (pos <16)
		{
			H_LCD_void_sendCommand((0x80|0x54)+pos);
		}
		break;
	}
	
	
}
void H_LCD_void_displayCustomChar(u8 loc)
{
	u8 i;

	switch(loc)
	{
		case 0:
		H_LCD_void_sendCommand(0x40 + (loc*8));
		for(i=0;i<8;i++)
		H_LCD_void_sendData(Character0[i]);
		break;
		case 1:
		H_LCD_void_sendCommand(0x40 + (loc*8));
		for(i=0;i<8;i++)
		H_LCD_void_sendData(Character1[i]);
		break;
		
		case 2:
		H_LCD_void_sendCommand(0x40 + (loc*8));
		for(i=0;i<8;i++)
		H_LCD_void_sendData(Character2[i]);
		break;
		
		case 3:
		H_LCD_void_sendCommand(0x40 + (loc*8));
		for(i=0;i<8;i++)
		H_LCD_void_sendData(Character3[i]);
		break;
		
		case 4:
		H_LCD_void_sendCommand(0x40 + (loc*8));
		for(i=0;i<8;i++)
		H_LCD_void_sendData(Character4[i]);
		break;
		
		case 5:
		H_LCD_void_sendCommand(0x40 + (loc*8));
		for(i=0;i<8;i++)
		H_LCD_void_sendData(Character5[i]);
		break;
		
		case 6:
		H_LCD_void_sendCommand(0x40 + (loc*8));
		for(i=0;i<8;i++)
		H_LCD_void_sendData(Character6[i]);
		break;
		
		case 7:
		H_LCD_void_sendCommand(0x40 + (loc*8));
		for(i=0;i<8;i++)
		H_LCD_void_sendData(Character7[i]);
		break;
	}
}


void LCD_intgerToString(u16 data) {
	char buff[16]; /* String to hold the ascii result */
	snprintf(buff,16,"%d",data);/* Use sprintf C function to convert the data to its corresponding ASCII value, 10 for decimal */
	H_LCD_void_sendString(buff); /* Display the string */
}
