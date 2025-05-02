//-------------------------------------------------------------
// 24-Channel USB relay driver.
// Driver for the TPIC6B595 serial to parallel shift register.
// 
// Last updated: Dilshan Jayakody [3rd Feb 2023]
//
// Update log:
// [03/02/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#include "include/stc15.h"

#include "config.h"
#include "shiftreg.h"
#include "util.h"

void updateOutput(unsigned long *portConfig)
{
    unsigned char outBuffer[MAX_IO_COUNT/8];
    unsigned char spos, cpos;

    // Split output into three 8-bit chunks.
    outBuffer[0] = (*portConfig) & 0xFF;
    outBuffer[1] = ((*portConfig) >> 8) & 0xFF;
    outBuffer[2] = ((*portConfig) >> 16) & 0xFF;
    
    // Set shift register outputs to the specified value.
    cpos = 0;
    while(cpos < (MAX_IO_COUNT/8))
    {
        // Load 8-bit data into the shift register.
        spos = 7;
        while(spos != 0xFF)
        {
            // Reset clock and data pins to load the next available data bit.   
            P1 &= 0xE9;
            P1 |= ((outBuffer[cpos] & (1 << spos)) ? 0x10 : 0x00);
            delay10us();

            // Load data into shift register.
            P1 |= 0x02;
            delay10us();

            spos--;
        }

        // Move into next shift register.
        cpos++;
    }

    // Load data into output regsiter.
    P1 &= 0xE9;
    P1 |= 0x04;

    delay10us();
    delay10us();
    P1 &= 0xFB;
}