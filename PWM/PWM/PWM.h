/*
 * PWM.h
 *
 * Created: 2018/07/31 7:08:04 عـصـر
 *  Author: Milad
 */ 

#include <avr/io.h>


#ifndef PWM_H_
#define PWM_H_

void PwmInit(void)
{
	/*set fast PWM mode with non-inverted output*/
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS00);
	DDRB |= (1 << PB3);													/*set OC0 pin as output*/
}



#endif /* PWM_H_ */