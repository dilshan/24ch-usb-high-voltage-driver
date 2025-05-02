//-------------------------------------------------------------
// 24-Channel USB relay driver.
// Common utility functions for STC15W204S MCU.
//
// Last updated: Dilshan Jayakody [3rd Feb 2023]
//
// Update log:
// [03/02/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#ifndef USB_RELAY_CARD_UTIL
#define USB_RELAY_CARD_UTIL

void delay10us();
void freeStr(unsigned char *inStr, const unsigned char strMaxLen);
unsigned char strToLong(unsigned char *inStr, unsigned long *outValue, const unsigned char strMaxLen);
unsigned char longToStr(unsigned long *inValue, unsigned char *outStr);

#endif /* USB_RELAY_CARD_UTIL */