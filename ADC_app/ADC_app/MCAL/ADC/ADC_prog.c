/*
 * ADC.c
 *
 * Created: 10/24/2023 9:51:44 AM
 *  Author: Sarah saeed
 */ 
#include "ADC_interface.h"


void ADC_Init(void)
{
	SETBIT(ADMUX,REFS0); // AVCC will be the ref.
	SETBIT(ADCSRA,ADEN); // enable ADC
	SETBIT(ADCSRA,ADPS0);
	SETBIT(ADCSRA,ADPS1);
	SETBIT(ADCSRA,ADPS2);
}
/*
SETBIT(ADCMUX_ADDRESS,6);//REF0
SETBIT(ADCMUX_ADDRESS,0);//adc1
SETBIT(ADCSRA_ADDRESS,7);//ADEN enable
SETBIT(ADCSRA_ADDRESS,5);//auto trigger
SETBIT(ADCSRA_ADDRESS,0);
SETBIT(ADCSRA_ADDRESS,1);
SETBIT(ADCSRA_ADDRESS,2);//prescaler 128
*/
u16 ADC_getDigitalValueSynchNonBlocking(void)
{
	SETBIT(ADCSRA,ADSC); // start single conversion
	while(READBIT(ADCSRA,ADSC) == 1); // conversion not completed
	return ADC;

	
}
/*
u16 result=0;
SETBIT(ADCMUX_ADDRESS,6);//start conversion
while(READBIT(ADCMUX_ADDRESS,6)==1);

//result=ADC_ADDRESS;
return ADC_ADDRESS;
//return result;
*/

