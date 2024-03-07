/*
 * TWI_Program.c
 *
 * Created: 2/12/2024 8:16:43 PM
 *  Author: mosta
 */ 


#include "STBD_TYPES.h"
#include "BIT_MATH.h"


#include "TWI_interface.h"
#include "TWI_Privte.h"


void TWI_voidInit(void)
{
	
	TWBR = 10 ;
	
	SET_BIT(TWSR , TWPS0);
	CLEAR_BIT(TWSR , TWPS1);
	
	
	SET_BIT(TWCR,TWEN);
}

void TWI_voidSetMyAddress(u8 Copy_MyAdd)
{
	TWAR = TWAR & 0x01 ; 
	TWAR = TWAR | (Copy_MyAdd << 1) ;
}

void TWI_voidSendStart(void)
{
	TWCR =   (1<<TWSTA)  | (1<<TWEN) |(1<<TWINT);
	while(GET_BIT(TWCR , TWINT)  == 0);
}

void TWI_voidSendStop(void)
{
	TWCR =  (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

void TWI_voidSendByte(u8 Copy_Byte)
{
	TWDR = Copy_Byte;
	TWCR =   (1<<TWINT)| (1<<TWEN);
	while(GET_BIT(TWCR , TWINT)  == 0);
}

u8 TWI_u8ReceiveByteWithNoAck(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(GET_BIT(TWCR , TWINT)  == 0);
	return TWDR ;
}


u8 TWI_u8ReceiveByteWithAck(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while(GET_BIT(TWCR , TWINT)  == 0);
	return TWDR ;
}

u8 TWI_u8CheckStatus(tenuI2C_Check Copy_Status)
{
	u8 Local_u8TWSR_Temp = TWSR;
	if( Copy_Status == (Local_u8TWSR_Temp & 0xF8 ) )
	{
		return True;
	}
	else
	{
		return False;
	}
}