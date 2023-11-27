/*
 * LoginSys.h
 *
 * Created: 11/9/2023 1:06:01 PM
 *  Author: Sarah saeed
 */ 


#ifndef LOGINSYS_H_
#define LOGINSYS_H_
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/GIE/GIE_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "../../MCAL/TIMER0/Timer0_interface.h"
#include "../LCD/LCD_interface.h"
#include "../KEYPAD/Keypad_interface.h"
#include "../RELAY/Relay_interface.h"
#include "../ULTRASONIC/UltraSonic_interface.h"
#define RELAY_CLOSE DIO_voidSetPinValue(PERIPHERAL_A_BASE,6,1);
#define RELAY_OPEN  DIO_voidSetPinValue(PERIPHERAL_A_BASE,6,0);

#define LED_RED_ON      DIO_voidSetPinValue(PERIPHERAL_A_BASE,7,1);
#define LED_RED_OFF     DIO_voidSetPinValue(PERIPHERAL_A_BASE,7,0);

#define LED_BLUE_ON      DIO_voidSetPinValue(PERIPHERAL_A_BASE,5,1);
#define LED_BLUE_OFF     DIO_voidSetPinValue(PERIPHERAL_A_BASE,5,0);

#define LED_GREEN_ON      DIO_voidSetPinValue(PERIPHERAL_A_BASE,4,1);
#define LED_GREEN_OFF     DIO_voidSetPinValue(PERIPHERAL_A_BASE,4,0);

#define TWO_MINUTES 120000
#define MAX_NUMBER_OF_TRY 3
#define PASSWORD_SIZE 4

void timer_callback(void);


#endif /* LOGINSYS_H_ */