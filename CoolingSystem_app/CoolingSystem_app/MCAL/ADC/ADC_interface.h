	/*
 * ADC.h
 *
 * Created: 10/24/2023 9:51:58 AM
 *  Author: Sarah saeed
 */ 
#ifndef ADC_H_
#define ADC_H_
#include "../../Std_types.h"
#include "../../BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_config.h"
#define ADC_REF_VOLT_VALUE  5
#define ADC_MAXIMUM_VALUE   1023

typedef enum
{
	AREF=0,AVCC=1,INTERNAL=3
}voltage_ref;
typedef enum
{
	ADJ_RIGHT,ADJ_LEFT
}Adjusmet;
typedef enum
{
	ADC_PRESCALER_2=1,
	ADC_PRESCALER_4,
	ADC_PRESCALER_8,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32,
	ADC_PRESCALER_64,
	ADC_PRESCALER_128=7
}ADC_Prescaler;
typedef enum
{
	AUTO_TRIGGER_DISABLE,AUTO_TRIGGER_ENABLE
}ADC_AutoTrigger;
typedef enum
{
	ADC_DISABLE,ADC_ENABLE
}ADC_EN;
typedef enum
{
	ADC_CHANNEL0,
	ADC_CHANNEL1,
	ADC_CHANNEL2,
	ADC_CHANNEL3,
	ADC_CHANNEL4,
	ADC_CHANNEL5,
	ADC_CHANNEL6,
	ADC_CHANNEL7
}ADC_CHANNEL;

typedef struct
{
	voltage_ref vref;
	Adjusmet adj;
	ADC_Prescaler prescaler;
	ADC_AutoTrigger auto_trig_en;
	ADC_EN adc_en;
	ADC_CHANNEL adc_channel;
}init_adc_struct;

void ADC_Init(init_adc_struct *input);
u16 ADC_getDigitalValueSynchNonBlocking(void);
u16 ADC_getReadNoBlock(init_adc_struct *input);
void ADC_getDigitalValueAsynchCallBack(void(*ptr_to_fn)(void),ADC_CHANNEL adc_ch);


#endif /* ADC_H_ */