/*
 * DIO.h
 *
 * Created: 10/21/2023 10:21:30 AM
 *  Author: Sarah saeed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "Std_types.h"


typedef union
{
	u8 value;
	struct
	{
		u8 B0 : 1;
		u8 B1 : 1;
		u8 B2 : 1;
		u8 B3 : 1;
		u8 B4 : 1;
		u8 B5 : 1;
		u8 B6 : 1;
		u8 B7 : 1;

	}Bit;
}Reg;


typedef struct
{
	 Reg PIN	;
	 Reg DDR	;
	 Reg PORT	;
}GPIO_peripherals;

#endif /* DIO_H_ */