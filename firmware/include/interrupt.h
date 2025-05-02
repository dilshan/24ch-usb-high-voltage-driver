//-------------------------------------------------------------
// STC51 interrupt definition for SDCC.
// 
// Based on STC15series MCU Data Sheet - 2015/10/10.
// Last updated: Dilshan Jayakody [14th Jan 2021]
//
// Update log:
// [14/01/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#ifndef STC15W_INTERRUPT_H
#define STC15W_INTERRUPT_H

#define INT0_VECTOR	            0   // External Interrupt 0.
#define	TIMER0_VECTOR	        1   // Timer 0 Interrupt.
#define	INT1_VECTOR		        2   // External Interrupt 1.
#define	TIMER1_VECTOR	        3   // Timer 1 Interrupt.
#define	UART1_VECTOR	        4   // UART1 Interrupt.
#define	ADC_VECTOR		        5   // ADC Interrupt.
#define	LVD_VECTOR		        6   // Low Voltage Detection (LVD) Interrupt.
#define	PCA_VECTOR		        7   // CCP/PWM/PCA Interrupt.
#define	UART2_VECTOR	        8   // UART2 Interrupt.
#define	SPI_VECTOR		        9   // SPI Interrupt.
#define	INT2_VECTOR		        10  // External Interrupt 2.
#define	INT3_VECTOR		        11  // External Interrupt 3.
#define	TIMER2_VECTOR	        12  // Timer 2 Interrupt.
#define PWM_VECTOR              13  // PWM Interrupt ? (Documentation or reference not available).
#define	INT4_VECTOR		        16  // External Interrupt 4.
#define	UART3_VECTOR	        17  // UART3 Interrupt.
#define	UART4_VECTOR	        18  // UART4 Interrupt.
#define	TIMER3_VECTOR	        19  // Timer 3 Interrupt.
#define	TIMER4_VECTOR	        20  // Timer 4 Interrupt.
#define	COMPRATOR_VECTOR		21  // Comparator Interrupt.

// Interrupt Enable Rsgister (IE) bit definitions.
#define EA      0x80    // Enable all interrupts.
#define ELVD    0x40    // Low volatge detection interrupt enable bit.
#define EADC    0x20    // ADC interrupt enable bit.
#define ES      0x10    // UART1 interrupt enable bit.
#define ET1     0x08    // Timer 1 interrupt enable bit.
#define EX1     0x04    // External interrupt 1 enable bit.
#define ET0     0x02    // Timer 0 interrupt enable bit.
#define EX0     0x01    // External interrupt 0 enable bit.

// Interrupt Enable Rsgister 2 (IE2) bit definitions.
#define ET4     0x40    // Timer 4 interrupt enable bit.
#define ET3     0x20    // Timer 3 interrupt enable bit.
#define ES4     0x10    // UART4 interrupt enable bit.
#define ES3     0x08    // UART3 interrupt enable bit.
#define ET2     0x04    // Timer 2 interrupt enable bit.
#define ESPI    0x02    // SPI interrupt enalbe bit.
#define ES2     0x01    // UART2 interrupt enable bit.

// Interrupt Priority Register (IP) bit definitions.
#define PPCA    0x80    // PCA interrupt priority control bit.
#define PLVD    0x40    // Low voltage detection interrupt priority control bit.
#define PADC    0x20    // ADC interrupt priority control bit.
#define PS      0x10    // UART1 interrupt priority control bit.
#define PT1     0x08    // Timer 1 interrupt priority control bit.
#define PX1     0x04    // External interrupt 1 priority control bit.
#define PT0     0x02    // Timer 0 interrupt priority control bit.
#define PX0     0x01    // External interrupt 0 priority control bit.

// Interrupt Priority Register 2 (IP2) bit definitions.
#define PSPI    0x02    // SPI interrupt priority control bit.
#define PS2     0x01    // UART2 interrupt priority control bit.

#endif /* STC15W_INTERRUPT_H */