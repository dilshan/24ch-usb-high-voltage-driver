//-------------------------------------------------------------
// STC51 IAP/ISP definitions for SDCC.
// 
// Based on STC15series MCU Data Sheet - 2015/10/10.
// Last updated: Dilshan Jayakody [4th Feb 2023]
//
// Update log:
// [14/01/2021] - Initial version - Dilshan Jayakody.
// [04/02/2023] - Add IAP command register bit definitions.
//-------------------------------------------------------------

#ifndef STC15W_IAP_ISP_H
#define STC15W_IAP_ISP_H

// IAP / EEPROM (IAP_CONTR) bit definitions.
#define IAPEN       0x80    // ISP/IAP operation enable.
#define SWBS        0x40    // Software boot selection control bit.
#define SWRST       0x20    // Software reset trigger control.
#define CMD_FAIL    0x10    // Command Fail indication for ISP/IAP operation.
#define WT2         0x04    // Waiting time selection (for flashing) bit 2.
#define WT1         0x02    // Waiting time selection (for flashing) bit 1.
#define WT0         0x01    // Waiting time selection (for flashing) bit 0.

// IAP / EEPROM command register (IAP_CMD) bit definitions.
#define MS1         0x02    // IAP operating mode bit 1.
#define MS0         0x01    // IAP operating mode bit 0.

#endif /* STC15W_IAP_ISP_H */