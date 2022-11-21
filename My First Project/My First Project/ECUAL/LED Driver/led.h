/*
 * led.h
 *
 * Created: 29/10/2022 14:49:24
 *  Author: ahmed
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO Driver/dio.h"
#define F_CPU 1000000U //1Mhz
#include <util/delay.h> // to use delay function

#define LED_1_PORT PORT_A
#define LED_1_PIN PIN4


void LED_init(uint8_t ledPort, uint8_t ledPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);


#endif /* LED_H_ */