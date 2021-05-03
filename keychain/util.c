#include <avr/io.h>
#include <util/delay.h>

#define PIN_DELAY 1000

char clicked( char pin, char button ){
	if(bit_is_clear(pin, button)){
		_delay_us(PIN_DELAY);
		if(bit_is_clear(pin, button)){
			return 1;
		}
	}
	return 0;
}
