/*
 * ADC.c
 *
 * Created: 10/24/2023 9:51:44 AM
 *  Author: Sarah saeed
 */ 
#include "ADC_interface.h"
#include "util/delay.h"
#include "../../HAL/LCD/LCD_interface.h"
void(*ptr_to_callback_fn)(void);

void ADC_Init(init_adc_struct *input)
{
	ADCSRA=(ADCSRA& 00000111)|(input->prescaler);
	ADMUX=(ADMUX &  11000000)|((input->vref)<<6);
	
	switch (input->adc_en) {
		case ADC_ENABLE:
		SETBIT(ADCSRA, ADEN);
		break;
		
		case ADC_DISABLE:
		CLRBIT(ADCSRA, ADEN);
		break;
		
		default:
		break;
	}
	switch(input->adc_channel)
	{
		case ADC_CHANNEL0: ADMUX=0b00000; break;
		case ADC_CHANNEL1: ADMUX=0b00001; break;
		case ADC_CHANNEL2: ADMUX=0b00010; break;
		case ADC_CHANNEL3: ADMUX=0b00011; break;
		case ADC_CHANNEL4: ADMUX=0b00100; break;
		case ADC_CHANNEL5: ADMUX=0b00101; break;
		case ADC_CHANNEL6: ADMUX=0b00110; break;
		case ADC_CHANNEL7: ADMUX=0b00111; break;
		default:
		break;
	}
	switch(input->adj)
	{
		case ADJ_LEFT :SETBIT(ADMUX,ADLAR); break;
		case ADJ_RIGHT:CLRBIT(ADMUX,ADLAR); break;
		default:
		break;
	}
	switch(input->auto_trig_en)
	{
		case AUTO_TRIGGER_ENABLE :SETBIT(ADCSRA,ADATE); break;
		case AUTO_TRIGGER_DISABLE:CLRBIT(ADCSRA,ADATE); break;
		default:
		break;
	}

}
u16 ADC_read(void)
{
	SETBIT(ADCSRA,ADSC); //start single conversion
	while(READBIT(ADCSRA,ADSC)==1); //conversion not completed
	return ADC;
	
}
/*this function should be put in the while*/
u16 ADC_getDigitalValueSynchNonBlocking(void)
{
	u16 adc_result=0;
	SETBIT(ADCSRA,ADSC); // start single conversion
	if(READBIT(ADCSRA,ADIF))
	{
		adc_result=ADC; //assuming that we're right adj
		SETBIT(ADCSRA,ADIF);	
	}
	return adc_result;
}
u16 ADC_getReadNoBlock(init_adc_struct *input)
{
	u16 adc_value=0;
	switch(input->adj)
	{
		case ADJ_LEFT : adc_value=((ADCL&11000000)>>6)|ADCH;   break;
		case ADJ_RIGHT: adc_value=ADC;						   break;
		default:
		break;
	}
	return adc_value;
}
void ADC_getDigitalValueAsynchCallBack(void(*ptr_to_fn)(void),ADC_CHANNEL adc_ch)
{
	switch(adc_ch)
	{
		
		case ADC_CHANNEL0: ADMUX=0b00000; break;
		case ADC_CHANNEL1: ADMUX=0b00001; break;
		case ADC_CHANNEL2: ADMUX=0b00010; break;
		case ADC_CHANNEL3: ADMUX=0b00011; break;
		case ADC_CHANNEL4: ADMUX=0b00100; break;
		case ADC_CHANNEL5: ADMUX=0b00101; break;
		case ADC_CHANNEL6: ADMUX=0b00110; break;
		case ADC_CHANNEL7: ADMUX=0b00111; break;
	}
	SETBIT(ADCSRA,ADSC); // start single conversion
	SETBIT(ADCSRA,ADIE); //enable inturupt
	
	ptr_to_callback_fn=ptr_to_fn;	
}
ISR(ADC_vect)
{
	if (ptr_to_callback_fn!=NULL)
	{
		ptr_to_callback_fn();
	}
}

