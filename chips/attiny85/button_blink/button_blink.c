//blink and use button


//define speed 1MHz
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{

DDRB |= (1 << PB4 ); //setup PB4 for output to led
DDRB &= ~(1 << PB3 ); //setup PB3 for button input

PORTB |= (1 << PB3 ); //setup internall pullup resistor on PB3

    while (1)
    {
        PORTB ^= ( 1 << PB4 ) //toggle PB4 and led

	//delay differences based on button input
	if ( bit_is_clear(PB3,1))
	{
	_delay_ms(10); //Fast
	}
	else
	{
	_delay_ms(100); //slower
	}
        
    }

}
