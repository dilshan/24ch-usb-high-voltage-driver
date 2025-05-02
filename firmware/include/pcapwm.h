//-------------------------------------------------------------
// STC51 PCA/PWM definitions for SDCC.
// 
// Based on STC15series MCU Data Sheet - 2015/10/10.
// Last updated: Dilshan Jayakody [14th Jan 2021]
//
// Update log:
// [14/01/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#ifndef STC15W_PCA_PWM_H
#define STC15W_PCA_PWM_H

// PCA (Programmable Counter Array) Control Register (CCON) bit definitions.
#define CF      0x80    // PCA Counter overflow flag.
#define CR      0x40    // PCA Counter Run control bit.
#define CCF3    0x08    // PCA Module 3 interrupt flag.
#define CCF2    0x04    // PCA Module 2 interrupt flag.
#define CCF1    0x02    // PCA Module 1 interrupt flag.
#define CCF0    0x01    // PCA Module 0 interrupt flag.

// PCA (Programmable Counter Array) Operation Mode (CMOD) bit definitions.
#define CIDL    0x80    // PCA Counter control bit in Idle mode.
#define CPS2    0x08    // PCA Counter Pulse source Select bit 2.
#define CPS1    0x04    // PCA Counter Pulse source Select bit 1.
#define CPS0    0x02    // PCA Counter Pulse source Select bit 0.
#define ECF     0x01    // PCA Counter Overflow interrupt Enable bit.

// Capture/Compare register of PCA module 0 (CCAPM0) bit definitions.
#define ECOM0   0x40    // Comparator Enable bit.
#define CAPP0   0x20    // Capture Positive control bit.
#define CAPN0   0x10    // Capture Negative control bit.
#define MAT0    0x08    // Match control bit.
#define TOG0    0x04    // Toggle control bit.
#define PWM0    0x02    // Pulse Width Modulation enable bit.
#define ECCF0   0x01    // Enable CCF0 interrupt.

// Capture/Compare register of PCA module 1 (CCAPM1) bit definitions.
#define ECOM1   0x40    // Comparator Enable bit.
#define CAPP1   0x20    // Capture Positive control bit.
#define CAPN1   0x10    // Capture Negative control bit.
#define MAT1    0x08    // Match control bit.
#define TOG1    0x04    // Toggle control bit.
#define PWM1    0x02    // Pulse Width Modulation enable bit.
#define ECCF1   0x01    // Enable CCF0 interrupt.

// Capture/Compare register of PCA module 2 (CCAPM2) bit definitions.
#define ECOM2   0x40    // Comparator Enable bit.
#define CAPP2   0x20    // Capture Positive control bit.
#define CAPN2   0x10    // Capture Negative control bit.
#define MAT2    0x08    // Match control bit.
#define TOG2    0x04    // Toggle control bit.
#define PWM2    0x02    // Pulse Width Modulation enable bit.
#define ECCF2   0x01    // Enable CCF0 interrupt.

#endif /* STC15W_PCA_PWM_H */