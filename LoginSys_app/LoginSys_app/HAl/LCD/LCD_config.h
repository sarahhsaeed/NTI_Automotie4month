/*
 * LCD_config.h
 *
 * Created: 10/26/2023 11:35:05 AM
 *  Author: Sarah saeed
 */ 
#include "../../MCAL/DIO/DIO_private.h"

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define RS_DIR(x) if (x==0) DIO_voidSetPinDirection(PERIPHERAL_C_BASE,RS,0);else DIO_voidSetPinDirection(PERIPHERAL_C_BASE,RS,1);
#define EN_DIR(x) if (x==0)	DIO_voidSetPinDirection(PERIPHERAL_C_BASE,EN,0);else DIO_voidSetPinDirection(PERIPHERAL_C_BASE,EN,1);

#define RS  0
#define EN  1
#define D4  4
#define D5  5
#define D6  6
#define D7  7


#endif /* LCD_CONFIG_H_ */