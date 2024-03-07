/*
 * LCD_Program.c
 *
 * Created: 12/20/2023 5:40:07 PM
 *  Author: mosta
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include "STBD_TYPES.h"

#include <stdio.h>
#include "DIO_interface.h"

#include "LCD_conifg.h"
#include "LCD_Interface.h"



void LCD_voidInit(void)
{
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, LCD_U8_D4 ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, LCD_U8_D5 ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, LCD_U8_D6 ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, LCD_U8_D7 ,DIO_U8_OUTPUT);
	
	DIO_voidSetPinDir(LCD_U8_CONTROL_PORT, LCD_U8_RS ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_CONTROL_PORT, LCD_U8_RW ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_OUTPUT);
	
	_delay_ms(35);
	LCD_voidSendCommand(Return_Home);
	_delay_ms(2);
	LCD_voidSendCommand(bit4_2line_5x8font);
	_delay_ms(2);
	LCD_voidSendCommand(displayOn_cursorON);
	_delay_ms(2);
	LCD_voidSendCommand(Entry_Mode);
	_delay_ms(2);
	LCD_voidSendCommand(Clear_Display);
	_delay_ms(2);
}
void LCD_voidSendData(u8 LCD_u8_Data)
{
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_RS ,DIO_U8_HIGH);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_RW ,DIO_U8_LOW);
	
	DIO_voidSetPortValue(LCD_U8_DATA_PORT , LCD_u8_Data & 0b11110000);
	
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
	
	DIO_voidSetPortValue(LCD_U8_DATA_PORT , (LCD_u8_Data << 4) & 0b11110000);
	
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
}

void LCD_voidSendCommand(u8 LCD_u8_Command)
{
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_RS ,DIO_U8_LOW);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_RW ,DIO_U8_LOW);
	
	DIO_voidSetPortValue(LCD_U8_DATA_PORT , LCD_u8_Command & 0b11110000);
	
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
	
	DIO_voidSetPortValue(LCD_U8_DATA_PORT , (LCD_u8_Command << 4) & 0b11110000);
	
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
}

void LCD_voidSendString(s8 String[])
{
	u8 index = 0;
	while(String[index] != '\0' )
	{
		LCD_voidSendData(String[index]);
		index++;
	}
}

void LCD_Int_to_String(u16 input)
{
	s8 str[5];
	sprintf(str,"%u",input);
	LCD_voidSendString(str);
}

void LCD_gotoxy(u8 x, u8 y)
{
	u8 address;

	if (y == 0)
	address = 0x80 + x; 
	else
	address = 0xC0 + x; 

	LCD_voidSendCommand(address); 
}