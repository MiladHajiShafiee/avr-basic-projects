/*
 * ExternalHardwareInterrupts.cpp
 *
 * Created: 2018/07/31 11:17:10 عـصـر
 * Author : Milad
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "ExternalInterrupt.h"

ExInterrupt exInt;

ISR(INT0_vect)
{
	PORTA |= (1 << PA0);
	_delay_ms(50);  								/* Software debouncing control delay */
	
}


int main(void)
{
	DDRA |= (1 << 0);
	PORTA &= ~(1 << 0);
	exInt.interrptInit(Int0, anyTrigger);
}
