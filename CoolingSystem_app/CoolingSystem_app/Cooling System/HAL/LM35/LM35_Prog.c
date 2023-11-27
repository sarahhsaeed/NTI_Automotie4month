/*
 * LM35_Prog.c
 *
 * Created: 11/8/2023 10:46:18 AM
 *  Author: Sarah saeed
 */ 
#include "LM35_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"
u8 LM35_getTemperature(void)
{
	u8 temp_value = 0;
	u8 adc_value = 0;
	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_read();
	/* Calculate the temperature from the ADC value*/
	temp_value = (u8)(((u32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
	return temp_value;
}