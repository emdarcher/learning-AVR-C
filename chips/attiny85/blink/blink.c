//blink program

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000UL

void setup(){
DDRB |= (1 << PB4);
}

int main(){
setup();

while (1)
{
	PORTB ^= (1 << PB4);
	_delay_ms(500);
}

}


