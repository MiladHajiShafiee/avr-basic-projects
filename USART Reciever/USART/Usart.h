/*
 * Usart.h
 *
 * Created: 2018/07/31 8:03:52 صـبـح
 *  Author: Milad
 */ 


#ifndef USART_H_
#define USART_H_

#include <avr/io.h>
#include <avr/interrupt.h>


enum PhraseVarriable {
	Asynchronous, Synchronous,
	EvenParity, OddParity, Disabled,
	};


class USART
{
	public:
	
	void UsartInit(uint16_t desiredBaudRate, PhraseVarriable AS, PhraseVarriable parityMode, uint8_t characterSize , bool interrupt);
	
	void UsartTransmiter(unsigned char character);
	
	void UsartNumTransmiter(uint16_t character);
	
	unsigned char UsartReciever(void);
	
	unsigned char UsartNumReciever(void);
	
	void UsartStringTransmiter(char *str);
	
	};


#endif /* USART_H_ */
