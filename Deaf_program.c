/*
 * Deaf_program.c
 *
 * Created: 3/5/2024 8:40:58 PM
 *  Author: mosta
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include "STBD_TYPES.h"
#include "TWI_Interface.h"
#include "EEPROM_interface.h"
#include "LCD_Interface.h"
#include "ADC_Interface.h"
#include "Deaf_interface.h"




void EEPROM_InsertData ()              
{										   						
	EEPROM_VoidWriteString(0x0100,"0");		     				
	_delay_ms(10);
	EEPROM_VoidWriteString(0x0000,"Hello!");                   
	_delay_ms(10);
	
	EEPROM_VoidWriteString(0x0110,"1752");	    				
	_delay_ms(10);														      	        	       		     
	EEPROM_VoidWriteString(0x0010,"How are you.");                
	_delay_ms(10);
	
	EEPROM_VoidWriteString(0x0120,"14016");                     
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0020,"good bye.");           
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0130,"14034");                     
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0030,"wow!");                      
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0140,"13970");                     
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0040,"what!.");						
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0150,"82");                       
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0050,"nice!");					
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0160,"14027");                     
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0060,"i am hungry.");				
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0170,"1728");                      
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0070,"I Love you.");				
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0180,"1536");                      
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0080,"i hate you");		   
	_delay_ms(10); 														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x0190,"13899");                   
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x0090,"what do you want");					
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x01A0,"1731");                      
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x00A0,"i want to help");			
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x01B0,"13971");                     
	_delay_ms(10);										     			       		     	       	         
	EEPROM_VoidWriteString(0x00B0,"I can see");	            
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x01C0,"14040");               
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x00C0,"see yoy soon");				
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x01D0,"14043");                    
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x00D0,"i dont understand.");					
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x01E0,"14019");                     
	_delay_ms(10);														       		     	       	         
	EEPROM_VoidWriteString(0x00E0,"me.");						
	_delay_ms(10);														       		     	       	         
																		       		     	       	         
	EEPROM_VoidWriteString(0x01F0,"576");                      
	_delay_ms(10);									           			       		     	       	         
	EEPROM_VoidWriteString(0x00F0,"great project");            
	_delay_ms(10);
	
}


u16  ADC_CollectValue(u16* value)
{
	u16 ADC_value;
	u16 collect=0x0000;
	
	for (u8 i=0;i<5;i++)
	{
		ADC_value=ADC_u16Convert(4-i);
		if (ADC_value==0)                        
		{  collect=(collect<<3)|(0b000);    }
		else if (ADC_value>0&&ADC_value<=340)     
		{  collect=(collect<<3)|(0b001);    }
		else if (ADC_value>340&&ADC_value<=679)   
		{  collect=(collect<<3)|(0b010);    }
		else if (ADC_value>679)                   
		{  collect=(collect<<3)|(0b011);    }
    }
    *value=collect;
	return collect;
}


void searchandprint(u16 data)
{
	s8 str_num[25];                                
	s8 str_word[25];                               
	s8 str_data[5];                                
	sprintf(str_data,"%u",data);
	for (u16 i=0x0100;i<=0x01F0;i+=0x0010)
	{											   
		EEPROM_u8ReadString(i, str_num);		
		int value = strcmp(str_num,str_data);	   
		if(value == 0)							  
		{										   
			EEPROM_u8ReadString(i-0x0100,str_word);
			LCD_voidSendString(str_word);
			return ;
		}
		
	}
	/*
	u16 x;
	s8 str_word[25];
	
	for (u16 i=0x0100;i<=0x01F0;i+=0x0010)
	{
		x=EEPROM_u8ReadByte(i);
		if(x==data)
		{
			EEPROM_u8ReadString(i-0x0100,str_word);
			LCD_voidSendString(str_word);
			return ;
		}
	}
	*/
}