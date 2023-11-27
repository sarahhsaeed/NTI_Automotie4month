/*
 * DIO_interface.h
 *
 * Created: 10/25/2023 4:07:02 PM
 *  Author: Sarah saeed
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "DIO_private.h"
typedef enum
{
	PIN_0  ,
	PIN_1  ,
	PIN_2  ,
	PIN_3  ,
	PIN_4  ,
	PIN_5  ,
	PIN_6  ,
	PIN_7
}PIN_t;

typedef enum
{
	INPUT  ,
	OUTPUT
}DIRECTION_t;


typedef enum
{
	LOW   ,
	HIGH
}VALUE_t;

void DIO_voidSetPinDirection( GPIO_peripherals *ptr, u8 Copy_u8PinId, u8 Copy_u8Direction);
void DIO_voidSetPinValue(GPIO_peripherals *ptr, u8 Copy_u8PinId, u8 Copy_u8Value);
u8 DIO_voidGetPinValue(GPIO_peripherals *ptr, u8 Copy_u8PinId);
void DIO_voidSetPortirection(GPIO_peripherals *ptr, u8 Copy_u8Direction);
void DIO_voidSetPortValue(GPIO_peripherals *ptr, u8 Copy_u8Value);
u8 DIO_voidGetportValue(GPIO_peripherals *ptr);

#endif /* DIO_INTERFACE_H_ */