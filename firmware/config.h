//-------------------------------------------------------------
// 24-Channel USB relay driver.
// System configuration.
// 
// Last updated: Dilshan Jayakody [4th Feb 2023]
//
// Update log:
// [04/02/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#ifndef USB_RELAY_CARD_CONFIG
#define USB_RELAY_CARD_CONFIG

// Number of relay terminals.
#define MAX_IO_COUNT    24

// Maximum allowed number from the host terminal.
// This value is related to MAX_IO_COUNT.
#define MAX_IO_MASK     0xFFFFFF

#endif /* USB_RELAY_CARD_CONFIG */