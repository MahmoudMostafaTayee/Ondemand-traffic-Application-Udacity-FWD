/*
 * button.h
 *
 * Created: 29/10/2022 23:01:53
 *  Author: ahmed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


#include "../../MCAL/DIO Driver/dio.h"
// Defining button #1
#define BUTTON_1_PORT PORT_B
#define BUTTON_1_PIN PIN2

// Defining button #2
#define BUTTON_2_PORT PORT_B
#define BUTTON_2_PIN PIN5

//initialize
void buttonInit(uint8_t buttonPort, uint8_t buttonPin);

//Button read
void buttonRead(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);


#endif /* BUTTON_H_ */