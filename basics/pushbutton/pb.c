
#include<avr/io.h>
#include<util/delay.h>

int main(void){

	DDRD = 0x00; // all D block ports as input
	PORTD |= (1 << PD2); // pullup resistor on port pd2

	DDRB = 0xff;

	while(1){
		if(PIND) // on
			PORTB = 0b00111100;
		else     // off
			PORTB = 0b11000011;
	
	}



	return 0;
}
