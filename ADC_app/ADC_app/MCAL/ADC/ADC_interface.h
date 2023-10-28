	/*
 * ADC.h
 *
 * Created: 10/24/2023 9:51:58 AM
 *  Author: Sarah saeed
 */ 
#ifndef ADC_H_
#define ADC_H_
#include "../../Std_types.h"
#include "avr/io.h"
#include "../../BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_Init(void);
u16 ADC_getDigitalValueSynchNonBlocking(void);
u16 ADC_getDigitalValueAsynchCallBack(void);


#endif /* ADC_H_ */