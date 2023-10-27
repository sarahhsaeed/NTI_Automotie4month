/*
 * LCD.c
 *
 * Created: 10/23/2023 10:18:56 AM
 *  Author: Sarah saeed
 */ 
#include "LCD.h"
#include "util/delay.h"
extern volatile GPIO_peripherals*PeripheralD;
extern volatile GPIO_peripherals*PeripheralC;
extern volatile GPIO_peripherals*PeripheralB;
extern volatile GPIO_peripherals*PeripheralA;
u8 LCD_pins[4]={B4,B2,B1,B0};

void H_LCD_void_Init(void)
{
		DIO_voidSetPinDirection(PeripheralA,RS,1);
		DIO_voidSetPinDirection(PeripheralA,EN,1);
		DIO_voidSetPinDirection(PeripheralB,B0,1);
		DIO_voidSetPinDirection(PeripheralB,B1,1);
		DIO_voidSetPinDirection(PeripheralB,B2,1);
		DIO_voidSetPinDirection(PeripheralB,B4,1);
		
		_delay_ms(50);
		DIO_voidSetPinValue(PeripheralA,RS,0);
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
	DIO_voidSetPinValue(PeripheralA,RS,1);
	H_LCD_void_latchByte(copy_u8data);
	_delay_ms(1);
	
}
void H_LCD_void_sendCommand(u8 copy_u8command)
{
	//put RS(0)
	DIO_voidSetPinValue(PeripheralA,RS,0);
	H_LCD_void_latchByte(copy_u8command);
	_delay_ms(1);
	
}

static void H_LCD_void_latchByte(u8 copy_u8Byte)
{
	DIO_voidSetPinValue(PeripheralB,B4,READBIT(copy_u8Byte,7));
	DIO_voidSetPinValue(PeripheralB,B2,READBIT(copy_u8Byte,6));
	DIO_voidSetPinValue(PeripheralB,B1,READBIT(copy_u8Byte,5));
	DIO_voidSetPinValue(PeripheralB,B0,READBIT(copy_u8Byte,4));
	DIO_voidSetPinValue(PeripheralA,EN,1);
	_delay_ms(1);
	DIO_voidSetPinValue(PeripheralA,EN,0);
	_delay_ms(5);
	
	DIO_voidSetPinValue(PeripheralB,B4,READBIT(copy_u8Byte,3));
	DIO_voidSetPinValue(PeripheralB,B2,READBIT(copy_u8Byte,2));
	DIO_voidSetPinValue(PeripheralB,B1,READBIT(copy_u8Byte,1));
	DIO_voidSetPinValue(PeripheralB,B0,READBIT(copy_u8Byte,0));
	DIO_voidSetPinValue(PeripheralA,EN,1);
	_delay_ms(1);
	DIO_voidSetPinValue(PeripheralA,EN,0);
	_delay_ms(5);
}

/*
static void H_LCD_void_latchByte(u8 copy_u8Byte)
{
	int p=7;
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<4;j++)
		{
			DIO_voidSetPinValue(PeripheralB,LCD_pins[j],READBIT(copy_u8Byte,p));
			p--;
		}
		DIO_voidSetPinValue(PeripheralA,EN,1);
		_delay_ms(1);
		DIO_voidSetPinValue(PeripheralA,EN,0);
		_delay_ms(1);
	}
}
*/
void LCD_write_string(u8 *data){
	uint8_t i =0;
	while(data[i] != '\0'){
		H_LCD_void_sendData(data[i]);
		i++;
	}
}




/*
int p=7;
for (int i=0;i<2;i++)
{
	for (int j=0;j<4;j++)
	{
		DIO_voidSetPinValue(PeripheralB,LCD_pins[j],READBIT(copy_u8Byte,p));
		p--;
	}
	DIO_voidSetPinValue(PeripheralA,EN,1);
	_delay_ms(1);
	DIO_voidSetPinValue(PeripheralA,EN,0);
	_delay_ms(5);
}

*/