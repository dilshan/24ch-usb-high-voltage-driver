//-------------------------------------------------------------
// STC51 timer definitions for SDCC.
// 
// Based on STC15series MCU Data Sheet - 2015/10/10.
// Last updated: Dilshan Jayakody [14th Jan 2021]
//
// Update log:
// [14/01/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#ifndef STC15W_TIMER_H
#define STC15W_TIMER_H

// Timer Control (TCON) bit definitions.
#define TF1 0x80    // Timer/Counter 1 Overflow Flag.
#define TR1 0x40    // Timer/Counter 1 Run Control bit.
#define TF0 0x20    // Timer/Counter 0 Overflow Flag.
#define TR0 0x10    // Timer/Counter 0 Run Control bit.
#define IE1 0x08    // External Interrupt 1 request flag.
#define IT1 0x04    // External Intenupt 1 Type Select bit.
#define IE0 0x02    // External Interrupt 0 request flag.
#define IT0 0x01    // External Intenupt 0 Type Select bit.

#endif /* STC15W_TIMER_H */