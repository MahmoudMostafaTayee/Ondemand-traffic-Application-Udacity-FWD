/*
 * interrupt.h
 *
 * Created: 07/11/2022 22:12:38
 *  Author: ahmed
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/************************************************************************/
/*						Interrupt vectors                               */
/************************************************************************/
//External interrupt vectors
// External interrupt request 0
#define EXT_INT0 __vector_1
// External interrupt request 1
#define EXT_INT1 __vector_2
// External interrupt request 2
#define EXT_INT2 __vector_3

//Set global interrupts, set the I-bit	in status register to 1
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

//Clear global interrupts, set the I-bit	in status register to 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

// ASR identification
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)
#endif /* INTERRUPT_H_ */