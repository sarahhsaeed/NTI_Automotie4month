/*
 * SEVEN_SEG.c
 *
 * Created: 8/13/2022 12:52:50 PM
 *  Author: safifi
 */ 
#include "SEVEN_SEG.h"
#include "util/delay.h"
extern volatile GPIO_peripherals*PeripheralD;
extern volatile GPIO_peripherals*PeripheralC;
extern volatile GPIO_peripherals*PeripheralB;
extern volatile GPIO_peripherals*PeripheralA;
void SEVEN_SEG_init(void){
	 PeripheralB->DDR.Bit.B0=1;
	 PeripheralB->DDR.Bit.B1=1;
	 PeripheralB->DDR.Bit.B2=1;
	 PeripheralB->DDR.Bit.B4=1;
	 
	 PeripheralB->DDR.Bit.B5=1;
	 PeripheralB->DDR.Bit.B6=1;
	 PeripheralA->DDR.Bit.B3=1;
	 PeripheralA->DDR.Bit.B2=1;
	 
	 PeripheralB->PORT.Bit.B5=1;
	 PeripheralB->PORT.Bit.B6=0;
	 PeripheralA->PORT.Bit.B3=1;
	 PeripheralA->PORT.Bit.B2=1;
	 
}
void SEVEN_SEG_one_number(u8 data){ // 0 to 9
	switch(data)
	{
		case 0:
		{
			PeripheralB->PORT.Bit.B0=0;
			PeripheralB->PORT.Bit.B1=0;
			PeripheralB->PORT.Bit.B2=0;
			PeripheralB->PORT.Bit.B4=0;
			break;
		}
		case 1:
		{
			
			PeripheralB->PORT.Bit.B0=1;
			PeripheralB->PORT.Bit.B1=0;
			PeripheralB->PORT.Bit.B2=0;
			PeripheralB->PORT.Bit.B4=0;
			break;
		}
		case 2:
		{
			PeripheralB->PORT.Bit.B0=0;
			PeripheralB->PORT.Bit.B1=1;
			PeripheralB->PORT.Bit.B2=0;
			PeripheralB->PORT.Bit.B4=0;
			break;
		}
		case 3:
		{
			PeripheralB->PORT.Bit.B0=1;
			PeripheralB->PORT.Bit.B1=1;
			PeripheralB->PORT.Bit.B2=0;
			PeripheralB->PORT.Bit.B4=0;
			break;
		}
		case 4:
		{
			PeripheralB->PORT.Bit.B0=0;
			PeripheralB->PORT.Bit.B1=0;
			PeripheralB->PORT.Bit.B2=1;
			PeripheralB->PORT.Bit.B4=0;
			break;
		}
		case 5:
		{
			PeripheralB->PORT.Bit.B0=1;
			PeripheralB->PORT.Bit.B1=0;
			PeripheralB->PORT.Bit.B2=1;
			PeripheralB->PORT.Bit.B4=0;
			break;
		}
		case 6:
		{
			PeripheralB->PORT.Bit.B0=0;
			PeripheralB->PORT.Bit.B1=1;
			PeripheralB->PORT.Bit.B2=1;
			PeripheralB->PORT.Bit.B4=0;
			break;
		}
		case 7:
		{
			PeripheralB->PORT.Bit.B0=1;
			PeripheralB->PORT.Bit.B1=1;
			PeripheralB->PORT.Bit.B2=1;
			PeripheralB->PORT.Bit.B4=0;
			break;
		}
		case 8:
		{
			PeripheralB->PORT.Bit.B0=0;
			PeripheralB->PORT.Bit.B1=0;
			PeripheralB->PORT.Bit.B2=0;
			PeripheralB->PORT.Bit.B4=1;
			break;
		}
		case 9:
		{
			PeripheralB->PORT.Bit.B0=1;
			PeripheralB->PORT.Bit.B1=0;
			PeripheralB->PORT.Bit.B2=0;
			PeripheralB->PORT.Bit.B4=1;
			break;
		}
	}//end of first switch
}

void SEVEN_SEG_two_numbers(u8 data)
{
	u8 rem=data%10;
	data=data/10;
	PeripheralB->PORT.Bit.B6=1;
	PeripheralB->PORT.Bit.B5=0;
	SEVEN_SEG_one_number(rem);
	_delay_ms(10);
	rem=data%10;
	PeripheralB->PORT.Bit.B6=0;
	PeripheralB->PORT.Bit.B5=1;
	SEVEN_SEG_one_number(rem);
	_delay_ms(10);
	
}
void sevseg_4num(u16 num){
	u8 rem;
	rem=num%10;
	num=num/10;
	SEVEN_SEG_one_number(rem);
	_delay_ms(1);
	DIO_voidSetPinValue(PeripheralA,3,1);
	DIO_voidSetPinValue(PeripheralA,2,0);
	rem=num%10;
	num=num/10;
	SEVEN_SEG_one_number(rem);
	_delay_ms(1);
	DIO_voidSetPinValue(PeripheralA,2,1);
	DIO_voidSetPinValue(PeripheralB,5,0);//5
	
	rem=num%10;
	num=num/10;
	SEVEN_SEG_one_number(rem);
	_delay_ms(1);
	DIO_voidSetPinValue(PeripheralB,5,1);
	DIO_voidSetPinValue(PeripheralB,6,0);
	rem=num%10;
	num=num/10;
	SEVEN_SEG_one_number(rem);
	_delay_ms(1);
	DIO_voidSetPinValue(PeripheralB,6,1);
	DIO_voidSetPinValue(PeripheralA,3,0);
	
}



