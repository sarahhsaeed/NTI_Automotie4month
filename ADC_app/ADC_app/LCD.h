/*
 * LCD.h
 *
 * Created: 10/23/2023 10:19:10 AM
 *  Author: Sarah saeed
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "Std_types.h"
#include "DIO_private.h"
#define SETBIT(REG,BIT) (REG |= 1<<BIT)
#define CLRBIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^= 1<<BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)
#define LCD_MODE _4_BIT_MODE
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



#endif /* LCD_H_ */