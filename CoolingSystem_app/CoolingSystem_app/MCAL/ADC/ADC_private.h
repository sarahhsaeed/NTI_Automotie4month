/*
 * ADC_private.h
 *
 * Created: 10/27/2023 9:10:11 PM
 *  Author: Sarah saeed
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
#include "MemMap.h"
#define ADMUX (*(volatile unsigned char*) 0x27)

#define REFS1  7
#define REFS0  6
#define ADLAR  5

#define ADCSRA (*(volatile unsigned char*) 0x26)
#define ADEN  7
#define ADSC  6
#define ADATE  5
#define ADIF  4
#define ADIE  3
#define ADPS2  2
#define ADPS1  1
#define ADPS0  0

/*
#define SFIOR (*(volatile unsigned char*) 0x26)
#define ADTS2  7
#define ADTS1  6
#define ADTS0  5*/

#define ADCL (*(volatile unsigned char*) 0x24)
#define ADCH (*(volatile unsigned char*) 0x25)
#define ADC (*(volatile unsigned short*)0x24)
/*
#define ADC7  7
#define ADC6  6
#define ADC5  5
#define ADC4  4
#define ADC3  3
#define ADC2  2
#define ADC1  1
#define ADC0  0
#define ADC9  1
#define ADC8  0*/



#endif /* ADC_PRIVATE_H_ */