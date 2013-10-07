/*
 * Blink_A_LED.cpp
 *
 *  Created on: Oct 3, 2013
 *      Author: lhotse
 */



#include <avr/io.h>

#include <util/delay.h>



int main( void )
{
	// Sets all pins of Port D as output
	DDRD |= 0xFF ;

	// Set Pin #5 of Port B as output
	DDRB |= (1 << PB5) ;

	// Initialize Port D
	PORTD = 1 ;

	// Main Loop
	for( ; ; )
	{
		// Left-Shift loop
		for( int i = 0 ; i < 7 ; i++ )
		{
			PORTD <<= 1 ;
			_delay_ms( 125.0 ) ;
		}

		// Right-shift loop
		for( int i = 0 ; i < 7 ; i++ )
		{
			PORTD >>= 1 ;
			_delay_ms( 125.0 ) ;
		}

		// Toggle Pin #5 of Port B
		PORTB ^= (1 << PB5 ) ;
	}

	// Shall never happen
	return( 0 ) ;
}
