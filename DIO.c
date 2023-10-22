/*
 * DIO.c
 *
 * Created: 10/21/2023 10:21:09 AM
 *  Author: Sarah saeed
 */ 
#include "DIO_private.h"


void DIO_voidSetPinDirection( GPIO_peripherals *ptr, u8 Copy_u8PinId, u8 Copy_u8Direction){

	switch (Copy_u8PinId){
		case 0:
		ptr->DDR.Bit.B0 = Copy_u8Direction;
		break;
		case 1:
		ptr->DDR.Bit.B1 = Copy_u8Direction;
		break;
		case 2:
		ptr->DDR.Bit.B2 = Copy_u8Direction;
		break;
		case 3:
		ptr->DDR.Bit.B3 = Copy_u8Direction;
		break;
		case 4:
		ptr->DDR.Bit.B4 = Copy_u8Direction;
		break;
		case 5:
		ptr->DDR.Bit.B5 = Copy_u8Direction;
		break;
		case 6:
		ptr->DDR.Bit.B6= Copy_u8Direction;
		break;
		case 7:
		ptr->DDR.Bit.B7 = Copy_u8Direction;
		break;
		default:
		break;
	}
}
void DIO_voidSetPinValue(GPIO_peripherals *ptr, u8 Copy_u8PinId, u8 Copy_u8Value){
	switch (Copy_u8PinId){
		case 0:
		ptr->PORT.Bit.B0 = Copy_u8Value;
		break;
		case 1:
		ptr->PORT.Bit.B1 = Copy_u8Value;
		break;
		case 2:
		ptr->PORT.Bit.B2 = Copy_u8Value;
		break;
		case 3:
		ptr->PORT.Bit.B3 = Copy_u8Value;
		break;
		case 4:
		ptr->PORT.Bit.B4 = Copy_u8Value;
		break;
		case 5:
		ptr->PORT.Bit.B5 = Copy_u8Value;
		break;
		case 6:
		ptr->PORT.Bit.B6 = Copy_u8Value;
		break;
		case 7:
		ptr->PORT.Bit.B7 = Copy_u8Value;
		break;
		default:
		break;
	}

}
u8 DIO_voidGetPinValue(GPIO_peripherals *ptr, u8 Copy_u8PinId){

	u8 pin_val;

	switch (Copy_u8PinId){
		case 0:
		pin_val= ptr->PIN.Bit.B0 ;
		break;
		case 1:
		pin_val= ptr->PIN.Bit.B1;
		break;
		case 2:
		pin_val= ptr->PIN.Bit.B2;
		break;
		case 3:
		pin_val= ptr->PIN.Bit.B3;
		break;
		case 4:
		pin_val= ptr->PIN.Bit.B4;
		break;
		case 5:
		pin_val= ptr->PIN.Bit.B5;
		break;
		case 6:
		pin_val= ptr->PIN.Bit.B6;
		break;
		case 7:
		pin_val=ptr->PIN.Bit.B7;
		break;
		default:
		break;
	}
	return pin_val;
}
void DIO_voidSetPortirection(GPIO_peripherals *ptr, u8 Copy_u8Direction){
	ptr->DDR.value =  Copy_u8Direction;
}
void DIO_voidSetPortValue(GPIO_peripherals *ptr, u8 Copy_u8Value){

	ptr->PORT.value =  Copy_u8Value;


}
/*
u8 DIO_voidGetportValue(GPIO_peripherals *ptr){

	u8 port_val;
	port_val= ptr->PORT.value;
	return port_val;
}
*/
