/*
 * Deaf_glove.c
 *
 * Created: 3/5/2024 8:37:37 PM
 * Author : mosta
 */ 


#define F_CPU 16000000
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include "STBD_TYPES.h"
#include "TWI_Interface.h"
#include "EEPROM_interface.h"
#include "LCD_Interface.h"
#include "ADC_Interface.h"
#include "Deaf_interface.h"





int main(void)
{
	ADC_voidInit();
	LCD_voidInit();
	EEPROM_voidInit();
	
	LCD_gotoxy(2,0);
	_delay_ms(2);
	LCD_voidSendString("Deaf");
	_delay_ms(2);
	LCD_gotoxy(3,1);
	_delay_ms(2);
	LCD_voidSendString("Project.AMIT");
	_delay_ms(1000);
	
	
	EEPROM_InsertData ();
	
	
	u16 ADC_Value=0;
	u16 ADC_Value1=1;
	u16 x=0;
	while (1)
	{
	
		ADC_Value=ADC_CollectValue(&x);
		
		if (ADC_Value!=ADC_Value1)
		{
			LCD_voidSendCommand(Clear_Display);
			_delay_ms(2);
			LCD_voidSendCommand(Return_Home);
			
			
			searchandprint(ADC_Value);
			
		}
		ADC_Value1=ADC_Value;
		
	}
}