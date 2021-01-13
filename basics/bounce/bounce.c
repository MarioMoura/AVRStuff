#include <avr/io.h>
#include <util/delay.h>

#define DELAY 100

int main () __attribute__ ((noreturn));

int main(void){

	DDRB = 0b11111111;

	PORTB = 0b01010101;

	while(1){
		_delay_ms(DELAY);
		PORTB ^= 0b11111111;
	}

}
