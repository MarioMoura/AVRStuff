#include <avr/io.h>
#include <util/delay.h>

#include "util.h"

#define B1 PD2
#define B2 PD4
#define B3 PC5


void func(void){

	PORTB ^= 0xff;
	_delay_ms(300);

}



int main(void){

	// B set
	DDRB = 0xff; // set to output

	// D set
	DDRD = 0x00; // set to input
	PORTD |= ( 1 << B1 ); // pull-up resistor on B1
	PORTD |= ( 1 << B2 ); // pull-up resistor on B2

	// C set
	DDRC = 0x00;
	PORTC |= ( 1 << B3 );

	char wasPressed_B1 = 0;
	char wasPressed_B2 = 0; char wasPressed_B3 = 0; void (*seq)(void) = func; //----------------------------
// Loop
//----------------------------

	while(1){

		seq();

		// First Button Press
		if( clicked(PIND,B1) ){
			if(!wasPressed_B1){
				// ----------------------
				PORTB = 0b00000011;
				// ----------------------
				wasPressed_B1 = 1;
			}
		}else{ wasPressed_B1 = 0; }

		// Second Button Press
		if( clicked(PIND,B2) ){
			if(!wasPressed_B2){
				// ----------------------
				PORTB = 0b11000000;
				// ----------------------
				wasPressed_B2 = 1;
			}
		}else{ wasPressed_B2 = 0; }

		// Third Button Press
		if( clicked(PINC,B3) ){
			if(!wasPressed_B3){
				// ----------------------
				PORTB = 0b00011000;
				// ----------------------
				wasPressed_B3 = 1;
			}
		}else{ wasPressed_B3 = 0; }
	}
	return 0;
}
