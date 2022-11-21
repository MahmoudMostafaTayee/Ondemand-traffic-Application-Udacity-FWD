/*
 * application.c
 *
 * Created: 29/10/2022 22:33:11
 *  Author: ahmed
 */ 

#include "application.h"
#define NUMBER_OF_OVERFLOWS 1200

/*
Application states:
	State 0:
		•	Pedestrian -> Green
		•	Cars -> Red
	State 1:
		•	Pedestrian -> Yellow
		•	Cars -> Yellow
	State 2:
		•	Pedestrian -> Red
		•	Cars -> Green
	State 3:
		•	Pedestrian -> Yellow
		•	Cars -> Yellow
*/
uint8_t state = 0; // This variable to define the state of the application as defined above.

/*
	Interrupt reaction to every state(State diagram):
		•	state 0 -> Do no thing.
		•	state 1 -> state 2
		•	state 2 -> state 2
		•	state 3 -> state 2
*/
uint8_t interrupt_happened = 0; // This is just to track if an interrupt happened to go to act up on it(As state above).
uint8_t multi_press_flag = 0; //This is just to raise a flag if an the button is pushed within the same state to consider it just once(first one) if pressed again.

// appInit skeletal.
/*
	1- Initialize the button as input.
	2- Initialize the leds as outputs.
	3- initializations for the interrupt.
		a- Enable global interrupt.
		b- work on the rising edge.
		c- Enable the external interrupt.
		d- Choose timer mode and set the timer value.
*/
void appInit(){
	// 1- set direction of button pin as input
	buttonInit(PORT_D, PIN2);
	
	//Set all led pins to output
	LED_init(PORT_B, PIN0);
	LED_init(PORT_B, PIN1);
	LED_init(PORT_B, PIN2);
	
	LED_init(PORT_A, PIN0);
	LED_init(PORT_A, PIN1);
	LED_init(PORT_A, PIN2);
	
	// Enable global interrupts
	sei();
	
	// Choose the interrupt sense control on rising edge.
	MCUCR |= (1<<0) | (1<<1);
	
	// Enable external interrupt 0 - INT0
	GICR |= (1<<6);
	
	
	//Choose timer mode
	TCCR0 = 0x00; // Normal mode
	// Set timer value
	TCNT0 = 0x00;
	
	
}

// appStart skeletal.
/*
	1- Iteratively check on the state to act up on its change.
		a- Change the leds depending on the state.
		b- Call the delay function.
		c- Update the state.
	
*/
void appStart(){
			// uint8_t state = 0;
	 		while(1)
			 {
		 			
			 	switch(state){
				 	case 0:
						// RED for cars and GREEN for pedestrians.
				 		LED_on(PORT_B, PIN0);
				 		LED_off(PORT_B, PIN1);
				 		LED_off(PORT_B, PIN2);
				 		LED_off(PORT_A, PIN0);
				 		LED_off(PORT_A, PIN1);
				 		LED_on(PORT_A, PIN2);
				 		delay(state);
						state++;
				 		break;
				 	case 1:
						// YELLOW for both cars and pedestrians.
				 		LED_off(PORT_B, PIN0);
				 		LED_on(PORT_B, PIN1);
				 		LED_off(PORT_B, PIN2);
				 		LED_off(PORT_A, PIN0);
				 		LED_on(PORT_A, PIN1);
				 		LED_off(PORT_A, PIN2);
				 		delay(state);
						state++;
				 		break;
				 	case 2:
					 // GREEN for cars and RED for pedestrians.
				 		LED_off(PORT_B, PIN0);
				 		LED_off(PORT_B, PIN1);
				 		LED_on(PORT_B, PIN2);
				 		LED_on(PORT_A, PIN0);
				 		LED_off(PORT_A, PIN1);
				 		LED_off(PORT_A, PIN2);
				 		delay(state);
				 		state++;
				 		break;
					case 3:
						// YELLOW for both cars and pedestrians.
						LED_off(PORT_B, PIN0);
						LED_on(PORT_B, PIN1);
						LED_off(PORT_B, PIN2);
						LED_off(PORT_A, PIN0);
						LED_on(PORT_A, PIN1);
						LED_off(PORT_A, PIN2);
						delay(state);
						state++;
						break;
				 		default:
				 		// Do nothing
				 		break;
			 	}
				if(state == 4)
					state = 0;
		 		
	 		}
		
}

// delay skeletal.
/*
	1- Set the overflow counter to be 0.
	2- Set the prescaler.
	3- check if the state is 1 or 3 wihch mean yellow leds to make toggle on the delay period.
	4- Make a busy wait to stay in it for the delay and just check if interrupt happened within it, if happened, return.
	5- After the busy wait, clear the overflow flag.
	6- Set the timer value to its inital.
	7- Set the overflow counter to be 0.
*/
void delay(){
	unsigned int overFlowCounter = 0;
	//Timer start -> setting the clock source.
	TCCR0 |= (1<<2); // prescaler = 1024.
	
	int overflows = NUMBER_OF_OVERFLOWS;
	uint8_t iter = 1;
	if(state == 1 || state == 3)
				{
					iter = 7;
					overflows = NUMBER_OF_OVERFLOWS / iter;
				}
	for(uint8_t i = 0; i< iter; i++)
			{
				while(overFlowCounter < overflows){
					//stop after one overflow -> 256 microsecond.
					// Wait until overflow flag to be set.
					while((TIFR & (1<<0)) == 0) // Busy wait.
													{
														if(interrupt_happened) // This condition is to break normal function and go back from delay function if needed
														{
															interrupt_happened = 0;
															return;
														}
													}
					
					// Clear the overflow flag.
					TIFR |= (1<<0);
					overFlowCounter++;
				}
				// Set timer value
				TCNT0 = 0x00;
				
				overFlowCounter = 0;
				LED_toggle(PORT_B, PIN1);
				LED_toggle(PORT_A, PIN1);
			}
			multi_press_flag = 0;
	
}

// ISR skeletal.
/*
	1- Check if multi flag is not 0 to ignore the multi presses.
	2- Set the multi_press_flag to 1 to mark a press within 5 seconds.
	3- Check the state to act up on it and according to the state diagram above.
*/
ISR(EXT_INT0)
{
	if(multi_press_flag == 0)	{
		
		multi_press_flag = 1; // Set it to one to tell if
		switch(state){
			case 0:
			state = 0;
			interrupt_happened = 1;
			break;
			case 1:
			state = 0;
			interrupt_happened = 1;
			break;
			case 3:
			state = 0;
			interrupt_happened = 1;
			break;
			case 2:
			// Do nothing
			break;
			default:
			// Error handling
			break;
			
		}
	}
		
}

