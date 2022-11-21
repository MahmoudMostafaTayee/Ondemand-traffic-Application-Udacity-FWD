/*
 * application.h
 *
 * Created: 29/10/2022 22:33:25
 *  Author: ahmed
 */ 

#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button driver/button.h"
#include "../MCAL/Interrupt library/interrupt.h"

#ifndef APPLICATION_H_
#define APPLICATION_H_

void appInit();
void appStart();
void delay();

#endif /* APPLICATION_H_ */