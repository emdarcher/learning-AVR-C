//blink program


#include <avr/io.h>
#include <util/delay.h>

//#define F_CPU 16500000UL
//#define F_CPU 8000000

void setup(){
DDRB |= (1 << PB1);
}

int main(){
setup();

while (1)
{
	PORTB ^= (1 << PB1);
	_delay_ms(500);
}

}


