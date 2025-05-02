//-------------------------------------------------------------
// 24-Channel USB relay driver.
// EEPROM support routines for STC15W204S.
//
// Last updated: Dilshan Jayakody [4th Feb 2023]
//
// Update log:
// [04/02/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#ifndef USB_RELAY_CARD_EEPROM
#define USB_RELAY_CARD_EEPROM

void saveValueToEEPROM(unsigned long *value);
unsigned long loadValueFromEEPROM();

#endif /* USB_RELAY_CARD_EEPROM */