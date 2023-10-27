/*
 * LCD_interface.h
 *
 * Created: 10/26/2023 11:35:17 AM
 *  Author: Sarah saeed
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include "../Std_types.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "../MCAL/DIO_interface.h"
#include "../BIT_MATH.h"

void H_LCD_void_Init(void);
void H_LCD_void_sendCommand(u8 copy_u8command);
void H_LCD_void_sendIntNum(s32 copy_s32Num);
void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col);
void H_LCD_void_creatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode);
void H_LCD_void_displayCustomChar(u8 copy_u8charCode);
#endif /* LCD_INTERFACE_H_ */