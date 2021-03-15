/*
 * KeypadCode.cpp
 *
 * Created: 2018/07/10 8:19:11 صـبـح
 * Author : Milad
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "Lcd 2x16.h"
#include "IOComponents.h"

Button keypad;
Lcd_4_BitMode lcd;

int main(void)
{
	int value;
	char printChar[10];
	
	lcd.LCD_Init();
	
	while(true)
	{
		value = keypad.Keypad('D' , 'D' , 4 , 3 , 'A');
		itoa(value , printChar , 10);
		lcd.LCD_String_xy(0 , 0 , printChar);
	}
}
