/*
 * LM35_interface.h
 *
 * Created: 11/8/2023 10:46:34 AM
 *  Author: Sarah saeed
 */ 


#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_
#include "LM35_private.h"
#include "LM35_config.h"
#include "../../Std_types.h"

#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
u8 LM35_getTemperature(void);


#endif /* LM35_INTERFACE_H_ */