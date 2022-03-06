/*
 * SeqSH.c
 *
 * Created: 3/3/2022 6:24:55 AM
 * Author : audiodiwhy
 */ 

#include <avr/io.h>
#include "4051lib.h"
#include "MCP4921.h"
#include "spi3.h"
#include <util/delay.h>


/* add code like this to main.c 

//configure DDRB0-3 as outputs for 4051 logic--
DDRB |= (1 << DDB0); // A
DDRB |= (1 << DDB1); // B
DDRB |= (1 << DDB2); //C
DDRB |= (1 << DDB3); // inhibit

*/

 

int main(void)
{

//328setup

//configure DDRB0-3 as outputs for 4051 logic-- 
DDRD |= (1 << DDD0); // A
DDRD |= (1 << DDD1); // B
DDRD |= (1 << DDD2); //C
DDRD |= (1 << DDD3); // inhibit

//SPI setup
init_spi_master();
spi_mode(2);

	//Set all outputs to zero.
	
	single4051_out(0);
	write4921(0);
	

	single4051_out(1);
	write4921(0);
	

	single4051_out(2);
	write4921(0);


	single4051_out(3);
	write4921(0);

 
 
    while (1) 
    {
   // this could easily be turned into a function
   //something like writeSH(uint16_t SH0, uint16_t SH1, uint16_t SH2 etc)
   //for testing I am manually entering the values to send to
   //each SH
   
	write4921(4000);
	 	_delay_ms(2);	
    single4051_out(0);	
    single4051_inhibit();
    _delay_ms(1);

	write4921(0);
	_delay_ms(1);	
	single4051_out(1);	
    single4051_inhibit();
    _delay_ms(1);
	
	write4921(2500);
	_delay_ms(2);
	single4051_out(2);	
    single4051_inhibit();
    _delay_ms(1);
	
	write4921(1000);
	_delay_ms(2);
	single4051_out(3);
	single4051_inhibit();
	_delay_ms(1);


	
	}


	
}



