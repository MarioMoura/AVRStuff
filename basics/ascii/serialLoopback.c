/*
A simple test of serial-port functionality.
Takes in a character at a time and sends it right back out,
 displaying the ASCII value on the LEDs.
*/

// ------- Preamble -------- //
//
#include <avr/io.h>
#include <util/delay.h>

#ifndef BAUD                          /* if not defined in Makefile... */
#define BAUD  9600                     /* set a safe default baud rate */
#endif

#include <util/setbaud.h>

#define LED_DDR                 DDRB
#define LED_PORT                PORTB

void initUSART(void) {                                /* requires BAUD */
	UBRR0H = UBRRH_VALUE;                        /* defined in setbaud.h */
	UBRR0L = UBRRL_VALUE;
#if USE_2X
	UCSR0A |= (1 << U2X0);
#else
	UCSR0A &= ~(1 << U2X0);
#endif
                                  /* Enable USART transmitter/receiver */
	UCSR0B = (1 << TXEN0) | (1 << RXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);   /* 8 data bits, 1 stop bit */
}

void transmitByte(uint8_t data) {
                                     /* Wait for empty transmit buffer */
	// UDREn  - USART Data Register Empty
	// UCSRnA - USART Control & Status Register A

	loop_until_bit_is_set(UCSR0A, UDRE0);

	// UDR - USART Data Register
	UDR0 = data;                                            /* send data */
}

uint8_t receiveByte(void) {
	  loop_until_bit_is_set(UCSR0A, RXC0); /* Wait for incoming data */
	  return UDR0;                      /* return register value */
}

int main(void) {
	char serialCharacter;

	// -------- Inits --------- //
	LED_DDR = 0xff;                            /* set up LEDs for output */
	initUSART();
	//printString("Hello World!\r\n");                          /* to test */
	transmitByte('1');

// ------ Event loop ------ //
	while (1) {

		serialCharacter = receiveByte();
		transmitByte(serialCharacter);
		LED_PORT = serialCharacter;
		/* display ascii/numeric value of character */

	}                                                  /* End event loop */
	return 0;
}
