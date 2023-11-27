/*
 * LCD_interface.h
 *
 * Created: 10/26/2023 11:35:17 AM
 *  Author: Sarah saeed
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include "../../Std_types.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../BIT_MATH.h"

#define SHIFT_LEFT            0x18
#define SHIFT_RIGHT			  0x1C
#define MOVE_CURSOR_LEFT	  0x10
#define MOVE_CURSOR_RIGHT	  0x14
#define CLEAR_DISPLAY		  0x01
#define CURSOR_ON			  0x0E
#define CURSOR_OFF			  0x0C
#define NEXT_LINE			  0xC0
#define OVER_WRITE			  0x80


void H_LCD_void_Init(void);void H_LCD_void_sendData(u8 copy_u8data );
void H_LCD_void_sendCommand(u8 copy_u8command);static void H_LCD_void_latchByte(u8 copy_u8Byte);void H_LCD_void_sendString(const s8 * pstr);
void H_LCD_void_sendIntNum(s32 copy_s32Num);
void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col);
void H_LCD_void_creatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode);
void H_LCD_void_displayCustomChar(u8 loc);
#endif /* LCD_INTERFACE_H_ */
