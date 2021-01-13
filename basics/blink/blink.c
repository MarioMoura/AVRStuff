#include <avr/io.h>
#include <util/delay.h>

#define DELAY 300

int main(void)
{
	DDRB = 0b00000001;            /* Data Direction Register B: */
	// set output or input pins
	while (1) {
		PORTB ^= 0b00000001;
		_delay_ms(DELAY);
	}
	return 0;
}
