/*
 * WatchDogTimer.cpp
 *
 * Created: 2018/08/01 1:35:05 عـصـر
 * Author : Milad
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "WatchDogTimer.h"


int main(void)
{
	WdtOn(1.0);
	DDRA |= (1 << 6);
	PORTA |= (1 << 6);
	_delay_ms(1000);
	PORTA &= ~(1 << 6);
	while(1);
}