/*
u8 value=data%10;
PeripheralB->PORT.Bit.B0=0;
PeripheralB->PORT.Bit.B1=0;
PeripheralB->PORT.Bit.B2=0;
PeripheralB->PORT.Bit.B4=0;
//////////////////////////////
PeripheralA->PORT.Bit.B3=0;
PeripheralA->PORT.Bit.B2=1;
switch(value)
{
	case 0:
	{
		PeripheralB->PORT.Bit.B0=0;
		PeripheralB->PORT.Bit.B1=0;
		PeripheralB->PORT.Bit.B2=0;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 1:
	{
		
		PeripheralB->PORT.Bit.B0=1;
		PeripheralB->PORT.Bit.B1=0;
		PeripheralB->PORT.Bit.B2=0;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 2:
	{
		PeripheralB->PORT.Bit.B0=0;
		PeripheralB->PORT.Bit.B1=1;
		PeripheralB->PORT.Bit.B2=0;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 3:
	{
		PeripheralB->PORT.Bit.B0=1;
		PeripheralB->PORT.Bit.B1=1;
		PeripheralB->PORT.Bit.B2=0;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 4:
	{
		PeripheralB->PORT.Bit.B0=0;
		PeripheralB->PORT.Bit.B1=0;
		PeripheralB->PORT.Bit.B2=1;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 5:
	{
		PeripheralB->PORT.Bit.B0=1;
		PeripheralB->PORT.Bit.B1=0;
		PeripheralB->PORT.Bit.B2=1;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 6:
	{
		PeripheralB->PORT.Bit.B0=0;
		PeripheralB->PORT.Bit.B1=1;
		PeripheralB->PORT.Bit.B2=1;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 7:
	{
		PeripheralB->PORT.Bit.B0=1;
		PeripheralB->PORT.Bit.B1=1;
		PeripheralB->PORT.Bit.B2=1;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 8:
	{
		PeripheralB->PORT.Bit.B0=0;
		PeripheralB->PORT.Bit.B1=0;
		PeripheralB->PORT.Bit.B2=0;
		PeripheralB->PORT.Bit.B4=1;
		break;
	}
	case 9:
	{
		PeripheralB->PORT.Bit.B0=1;
		PeripheralB->PORT.Bit.B1=0;
		PeripheralB->PORT.Bit.B2=0;
		PeripheralB->PORT.Bit.B4=1;
		break;
	}
}//end of first switch
_delay_ms(10);
value=data/10;
PeripheralA->PORT.Bit.B3=1;
PeripheralA->PORT.Bit.B2=0;
switch(value)
{
	case 0:
	{
		PeripheralB->PORT.Bit.B0=0;
		PeripheralB->PORT.Bit.B1=0;
		PeripheralB->PORT.Bit.B2=0;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 1:
	{
		
		PeripheralB->PORT.Bit.B0=1;
		PeripheralB->PORT.Bit.B1=0;
		PeripheralB->PORT.Bit.B2=0;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 2:
	{
		PeripheralB->PORT.Bit.B0=0;
		PeripheralB->PORT.Bit.B1=1;
		PeripheralB->PORT.Bit.B2=0;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 3:
	{
		PeripheralB->PORT.Bit.B0=1;
		PeripheralB->PORT.Bit.B1=1;
		PeripheralB->PORT.Bit.B2=0;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 4:
	{
		PeripheralB->PORT.Bit.B0=0;
		PeripheralB->PORT.Bit.B1=0;
		PeripheralB->PORT.Bit.B2=1;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 5:
	{
		PeripheralB->PORT.Bit.B0=1;
		PeripheralB->PORT.Bit.B1=0;
		PeripheralB->PORT.Bit.B2=1;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 6:
	{
		PeripheralB->PORT.Bit.B0=0;
		PeripheralB->PORT.Bit.B1=1;
		PeripheralB->PORT.Bit.B2=1;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 7:
	{
		PeripheralB->PORT.Bit.B0=1;
		PeripheralB->PORT.Bit.B1=1;
		PeripheralB->PORT.Bit.B2=1;
		PeripheralB->PORT.Bit.B4=0;
		break;
	}
	case 8:
	{
		PeripheralB->PORT.Bit.B0=0;
		PeripheralB->PORT.Bit.B1=0;
		PeripheralB->PORT.Bit.B2=0;
		PeripheralB->PORT.Bit.B4=1;
		break;
	}
	case 9:
	{
		PeripheralB->PORT.Bit.B0=1;
		PeripheralB->PORT.Bit.B1=0;
		PeripheralB->PORT.Bit.B2=0;
		PeripheralB->PORT.Bit.B4=1;
		break;
	}
}


*/