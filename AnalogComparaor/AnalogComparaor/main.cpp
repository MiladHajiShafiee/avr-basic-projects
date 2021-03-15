/*
 * AnalogComparaor.cpp
 *
 * Created: 2018/08/01 12:33:34 عـصـر
 * Author : Milad
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "AnalogComparator.h"

int main()
{
	DDRA |= (1 << PA0);
	uint8_t AcValue;
	
	while (1)
	{
		AcValue = AcInit(ADC0, False, false);
		if (AcValue)
		{
			PORTA |= (1 << PA0);
		} 
		else
		{
			PORTA &= ~(1 << PA0);
		}
	}
}