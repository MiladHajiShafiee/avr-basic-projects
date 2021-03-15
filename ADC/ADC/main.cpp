/*
 * ADC.cpp
 *
 * Created: 2018/07/29 7:26:58 صـبـح
 * Author : Milad
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "Lcd 2x16.h"
#include "Adc.h"

Lcd_4_BitMode lcd;
Adc adc;

int main(void)
{
	
	uint16_t value;
	
	lcd.LcdInit();
	adc.AdcInit(DevidedBy64, Internal);
	lcd.LcdString("Temperature:");
	
    while (1) 
    {
		lcd.LcdCommand(MoveCursorRighttByOneCharacter);
		value = adc.AdcRead('A' , 2)/4;
		lcd.LcdGoXy(0 , strlen("Temperature:") + 1);
		lcd.LcdNum(value, decimal);
		lcd.LcdString(" ");
    }
}
