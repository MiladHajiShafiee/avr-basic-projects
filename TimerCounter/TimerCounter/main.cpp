/*
 * TimerCounter.cpp
 *
 * Created: 2018/07/30 8:53:20 صـبـح
 * Author : Milad
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "TimerCounter.h"

TC timerCounter;

int main(void)
{
	//while (1)
	//{
		timerCounter.TimerMode(Timer0 , Normal , Toggle , 1024 , 0 , 0 , false , false);
	//}
}
