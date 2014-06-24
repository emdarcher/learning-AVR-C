/* define the cpu frequency so _delay_ms() works properly */
#define F_CPU 1000000UL //1MHz

#include <avr/io.h>
#include <util/delay.h>

//blinks led on PB4 (IC pin3)

int main ( void )
{
	unsigned char counter;
	/* set PORTB for output */
	DDRB = (1<<0);

	while (1)
	{
		/* set PORTB.0 high */
		PORTB = (1<<0);
		

		_delay_ms(1000);
		/* wait (10 * 1200000) cycles = wait 12000000 cycles */
		//counter = 0;
		//while (counter != 50)
		//{
		//	///* wait (30000 x 4) cycles = wait 1200000 cycles */
		//	_delay_loop_2(300000);
		//	counter++;
		//}

		/* set PORTB.0 low */
		PORTB ^= (1<<0);

		_delay_ms(1000);

		/* wait (10 * 120000) cycles = wait 1200000 cycles */
		//counter = 0;
		//while (counter != 50)
		//{
		//	/* wait (30000 x 4) cycles = wait 120000 cycles */
		//	_delay_loop_2(30000);
		//	counter++;
		//}
	}

	return 1;
}
