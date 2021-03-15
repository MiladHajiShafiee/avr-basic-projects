/*
 * PWM.cpp
 *
 * Created: 2018/07/31 6:56:53 عـصـر
 * Author : Milad
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "PWM.h"


int main(void)
{
	unsigned int duty = 1;
	unsigned int countMount = 1;
	PwmInit();
	
    while (1) 
    {
		if (duty == 255 || duty == 0)
		{
			countMount = -countMount;
		}
		OCR0 = duty;
		duty += countMount;
		_delay_ms(8);
    }
}

