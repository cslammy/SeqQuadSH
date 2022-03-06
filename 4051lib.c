/*
 * _4051lib.c
 *
 * Created: 3/3/2022 6:39:07 AM
 *  Author: audiodiwhy
 */ 
#include <avr/io.h>
#include "4051lib.h"


/* logic for 4051
A	B	C	E	Q
X	X	X	1	Hi
0	0	0	0	D0
1	0	0	0	D1
0	1	0	0	D2
1	1	0	0	D3
0	0	1	0	D4
1	0	1	0	D5
0	1	1	0	D6
1	1	1	0	D7
*/



void single4051_out(uint8_t output)
{
	switch (output)
	{
	case 0:
	PORTCHOICE &= ~(1 << PINCHOICE0);
	PORTCHOICE &= ~(1 << PINCHOICE1);
	PORTCHOICE &= ~(1 << PINCHOICE2);
	PORTCHOICE &= ~(1 << PINCHOICE3);
	
	break; 

    case 1:
    PORTCHOICE |= (1 <<  PINCHOICE0);
    PORTCHOICE &= ~(1 << PINCHOICE1);
    PORTCHOICE &= ~(1 << PINCHOICE2);
    PORTCHOICE &= ~(1 << PINCHOICE3);
    break;
   
   
    case 2:
    PORTCHOICE &= ~(1 << PINCHOICE0);
    PORTCHOICE |= (1 <<  PINCHOICE1);
    PORTCHOICE &= ~(1 << PINCHOICE2);
    PORTCHOICE &= ~(1 << PINCHOICE3);
    break;

    case 3:
    PORTCHOICE |= (1 << PINCHOICE0);
    PORTCHOICE |= (1 << PINCHOICE1);
    PORTCHOICE &= ~(1 <<PINCHOICE2);
    PORTCHOICE &= ~(1 <<PINCHOICE3);
    break;
	
	case 4:
	PORTCHOICE &= ~(1 << PINCHOICE0);
	PORTCHOICE &= ~(1 << PINCHOICE1);
	PORTCHOICE |= (1 <<  PINCHOICE2);
	PORTCHOICE &= ~(1 << PINCHOICE3);
	break;
		
    case 5:
    PORTCHOICE |= (1 <<  PINCHOICE0);
    PORTCHOICE &= ~(1 << PINCHOICE1);
    PORTCHOICE |= (1 <<  PINCHOICE2);
	PORTCHOICE &= ~(1 << PINCHOICE3);
	break;
			
	case 6:
	PORTCHOICE &= ~(1 << PINCHOICE0);
	PORTCHOICE |= (1 << PINCHOICE1);
	PORTCHOICE |= (1 << PINCHOICE2);
	PORTCHOICE &= ~(1 << PINCHOICE3);
	break;
				
	case 7:
	PORTCHOICE |= (1 <<  PINCHOICE0);
	PORTCHOICE |= (1 << PINCHOICE1);
	PORTCHOICE |= (1 << PINCHOICE2);
	PORTCHOICE &= ~(1 << PINCHOICE3);
	break;

    	
    default :
	
	PORTCHOICE &= ~(1 << PINCHOICE0);
	PORTCHOICE &= ~(1 << PINCHOICE1);
	PORTCHOICE &= ~(1 << PINCHOICE2);
	PORTCHOICE &= ~(1 << PINCHOICE3);    	


	}
}
void single4051_inhibit(void)
{

    	PORTCHOICE |= (1 << PINCHOICE3);		
}


	
