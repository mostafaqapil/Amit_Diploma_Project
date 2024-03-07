/*
 * ADC_Program.c
 *
 * Created: 1/21/2024 3:55:54 AM
 *  Author: mosta
 */ 


#include "STBD_TYPES.h"
#include "BIT_MATH.h"


#include "ADC_interface.h"
#include "ADC_privet.h"
#include "ADC_Privite.h"


/*void ADC_init(u8 referenceVoltage)
{
	switch(referenceVoltage)
	{
		
		case ADC_REFERENCE_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		
		
		case ADC_REFERENCE_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		
		
		case ADC_REFERENCE_INTERNAL:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	
	
	CLR_BIT(ADMUX,ADLAR);
	
	
	CLR_BIT(ADCSRA,ADATE);
	
	
	CLR_BIT(ADCSRA,ADIE);
	
	
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS0);
	
	
	SET_BIT(ADCSRA,ADEN);
}


u16  ADC_getDigitalValue(u8 channelNum)
{
	if(channelNum<32)
	{
		
		ADMUX &= 0xE0;
		
		
		ADMUX |= channelNum;
		
		
		SET_BIT(ADCSRA,ADSC);
		
		
		while(0 == GET_BIT(ADCSRA,ADIF));
		
		
		SET_BIT(ADCSRA,ADIF);
		
		return ADC_u16;
	}
	else
	{
		return 0;
	}
}*/

void ADC_voidInit(void)
{
	#if ADC_U8_VREF  == ADC_U8_AREF
	CLEAR_BIT(ADMUX , 6);
	CLEAR_BIT(ADMUX , 7);
	#elif ADC_U8_VREF  == ADC_U8_AVCC
	SET_BIT(ADMUX , 6);
	CLEAR_BIT(ADMUX , 7);
	#elif ADC_U8_VREF  == ADC_U8_INTERNAL
	SET_BIT(ADMUX , 6);
	SET_BIT(ADMUX , 7);
	#endif
	
	#if ADC_U8_ADJUSTMENT == ADC_U8_LEFT
	SET_BIT(ADMUX , 5);
	#elif ADC_U8_ADJUSTMENT == ADC_U8_RIGHT
	CLEAR_BIT(ADMUX , 5);
	#endif
	
	
	#if ADC_U8_PRESCALER == ADC_U8_BY2
	CLEAR_BIT(ADCSRA , 0);
	CLEAR_BIT(ADCSRA , 1);
	CLEAR_BIT(ADCSRA , 2);
	#elif ADC_U8_PRESCALER == ADC_U8_BY4
	SET_BIT(ADCSRA , 0);
	CLEAR_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
	#elif ADC_U8_PRESCALER == ADC_U8_BY8
	CLEAR_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
	#elif ADC_U8_PRESCALER == ADC_U8_BY16
	SET_BIT(ADCSRA , 0);
	CLEAR_BIT(ADCSRA , 1);
	CLEAR_BIT(ADCSRA , 2);
	#elif ADC_U8_PRESCALER == ADC_U8_BY32
	SET_BIT(ADCSRA , 0);
	CLEAR_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
	#elif ADC_U8_PRESCALER == ADC_U8_BY64
	SET_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	CLEAR_BIT(ADCSRA , 2);
	#elif ADC_U8_PRESCALER == ADC_U8_BY128
	SET_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
	#endif
}

void ADC_voidEnable(void)
{
	SET_BIT(ADCSRA , 7);
}

void ADC_voidDisable(void)
{
	CLEAR_BIT(ADCSRA , 7);
}

#if ADC_U8_ADJUSTMENT == ADC_U8_LEFT
u8 ADC_u8Convert(u8 Local_u8Channel)
{
	ADC_voidDisable();
	ADMUX = ADMUX & 0b11100000; 
	ADMUX =  ADMUX | Local_u8Channel;
	ADC_voidEnable();
	
	SET_BIT(ADCSRA , 6);
	
	while(GET_BIT(ADCSRA , 6) == 1);
	
	return ADCH;
}

#elif ADC_U8_ADJUSTMENT == ADC_U8_RIGHT
u64 ADC_u16Convert(u8 Local_u8Channel)
{
	u8 Local_u8High = 0;
	u8 Local_u8LOW = 0;
	u64 Local_u64Result = 0;
	
	ADC_voidDisable();
	ADMUX = ADMUX & 0b11100000; 
	ADMUX =  ADMUX | Local_u8Channel;
	ADC_voidEnable();
	
	
	SET_BIT(ADCSRA , 6);
	
	while(GET_BIT(ADCSRA , 6) == 1);
	
	Local_u8LOW = ADCL; 
	Local_u8High = ADCH; 

	Local_u64Result = ( (Local_u8High & 0b00000011) << 8) | Local_u8LOW;
	
	return Local_u64Result;
}

#endif