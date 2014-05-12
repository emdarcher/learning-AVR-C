//debouncing in software

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
DDRB |= 1 << PINB4; //led
PORTB ^= 1 << PINB4; //toggle
DDRB |= 1 << PINB2; //led2
DDRB &= ~(1 << PINB3); //input from button
PORTB |= 1 << PINB3;

int Pressed = 0;
int Pressed_Confidence_Level = 0; //button press confidence
int Released_Confidence_Level = 0; //vice versa

	while (1)
	{
		if (bit_is_clear(PINB, 3))
		{
			Pressed_Confidence_Level ++; //inc pressed confidence
			Released_Confidence_Level = 0; //reset released confidence
			if (Pressed_Confidence_Level > 500) //inicator of valid press
			{
				if (Pressed == 0)
				{
					PORTB ^= 1 << PINB4; //toggling
					PORTB ^= 1 << PINB2;
					Pressed = 1;
				}
				//Zero it so a new condition can be evaluated
				Pressed_Confidence_Level = 0;
			}
		}
		else
		{
			Released_Confidence_Level ++; //works like pressed
			Pressed_Confidence_Level = 0; //Reset since released
			if (Released_Confidence_Level >500)
			{
				Pressed = 0;
				Released_Confidence_Level = 0;
			}
		}
	
	}
	
}
