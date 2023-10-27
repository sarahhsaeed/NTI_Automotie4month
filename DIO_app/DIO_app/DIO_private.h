/*
 * DIO.h
 *
 * Created: 10/21/2023 10:21:30 AM
 *  Author: Sarah saeed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "Std_types.h"
#define PERIPHERAL_D_BASE (GPIO_peripherals*)0x30
#define PERIPHERAL_C_BASE (GPIO_peripherals*)0x33
#define PERIPHERAL_B_BASE (GPIO_peripherals*)0x36
#define PERIPHERAL_A_BASE (GPIO_peripherals*)0x39
typedef union
{
	volatile u8 value;
	struct
	{
		volatile u8 B0 : 1;
		volatile u8 B1 : 1;
		volatile u8 B2 : 1;
		volatile u8 B3 : 1;
		volatile u8 B4 : 1;
		volatile u8 B5 : 1;
		volatile u8 B6 : 1;
		volatile u8 B7 : 1;

	}Bit;
}Reg;


typedef struct
{
	volatile Reg PIN	;
	volatile Reg DDR	;
	volatile Reg PORT	;
}GPIO_peripherals;

#endif /* DIO_H_ */