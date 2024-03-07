/*
 * EEPROM_program.c
 *
 * Created: 3/5/2024 8:43:06 PM
 *  Author: mosta
 */ 


#define F_CPU 16000000UL
#include  <util/delay.h>

#include "STBD_TYPES.h"
#include "BIT_MATH.h"

#include "EEPROM_interface.h"
#include "TWI_Interface.h"



void EEPROM_voidInit(void)
{
	TWI_voidInit();
}


void EEPROM_VoidWriteByte(u16 Copy_Location , u8 Copy_Data)
{
	u8 SLA_W = 0b10100000 ;
	u8 B8 = GET_BIT(Copy_Location , 8);
	u8 B9 = GET_BIT(Copy_Location , 9);
	u8 B10 = GET_BIT(Copy_Location , 10);
	SLA_W |= ((B8<<1) | (B9<<2) | (B10<<3));
	
	TWI_voidSendStart();
	if(True == TWI_u8CheckStatus(StrConTx))
	{
		TWI_voidSendByte(SLA_W);
		if(True == TWI_u8CheckStatus(SlA_W_Ack))
		{
			TWI_voidSendByte((u8)Copy_Location);
			if(True == TWI_u8CheckStatus(Data_TX_Ack))
			{
				TWI_voidSendByte(Copy_Data);
				if(True == TWI_u8CheckStatus(Data_TX_Ack))
				{
					TWI_voidSendStop();
				}
			}
		}
	}
}

void EEPROM_VoidWriteString(u16 Copy_Location,s8 Copy_Str[])
{
	u8 SLA_W = 0b10100000 ;
	u8 B8 = GET_BIT(Copy_Location , 8);
	u8 B9 = GET_BIT(Copy_Location , 9);
	u8 B10 = GET_BIT(Copy_Location , 10);
	SLA_W |= ((B8<<1) | (B9<<2) | (B10<<3));
	
	TWI_voidSendStart();
	if(True == TWI_u8CheckStatus(StrConTx))
	{
		TWI_voidSendByte(SLA_W);
		if(True == TWI_u8CheckStatus(SlA_W_Ack))
		{
			TWI_voidSendByte((u8)Copy_Location);
			if(True == TWI_u8CheckStatus(Data_TX_Ack))
			{
				u8 i=0;
				while(Copy_Str[i]!='\0')
				{
					TWI_voidSendByte((u8)Copy_Str[i]);
					if(True == TWI_u8CheckStatus(Data_TX_Ack))
					{
						i++;
						_delay_ms(5);
					}
				}
				TWI_voidSendByte((u8)Copy_Str[i]);
				if(True == TWI_u8CheckStatus(Data_TX_Ack))
				{
					TWI_voidSendStop();
				}
			}
		}
	}
}

u8 EEPROM_u8ReadByte(u16 Copy_Location)
{
	u8 RetVal = 0;
	u8 SLA_W = 0b10100000;
	u8 SLA_R ;
	u8 B8 = GET_BIT(Copy_Location , 8);
	u8 B9 = GET_BIT(Copy_Location , 9);
	u8 B10 = GET_BIT(Copy_Location , 10);
	SLA_W |= (B8<<1) | (B9<<2) | (B10<<3);
	SLA_R = SLA_W + 1 ;
	
	TWI_voidSendStart();
	if(True == TWI_u8CheckStatus(StrConTx))
	{
		TWI_voidSendByte(SLA_W);
		if(True == TWI_u8CheckStatus(SlA_W_Ack))
		{
			TWI_voidSendByte((u8)  Copy_Location);
			if(True == TWI_u8CheckStatus(Data_TX_Ack))
			{
				TWI_voidSendStart();
				if(True == TWI_u8CheckStatus(RepStrConTx))
				{
					TWI_voidSendByte(SLA_R);
					if(True == TWI_u8CheckStatus(SLA_R_W_ACK))
					{
						RetVal = TWI_u8ReceiveByteWithNoAck();
						
						TWI_voidSendStop();
					}
				}
			}
		}
	}

	return RetVal ;
}

void EEPROM_u8ReadString(u16 Copy_Location, s8 Copy_Str[])
{
	int i=0;
	u8 buffer=EEPROM_u8ReadByte(Copy_Location+i);
	while (buffer!='\0' && buffer!=0xff)
	{
		Copy_Str[i]=buffer;
		i++;
		buffer=EEPROM_u8ReadByte(Copy_Location+i);
		
	}
	Copy_Str[i]='\0';
	
}
