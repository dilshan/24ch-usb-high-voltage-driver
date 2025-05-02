//-------------------------------------------------------------
// 24-Channel USB relay driver.
// EEPROM support routines for STC15W204S.
//
// Last updated: Dilshan Jayakody [4th Feb 2023]
//
// Update log:
// [04/02/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#include "include/stc15.h"

#include "config.h"
#include "eeprom.h"

#define IAP_ADDRESS 0x0000

// IAP / EEPROM commands defined in STC datasheet.
#define IAP_CMD_IDLE    0x00
#define IAP_CMD_READ    MS0
#define IAP_CMD_WRITE   MS1
#define IAP_CMD_ERASE   MS0 | MS1

void eepromIdle()
{
    // Clear and close IAP functions.
    IAP_CONTR = 0;
    IAP_CMD = 0;
    IAP_TRIG = 0;

    // Point data pointer to non-EEPROM area.
    IAP_ADDRH = 0x80;
    IAP_ADDRL = 0;
}

unsigned char eepromReadByte(unsigned short address)
{
    unsigned char tempData;

    // Enter IAP into the read mode.
    IAP_CONTR = IAPEN | WT1;
    IAP_CMD = IAP_CMD_READ;
    
    // Select the specified address from IAP memory sector.
    IAP_ADDRL = address;
    IAP_ADDRH = address >> 8;

    // Initialize the EEPROM read operation.
    IAP_TRIG = 0x5A;
    IAP_TRIG = 0xA5;

    // Wait to finish the EEPROM read operation.
    nop();

    tempData = IAP_DATA;
    eepromIdle();

    return tempData;
}

void eepromWriteByte(unsigned short address, unsigned char data)
{
    // Enter IAP into the write mode.
    IAP_CONTR = IAPEN | WT1;
    IAP_CMD = IAP_CMD_WRITE;

    // Select the specified address from IAP memory sector.
    IAP_ADDRL = address;
    IAP_ADDRH = address >> 8;

    // Write IAP / EEPROM data into selected memory address.
    IAP_DATA = data;

    // Initialize the EEPROM write operation.
    IAP_TRIG = 0x5A;
    IAP_TRIG = 0xA5;

    // Wait to finish the EEPROM write operation.
    nop();
    eepromIdle();
}

void eepromEraseSector(unsigned short address)
{
    // Enter IAP into the erase mode.
    IAP_CONTR = IAPEN | WT1;
    IAP_CMD = IAP_CMD_ERASE;

    // Select the specified address from IAP memory sector.
    IAP_ADDRL = address;
    IAP_ADDRH = address >> 8;

    // Initialize the EEPROM erase operation.
    IAP_TRIG = 0x5A;
    IAP_TRIG = 0xA5;

    // Wait to finish the EEPROM erase operation.
    nop();
    eepromIdle();
}

void saveValueToEEPROM(unsigned long *value)
{
    // Erase the first sector of the EEPROM.
    eepromEraseSector(IAP_ADDRESS);

    // Write specified value into EEPROM.
    eepromWriteByte(IAP_ADDRESS, (unsigned char)((*value) & 0xFF));
    eepromWriteByte(IAP_ADDRESS + 1, (unsigned char)(((*value) >> 8) & 0xFF));
    eepromWriteByte(IAP_ADDRESS + 2, (unsigned char)(((*value) >> 16) & 0xFF));
    eepromWriteByte(IAP_ADDRESS + 3, (unsigned char)(((*value) >> 24) & 0xFF));
}

unsigned long loadValueFromEEPROM()
{
    unsigned long tempVal;

    // Load programmed value from the EEPROM.
    tempVal = eepromReadByte(IAP_ADDRESS);
    tempVal = tempVal | ((unsigned long)(eepromReadByte(IAP_ADDRESS + 1)) << 8);
    tempVal = tempVal | ((unsigned long)(eepromReadByte(IAP_ADDRESS + 2)) << 16);
    tempVal = tempVal | ((unsigned long)(eepromReadByte(IAP_ADDRESS + 3)) << 24);

    return (tempVal & MAX_IO_MASK);
}