/*
 * Usart.cpp
 *
 * Created: 2018/07/31 8:03:34 صـبـح
 *  Author: Milad
 */ 

#define F_CPU 8000000UL


#include "Usart.h"


void USART::UsartInit(uint16_t desiredBaudRate , PhraseVarriable AS, PhraseVarriable parityMode, uint8_t characterSize  , bool interrupt)
{
	uint16_t UbbrValue;
	switch (parityMode)
	{
		case Disabled:
		UCSRC &= ~(1 << UPM0);
		UCSRC &= ~(1 << UPM1);
		break;
		case EvenParity:
		UCSRC |= (1 << UPM1);
		break;
		case OddParity:
		UCSRC |= (1 << UPM0);
		break;
	}
	switch (AS)
	{
		case Synchronous:
		UCSRC |= (1 << UMSEL);
		break;
		case Asynchronous:
		UCSRC &= ~(1 << UMSEL);
		break;
	}
	if(interrupt)
	{
		UCSRB |= (1 << RXCIE);
		UCSRB |= (1 << TXCIE);
	}
	UCSRB |= (1 << RXEN)|(1 << TXEN);
	UCSRC |= (1 << URSEL);
	switch (characterSize)
	{
		case 5:
			UCSRC &= ~(1 << UCSZ0);
			UCSRC &= ~(1 << UCSZ1);
		break;
		case 6:
			UCSRC |= (1 << UCSZ0);
			UCSRC &= ~(1 << UCSZ1);
		break;
		case 7:
			UCSRC |= (1 << UCSZ1);
			UCSRC &= ~(1 << UCSZ0);
		break;
		case 8:
			UCSRC = (1 << UCSZ0)|(1 << UCSZ1);
		break;
		case 9:
			UCSRC = (1 << UCSZ0)|(1 << UCSZ1)|(1 << UCSZ2);
		break;
	}
	
	UbbrValue = F_CPU / (desiredBaudRate * 16UL) - 1;
	
	UBRRL = UbbrValue;
	UBRRH = (UbbrValue >> 8);
}

void USART::UsartTransmiter(unsigned char character)
{
	while (!(UCSRA & (1<<UDRE)));
	UDR = character;
}

void USART::UsartNumTransmiter(uint16_t character)
{
	while (!(UCSRA & (1<<UDRE)));
	UDR = character;
}

unsigned char USART::UsartReciever(void)
{
	while ((UCSRA & (1 << RXC)) == 0);
	return UDR;
}

void USART::UsartStringTransmiter(char *str)
{
	
	unsigned char i = 0;
	
	while (str[i] != 0)
	{
		UsartTransmiter(str[i]);
		i++;
	}
		
}
