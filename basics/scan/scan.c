#include <avr/io.h>
#include <util/delay.h>

#define DELAY 30
#define BLOCK 3 // 1...8

int main(void){

	DDRB = 0b11111111;

	PORTB = (0b00000001 << BLOCK) - 1;


	_delay_ms(DELAY);
	while(1){
		for(int i = 0; i < 8-BLOCK; i++){
			PORTB = PORTB << 1;
			_delay_ms(DELAY);
		}
		for(int i = 0; i < 8-BLOCK; i++){
			PORTB = PORTB >> 1;
			_delay_ms(DELAY);
		}
	
	}

}
