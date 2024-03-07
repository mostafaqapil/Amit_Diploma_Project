/*
 * ADC_Interface.h
 *
 * Created: 1/21/2024 3:57:24 AM
 *  Author: mosta
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*#define ADC_CHANNEL0            0
#define ADC_CHANNEL1            1
#define ADC_CHANNEL2            2
#define ADC_CHANNEL3            3
#define ADC_CHANNEL4            4
#define ADC_CHANNEL5            5
#define ADC_CHANNEL6            6
#define ADC_CHANNEL7            7



#define ADC_REFERENCE_AVCC      1
#define ADC_REFERENCE_AREF      2
#define ADC_REFERENCE_INTERNAL  3



void ADC_init           (u8 referenceVoltage);
u16  ADC_getDigitalValue(u8 channelNum);*/


void ADC_voidInit(void);
void ADC_voidEnable(void);
void ADC_voidDisable(void);

#define ADC_U8_Channel0  0
#define ADC_U8_Channel1  1
#define ADC_U8_Channel2  2
#define ADC_U8_Channel3  3
#define ADC_U8_Channel4  4
#define ADC_U8_Channel5  5
#define ADC_U8_Channel6  6
#define ADC_U8_Channel7  7


u8 ADC_u8Convert(u8 Local_u8Channel);
u64 ADC_u16Convert(u8 Local_u8Channel);

#endif /* ADC_INTERFACE_H_ */