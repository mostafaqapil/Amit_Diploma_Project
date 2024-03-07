/*
 * TWI_Privte.h
 *
 * Created: 2/12/2024 8:18:03 PM
 *  Author: mosta
 */ 


#ifndef TWI_PRIVTE_H_
#define TWI_PRIVTE_H_



#define TWBR (*((volatile u8 *)0x20))
#define TWCR (*((volatile u8 *)0x56))
#define TWSR (*((volatile u8 *)0x21))
#define TWDR (*((volatile u8 *)0x23))
#define TWAR (*((volatile u8 *)0x22))



#define TWINT   7
#define TWEA	6
#define TWSTA   5
#define TWSTO	4
#define TWWC	3
#define TWEN	2
//#define TWBR1	1
#define TWIE	0


#define TWPS1	1
#define TWPS0	0



#endif /* TWI_PRIVTE_H_ */