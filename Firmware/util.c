//-------------------------------------------------------------
// 24-Channel USB relay driver.
// Common utility functions for STC15W204S MCU.
//
// Last updated: Dilshan Jayakody [3rd Feb 2023]
//
// Update log:
// [03/02/2021] - Initial version - Dilshan Jayakody.
//--------------------------------------------------------------

#include "include/stc15.h"

#include "util.h"

void delay10us()
{
    unsigned char pos = 25;
    nop();
    while(--pos);
}

void freeStr(unsigned char *inStr, const unsigned char strMaxLen)
{
    char strPos;

    for(strPos = 0; strPos < strMaxLen; strPos++)
    {
        inStr[strPos] = 0;
    }
}

unsigned char strToLong(unsigned char *inStr, unsigned long *outValue, const unsigned char strMaxLen)
{
    char strPos = 0;
    unsigned long intPos = 1;
    
    // Searching for null to determine the length of the specified string.
    while(strPos < strMaxLen)
    {
        if(inStr[strPos] == 0)
        {
            // Found null character.
            strPos--;
            break;
        }
        
        strPos++;
    }
    
    // If null is not found terminate the conversion.
    if(strPos == strMaxLen)
    {
        // Specified buffer is NOT a null terminated string!
        return 0;
    }
    
    while(strPos != 0xFF)
    {
        if((inStr[strPos] > 47) && (inStr[strPos] < 58))
        {
            // Convert each digit to integer and construct the number.
            (*outValue) = (*outValue) + (intPos * (inStr[strPos] - 48));
        }
        else
        {
            // Found an invalid character. This function except string buffer which contains only a numbers [0-9].
            return 0;
        }
        
        strPos--;

        // Increase the 10th position.
        intPos = intPos * 10;
    }
    
    // Conversion is successful.
    return 1;
}

unsigned char longToStr(unsigned long *inValue, unsigned char *outStr)
{
    unsigned long tempValue = (*inValue);
    unsigned char strPos = 2, len = 1;

    // Find the length of the specified number.
    while(tempValue > 10)
    {
        tempValue = tempValue / 10;
        len++;
    }

    tempValue = (*inValue); 
    len--;

    // Convert each digit to a character.
    while((len--) != 0xFF)
    {
        outStr[strPos] = (tempValue % 10) + 48;
        tempValue = tempValue / 10;
        strPos++;
    }

    // Set null character at the end of the string buffer.
    outStr[strPos] = 0; 

    // Set CR and LF characters at the beginning of the string to get
    // compatible with UART transmission buffer.
    outStr[1] = 10;
    outStr[0] = 13;
    
    return strPos;
}