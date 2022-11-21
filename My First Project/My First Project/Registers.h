/*
 * Registers.h
 *
 * Created: 23/10/2022 18:07:18
 *  Author: ahmed
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
typedef unsigned char uint8_t;

/************************************************************************/
/* DIO REGISTERS                                                        */
/************************************************************************/
// PORTA register
#define PORTA *((volatile uint8_t*) 0X3B)
#define DDRA *((volatile uint8_t*) 0X3A)
#define PINA *((volatile uint8_t*) 0X39)

// PORTB register
#define PORTB *((volatile uint8_t*) 0X38)
#define DDRB *((volatile uint8_t*) 0X37)
#define PINB *((volatile uint8_t*) 0X36)

// PORTC register
#define PORTC *((volatile uint8_t*) 0X35)
#define DDRC *((volatile uint8_t*) 0X34)
#define PINC *((volatile uint8_t*) 0X33)

// PORTD register
#define PORTD *((volatile uint8_t*) 0X32)
#define DDRD *((volatile uint8_t*) 0X31)
#define PIND *((volatile uint8_t*) 0X30)



/************************************************************************/
/*							Timer registers                             */
/************************************************************************/

#define TCCR0 *((volatile uint8_t*) 0X53)
#define TCNT0 *((volatile uint8_t*) 0X52)
#define TIFR *((volatile uint8_t*) 0X58)

/************************************************************************/
/*				External interrupt registers                            */
/************************************************************************/
#define MCUCR *((volatile uint8_t*) 0X55)
#define MCUCSR *((volatile uint8_t*) 0X54)
#define GICR *((volatile uint8_t*) 0X5B)
#define GIFR *((volatile uint8_t*) 0X5A)
#endif /* REGISTERS_H_ */