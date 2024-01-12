//-------------------------------------------------------------
// STC51 ADC definitions for SDCC.
// 
// Based on STC15series MCU Data Sheet - 2015/10/10.
// Last updated: Dilshan Jayakody [14th Jan 2021]
//
// Update log:
// [14/01/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#ifndef STC15W_ADC_H
#define STC15W_ADC_H

// Analog to digital converter (ADC) bit definitions.
#define ADC_POWER   0x80    // ADC power control bit.
#define SPEED1      0x40    // Conversion speed selection.
#define SPEED0      0x20    // Conversion speed selection.
#define ADC_FLAG    0x10    // ADC interrupt flag.
#define ADC_START   0x08    // ADC start bit.
#define CHS2        0x04    // Analog input source selector bit.
#define CHS1        0x02    // Analog input source selector bit.
#define CHS0        0x01    // Analog input source selector bit.

#endif /* STC15W_ADC_H */