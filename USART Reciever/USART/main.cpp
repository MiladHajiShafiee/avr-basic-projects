/*
 * USART.cpp
 *
 * Created: 2018/07/31 8:02:29 صـبـح
 * Author : Milad
 */ 

#define F_CPU 8000000UL			/* Define frequency here its 8MHz */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Usart.h"
#include <stdlib.h>
#include "Lcd 2x16.h"


USART usart;
Lcd_4_BitMode lcd;


ISR(USART_RXC_vect)
{
	char c[] = {usart.UsartReciever()};
	lcd.LcdString(c);
}


int main()
{
	usart.UsartInit(9600, Asynchronous, Disabled, 8, true);
	lcd.LcdInit();
	sei();
	while(1);
}
