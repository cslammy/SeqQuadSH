/*
*  Author: audiodiwhy
*/

#include <stdio.h>
#include "MCP4921.h"
#include "spi3.h"

uint8_t MSBwcontrol = 0;

void write4921(uint16_t data)
{

{

// code assumes LDAC (4921 pin 5) tied to ground
uint16_t data12 = data & 0b0000111111111111; // we only want 12 LSBs




uint8_t MSB = (data12 >> 8);
MSB |= (1 << 6) | (1 << 5) | (1 << 4) ; // buffered ref in, gain = ref; no shutdown

MSB &= ~(1 << 7);  // this control must be zero always

uint8_t LSB = data12 & 0x00FF;








// for 4921, you send 2 bytes.  bit 15 is always zero,
// bits 14,13,12 are control, 11-10-9-8 are MSBs data
//  7 6 5 4 3 2 1 0 are LSB data



//send the data.  4921 can eat 16 bit xfers.
SELECT();

SPI_SendByte(MSB);
//  SPI_SendByte(0b01110111);
SPI_SendByte(LSB);
//   SPI_SendByte(0x00);
DESELECT();


}



}