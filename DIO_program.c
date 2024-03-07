/*
 * DIO_program.c
 *
 * Created: 12/13/2023 2:50:06 AM
 *  Author: mosta
 */ 

#include "DIO_Private.h"

#include "STBD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

void DIO_voidSetPinDir(u8 Port, u8 Pin, u8 Direction)
{
	switch(Port)
	{
		case DIO_U8_PORTA:
		if(Direction == DIO_U8_INPUT)
		{
			CLEAR_BIT(DDRA,Pin);
		}
		else if(Direction == DIO_U8_OUTPUT)
		{
			SET_BIT(DDRA,Pin);
		}
		break;
		
		case DIO_U8_PORTB:
		if(Direction == DIO_U8_INPUT)
		{
			CLEAR_BIT(DDRB,Pin);
		}
		else if(Direction == DIO_U8_OUTPUT)
		{
			SET_BIT(DDRB,Pin);
		}
		break;

		case DIO_U8_PORTC:
		if(Direction == DIO_U8_INPUT)
		{
			CLEAR_BIT(DDRC,Pin);
		}
		else if(Direction == DIO_U8_OUTPUT)
		{
			SET_BIT(DDRC,Pin);
		}
		break;

		case DIO_U8_PORTD:
		if(Direction == DIO_U8_INPUT)
		{
			CLEAR_BIT(DDRD,Pin);
		}
		else if(Direction == DIO_U8_OUTPUT)
		{
			SET_BIT(DDRD,Pin);
		}
		break;
	}
}
void DIO_voidSetPinVal(u8 Port, u8 Pin, u8 Value)
{
	switch(Port)
	{
		case DIO_U8_PORTA:
		if(Value == DIO_U8_LOW)
		{
			CLEAR_BIT(PORTA,Pin);
		}
		else if(Value == DIO_U8_HIGH)
		{
			SET_BIT(PORTA,Pin);
		}
		break;
		
		case DIO_U8_PORTB:
		if(Value == DIO_U8_LOW)
		{
			CLEAR_BIT(PORTB,Pin);
		}
		else if(Value == DIO_U8_HIGH)
		{
			SET_BIT(PORTB,Pin);
		}
		break;

		case DIO_U8_PORTC:
		if(Value == DIO_U8_LOW)
		{
			CLEAR_BIT(PORTC,Pin);
		}
		else if(Value == DIO_U8_HIGH)
		{
			SET_BIT(PORTC,Pin);
		}
		break;

		case DIO_U8_PORTD:
		if(Value == DIO_U8_LOW)
		{
			CLEAR_BIT(PORTD,Pin);
		}
		else if(Value == DIO_U8_HIGH)
		{
			SET_BIT(PORTD,Pin);
		}
		break;
	}
}
u8 DIO_u8GetPinVal(u8 Port, u8 Pin)
{
	u8 LOCAL_u8Result = 0;
	switch(Port)
	{
		case DIO_U8_PORTA: LOCAL_u8Result = GET_BIT(PINA,Pin); break;
		case DIO_U8_PORTB: LOCAL_u8Result = GET_BIT(PINB,Pin); break;
		case DIO_U8_PORTC: LOCAL_u8Result = GET_BIT(PINC,Pin); break;
		case DIO_U8_PORTD: LOCAL_u8Result = GET_BIT(PIND,Pin); break;
	}
	
	return LOCAL_u8Result;
}

void DIO_voidSetPortValue(u8 DIO_u8Port, u8 DIO_u8Value)
{
	if(DIO_u8Port == DIO_U8_PORTA)
	{
		PORTA = DIO_u8Value;
	}
	else if(DIO_u8Port == DIO_U8_PORTB)
	{
		PORTB = DIO_u8Value;
	}
	else if(DIO_u8Port == DIO_U8_PORTC)
	{
		PORTC = DIO_u8Value;
	}
	else if(DIO_u8Port == DIO_U8_PORTD)
	{
		PORTD = DIO_u8Value;
	}
}