/*
 * ADC_Privite.h
 *
 * Created: 1/21/2024 3:58:08 AM
 *  Author: mosta
 */ 


#ifndef ADC_PRIVITE_H_
#define ADC_PRIVITE_H_

/*#define ADMUX            (*(volatile u8*)0x27)
#define MUX0             0
#define MUX1             1
#define MUX2             2
#define MUX3             3
#define MUX4             4
#define ADLAR            5
#define REFS0            6
#define REFS1            7



#define ADCSRA           (*(volatile u8*)0x26)
#define ADPS0            0
#define ADPS1            1
#define ADPS2            2
#define ADIE             3
#define ADIF             4
#define ADATE            5
#define ADSC             6
#define ADEN             7



#define ADC_u16          (*(volatile u16*)0x24)


#define SFIOR            (*(volatile u8*)0x50)0x50)
#define ADTS2         7
#define ADTS1         6
#define ADTS0         5*/



#define ADC_U8_AVCC       0
#define ADC_U8_AREF       1
#define ADC_U8_INTERNAL   2

#define ADC_U8_LEFT     3
#define ADC_U8_RIGHT    4

#define ADC_U8_BY2    1
#define ADC_U8_BY4    2
#define ADC_U8_BY8    3
#define ADC_U8_BY16   4
#define ADC_U8_BY32   5
#define ADC_U8_BY64   6
#define ADC_U8_BY128  7

#define ADCL    *((volatile u8 *)0x24)
#define ADCH    *((volatile u8 *)0x25)
#define ADCSRA  *((volatile u8 *)0x26)
#define ADMUX   *((volatile u8 *)0x27)


#endif /* ADC_PRIVITE_H_ */