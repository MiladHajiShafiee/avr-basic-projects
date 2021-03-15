/*
 * I2C.cpp
 *
 * Created: 2018/08/05 8:20:01 صـبـح
 * Author : Milad
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "I2C.h"
#include "Lcd 2x16.h"

Lcd_4_BitMode lcd;
I2c i2c;

/*
int main()
{
	char array[] = " This is my First I2C" ;
	
	while (1)
	{
		lcd.LcdInit();
		i2c.MasterInit(DevidedBy64);
		lcd.LcdClear();
		lcd.LcdString("Master Device");
		i2c.StartWait(0x20);
		_delay_ms(5);
		i2c.Write(0x21);
		i2c.ReapetedStart(0x20);
		for (uint8_t count = 0 ; count < strlen(array) ; count ++)
		{
			uint8_t i = i2c.Write(array[count]);
			lcd.LcdGoXy(1 , 0);
			lcd.LcdChar(i);
			_delay_ms(50);
		}
		i2c.Stop();
	}
}
*/


int main()
{
	lcd.LcdInit();
	lcd.LcdString("Master Device:");
	lcd.LcdCommand(GoSecondLine);
	lcd.LcdString("Sent: ");
	lcd.LcdGoXy(1, 6);
	i2c.MasterInit(DevidedBy64);
	char data[] = "Milad Hsh";
	i2c.StartWait(0x10);
	_delay_ms(5);
	i2c.Write(0x11);
	for (uint8_t i = 0 ; i <= strlen(data) ; i++)
	{
		i2c.Write(data[i]);
		lcd.LcdChar(data[i]);
	}
	i2c.Stop();
}