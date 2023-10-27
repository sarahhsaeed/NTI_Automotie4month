/*
 * sevSeg_prog.c
 *
 * Created: 10/25/2023 10:22:44 PM
 *  Author: Sarah saeed
 */ 
#include "sevSeg_interface.h"
#include "util/delay.h"
void SEVEN_SEG_init(void)
{
	DIO_voidSetPinDirection(PERIPHERAL_B_BASE,B6,1);
	DIO_voidSetPinDirection(PERIPHERAL_B_BASE,B5,1);
	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,A2,1);
	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,A3,1);
	DIO_voidSetPinValue(PERIPHERAL_B_BASE,B6,1);
	DIO_voidSetPinValue(PERIPHERAL_B_BASE,B5,1);
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,A2,1);
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,A3,1);
	//direction of portB
	DIO_voidSetPinDirection(PERIPHERAL_B_BASE,B0,1);
	DIO_voidSetPinDirection(PERIPHERAL_B_BASE,B1,1);
	DIO_voidSetPinDirection(PERIPHERAL_B_BASE,B2,1);
	DIO_voidSetPinDirection(PERIPHERAL_B_BASE,B4,1);
}
void SEVEN_SEG_write_byte(u8 data)
{
	switch(data)
	{
		case 0:
		{
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B0,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B1,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B2,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B4,0);
			break;
		}
		case 1:
		{
			
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B0,1);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B1,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B2,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B4,0);
			break;
		}
		case 2:
		{
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B0,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B1,1);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B2,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B4,0);
			break;
		}
		case 3:
		{
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B0,1);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B1,1);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B2,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B4,0);
			break;
		}
		case 4:
		{
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B0,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B1,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B2,1);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B4,0);
			break;
		}
		case 5:
		{
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B0,1);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B1,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B2,1);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B4,0);
			break;
		}
		case 6:
		{
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B0,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B1,1);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B2,1);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B4,0);
			break;
		}
		case 7:
		{
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B0,1);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B1,1);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B2,1);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B4,0);
			break;
		}
		case 8:
		{
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B0,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B1,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B2,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B4,1);
			break;
		}
		case 9:
		{
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B0,1);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B1,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B2,0);
			DIO_voidSetPinValue(PERIPHERAL_B_BASE,B4,1);
			break;
		}
	}
}

void SEVEN_SEG_write(u16 num){
	u8 rem;
	rem=(num/1000)%10;
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,A3,1);
	DIO_voidSetPinValue(PERIPHERAL_B_BASE,B6,0);
	SEVEN_SEG_write_byte(rem);
	_delay_ms(7);
	rem=(num/100)%10;
	DIO_voidSetPinValue(PERIPHERAL_B_BASE,B6,1);
	DIO_voidSetPinValue(PERIPHERAL_B_BASE,B5,0);//5
	SEVEN_SEG_write_byte(rem);
	_delay_ms(7);
	rem=(num/10)%10;
	DIO_voidSetPinValue(PERIPHERAL_B_BASE,B5,1);
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,A2,0);
	SEVEN_SEG_write_byte(rem);
	_delay_ms(7);
	rem=(num/1)%10;
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,A2,1);
	DIO_voidSetPinValue(PERIPHERAL_A_BASE,A3,0);
	SEVEN_SEG_write_byte(rem);
	_delay_ms(7);
}
