/*
 * UltraSonic_interface.h
 *
 * Created: 11/9/2023 1:11:06 PM
 *  Author: Sarah saeed
 */ 


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_
#include "UltraSonic_config.h"
#include "UltraSonic_private.h"
#include "../../Std_types.h"

void Ultrasonic_init(void);
void increment_overflow(void);
u32 timer1_init_input_capture_usec(void);
u32 read_distance(void);




#endif /* ULTRASONIC_INTERFACE_H_ */