//demonstate button bounce on two LEDs

#define F_CPU 1000000UL

#include <avr/io.h>

int main(void)
{
	DDRB |= ( 1 << PINB4 ); //set PB4 output led
	PORTB ^= ( 1 << PINB4 ); //toggle PB4
	DDRB |= ( 1 << PINB2 ); //set PB2 output led 2
	DDRB &= ~( 1 << PINB3 ); //set PB3 input button, so 0 bit
	PORTB |= ( 1 << PINB3 ); //set high to use internal pullup resistor

	uint8_t Pressed = 0; //initialize pressed value variable

	while (1)
	{
		if (bit_is_clear(PINB, 3))
		{
			if (Pressed == 0)
			{
				PORTB ^= ( 1 << PINB4 ); //toggle led 1
				PORTB ^= ( 1 << PINB2 ); //toggle led 2 
				Pressed = 1;
			}
		}
		else
		{
		//executes when not pressed
		Pressed = 0;
		}
	}

}
