/*
 * EEPROM.cpp
 *
 * Created: 2018/08/16 8:54:01 صـبـح
 * Author : Milad
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/eeprom.h>
#include "Lcd 2x16.h"

Lcd_4_BitMode lcd;

int main(void)
{
	/*
	uint8_t ByteOfData;
	ByteOfData = 0x55;
	eeprom_update_byte((uint8_t *)64, ByteOfData);
	
	uint8_t value;
	value = eeprom_read_byte((const uint8_t *)64);
	lcd.LcdInit();
	lcd.LcdNum(value, hexadecimal);
	*/
	lcd.LcdInit();
	char yourString[15], myString[15] = "My EEPROM Test";
	memset(yourString, 0, 15);
	eeprom_busy_wait();
	eeprom_write_block(myString, 0, strlen(myString));
	eeprom_read_block(yourString, 0, strlen(myString));
	lcd.LcdString(yourString);
}
