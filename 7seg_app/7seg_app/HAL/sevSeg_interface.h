/*
 * _7segement_interface.h
 *
 * Created: 10/25/2023 5:24:25 PM
 *  Author: Sarah saeed
 */ 
#ifndef SEVSEG_INTERFACE_H_
#define SEVSEG_INTERFACE_H_
#include "../MCAL/DIO_interface.h"
#include "sevSeg_config.h"
#include "sevSeg_private.h"
#include "../MCAL/Std_types.h"


void SEVEN_SEG_init(void);
void SEVEN_SEG_write_byte(u8 data);
void SEVEN_SEG_write(u16 data);

#endif /* 7SEGEMENT_INTERFACE_H_ */