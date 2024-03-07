/*
 * LCD_Interface.h
 *
 * Created: 12/20/2023 5:41:07 PM
 *  Author: mosta
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


typedef enum{
	Clear_Display		=	0x01,
	Return_Home			=	0x02,
	Entry_Mode			=	0x06,
	bit8_2line_5x8font	=	0x38,
	bit4_2line_5x8font	=	0x28,
	bit8_1line			=	0x33,
	displayOn_cursorON  =	0x0E,
	displayOff  =	0x08
}LCD_Commands;


void LCD_voidInit(void);
void LCD_voidSendData(u8 LCD_u8_Data);
void LCD_voidSendCommand(u8 LCD_u8_Command);
void LCD_voidSendString(s8 String[]);
void LCD_Int_to_String(u16 input);
void LCD_gotoxy(u8 x, u8 y);




#endif /* LCD_INTERFACE_H_ */