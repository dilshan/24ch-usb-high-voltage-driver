//-------------------------------------------------------------
// 24-Channel USB relay driver.
// Driver for the TPIC6B595 serial to parallel shift register.
// 
// Last updated: Dilshan Jayakody [3rd Feb 2023]
//
// Update log:
// [03/02/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#ifndef USB_RELAY_CARD_SHIFT_REG
#define USB_RELAY_CARD_SHIFT_REG

void updateOutput(unsigned long *portConfig);

#endif /* USB_RELAY_CARD_SHIFT_REG */