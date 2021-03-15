/*
 * SPI.cpp
 *
 * Created: 2018/08/02 7:19:57 صـبـح
 * Author : Milad
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "Lcd 2x16.h"
#include "SPI.h"

Lcd_4_BitMode lcd;
Spi spi;

int main(void)
{
	char data = 'a';
	int charValue = (int)data;
	
	lcd.LcdInit();
	spi.SpiMasterInit(devidedBy64);
	
	lcd.LcdString("Master Device");
	lcd.LcdCommand(GoSecondLine);
	lcd.LcdString("Sent Data:          ");
	
    while (1) 
    {
		spi.SpiWrite(data);
		lcd.LcdGoXy(1, lcd.LcdString("Sent Data:") + 5);
		lcd.LcdChar(data);
		charValue ++;
		data = (char)charValue;
		_delay_ms(500);
    }
}
