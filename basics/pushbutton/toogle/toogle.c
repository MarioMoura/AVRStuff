
#include<avr/io.h>
#include<util/delay.h>

char clicked(void){
	if(bit_is_clear(PIND,PD2)){
		_delay_us(1000);
		if(bit_is_clear(PIND,PD2)){
			return 1;
		}
	}
	return 0;
}

int main(void){

	char wasPressed = 0;

	DDRB = 0xff;
	PORTB = 0xff;

	DDRD = 0x00;
	PORTD |= (1 << PD2);


	while(1){
		if( clicked() ){
			if(!wasPressed){
				PORTB ^= 0b11111111;
				wasPressed = 1;
			}
		}else{
			wasPressed = 0;
		}
	}



	return 0;
}
