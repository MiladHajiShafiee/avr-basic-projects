/*
 * USART.cpp
 *
 * Created: 2018/07/31 8:02:29 صـبـح
 * Author : Milad
 */ 

#define F_CPU 8000000UL			/* Define frequency here its 8MHz */

#include <avr/io.h>
#include "Usart.h"

USART usart;

int main()
{
	char c[] = "Milad Hsh";
	
	usart.UsartInit(9600, Asynchronous, Disabled, 8, false);
	
	usart.UsartStringTransmiter(c);
}
