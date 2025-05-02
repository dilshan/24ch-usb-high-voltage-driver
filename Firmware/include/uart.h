//-------------------------------------------------------------
// STC51 UART definitions for SDCC.
// 
// Based on STC15series MCU Data Sheet - 2015/10/10.
// Last updated: Dilshan Jayakody [14th Jan 2021]
//
// Update log:
// [14/01/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#ifndef STC15W_UART_H
#define STC15W_UART_H

// Serial Control (SCON) bit definitions.
#define SM0 0x80    // Serial mode 0.
#define SM1 0x40    // Serial mode 1.
#define SM2 0x20    // Serial mode 2.
#define REN 0x10    // Enables serial reception.
#define TB8 0x08    // Enable 9th data bit transmission.
#define RB8 0x04    // Received 9th data bit.
#define TI  0x02    // Transmit interrupt flag.
#define RI  0x01    // Receive interrupt flag.

// Serial Control 2 (S2CON) bit definitions.
#define S2SM0 0x80    // Serial mode 0.
#define S2SM2 0x20    // Serial mode 2.
#define S2REN 0x10    // Enables serial reception.
#define S2TB8 0x08    // Enable 9th data bit transmission.
#define S2RB8 0x04    // Received 9th data bit.
#define S2TI  0x02    // Transmit interrupt flag.
#define S2RI  0x01    // Receive interrupt flag.

// Serial Control 3 (S3CON) bit definitions.
#define S3SM0 0x80    // Serial mode 0.
#define S3ST3 0x40    // Serial mode 1.
#define S3SM2 0x20    // Serial mode 2.
#define S3REN 0x10    // Enables serial reception.
#define S3TB8 0x08    // Enable 9th data bit transmission.
#define S3RB8 0x04    // Received 9th data bit.
#define S3TI  0x02    // Transmit interrupt flag.
#define S3RI  0x01    // Receive interrupt flag.

// Serial Control 4 (S4CON) bit definitions.
#define S4SM0 0x80    // Serial mode 0.
#define S4ST4 0x40    // Serial mode 1.
#define S4SM2 0x20    // Serial mode 2.
#define S4REN 0x10    // Enables serial reception.
#define S4TB8 0x08    // Enable 9th data bit transmission.
#define S4RB8 0x04    // Received 9th data bit.
#define S4TI  0x02    // Transmit interrupt flag.
#define S4RI  0x01    // Receive interrupt flag.

#endif /* STC15W_UART_H */