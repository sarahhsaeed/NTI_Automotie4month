/*
 * LCD_config.h
 *
 * Created: 10/26/2023 11:35:05 AM
 *  Author: Sarah saeed
 */ 
#include "../MCAL/DIO_private.h"

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define RS_DIR(x) if (x==0) DIO_voidSetPinDirection(PERIPHERAL_A_BASE,RS,0);else DIO_voidSetPinDirection(PERIPHERAL_A_BASE,RS,1);
#define EN_DIR(x) if (x==0)	DIO_voidSetPinDirection(PERIPHERAL_A_BASE,EN,0);else DIO_voidSetPinDirection(PERIPHERAL_A_BASE,EN,1);

#define RS  3
#define EN  2
#define B0  0
#define B1  1
#define B2  2
#define B4  4
void H_LCD_void_Init(void);
void H_LCD_void_sendData(u8 copy_u8data );
void H_LCD_void_sendCommand(u8 copy_u8command);
static void H_LCD_void_latchByte(u8 copy_u8Byte);


#endif /* LCD_CONFIG_H_ */