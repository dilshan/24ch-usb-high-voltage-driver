//-------------------------------------------------------------
// STC51 SPI definitions for SDCC.
// 
// Based on STC15series MCU Data Sheet - 2015/10/10.
// Last updated: Dilshan Jayakody [14th Jan 2021]
//
// Update log:
// [14/01/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#ifndef STC15W_SPI_H
#define STC15W_SPI_H

// Serial peripheral interface (SPCTL) bit definitions.
#define SSIG    0x80    // Enable / disable SS pin function.
#define SPEN    0x40    // SPI enable bit.
#define DORD    0x20    // Set the transmitted or received SPI data order.
#define MSTR    0x10    // Master/Slave mode select bit.
#define CPOL    0x08    // SPI clock polarity select bit.
#define CPHA    0x04    // SPI clock phase select bit.
#define SPR1    0x02    // SPI clock rate select bit 1.
#define SPR0    0x01    // SPI clock rate select bit 2.

#endif /* STC15W_SPI_H */