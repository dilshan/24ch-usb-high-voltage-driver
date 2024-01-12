//-------------------------------------------------------------
// 24-Channel USB relay driver.
// 
// Last updated: Dilshan Jayakody [3rd Feb 2023]
//
// Update log:
// [03/02/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#include "include/stc15.h"

#include "config.h"
#include "main.h"
#include "shiftreg.h"
#include "util.h"
#include "eeprom.h"

void UART_ISR(void) __interrupt(UART1_VECTOR) __using(1)
{
    IE &= ~(ES);

    if(SCON & RI)
    {
        // Receive interrupt flag has raised.
        SCON &= ~(RI);
        data = SBUF;

        // Ignore line feed character.
        if(data != 10)
        {
            if(data == 13)
            {
                // Execute command on carriage return.
                commandReady = 1;
            }        
            else if((rxDataPos < RX_BUFFER_SIZE) && (commandReady == 0))
            {
                // Fill command buffer.
                rxBuffer[rxDataPos++] = data;
            }
        }
    }

    if(SCON & TI)
    {
        // Transmit interrupt flag has raised.
        SCON &= ~(TI);

        if(txDataPos > 0)
        {
            SBUF = txBuffer[--txDataPos];
        }
    }

    IE |= ES;
}

// Main application entrypoint.
void main()
{	
	initSystem();

    // Free input data buffer.
    freeStr(rxBuffer, RX_BUFFER_SIZE);

    // Load default configuration based on jumper setting.
    if((P3 & 0x04) == 0x00)
    {
        // Load saved configuration from EEPROM and apply to output.
        output = loadValueFromEEPROM();
        updateOutput(&output);
    }

    // Main service loop.
    while(1)
    {
        if(commandReady)
        {
            outputReady = 0;
            tempOutput = 0;

            // Looking for ON or OFF command.
            if(rxBuffer[0] == 'O')
            {
                if((rxBuffer[1] == 'N') && (rxBuffer[2] == '='))
                {
                    // Received ON command from the host.
                    outputReady = strToLong((rxBuffer + 3), &tempOutput, RX_BUFFER_SIZE);

                    // Only up to 24 positions are allowed for ON commands.
                    if(tempOutput > MAX_IO_MASK)
                    {
                        outputReady = 0;
                    }
                    
                    tempOutput = tempOutput | output;
                }
                else if((rxBuffer[1] == 'F') && (rxBuffer[2] == 'F') && (rxBuffer[3] == '='))
                {
                    // Received OFF command from the host.
                    outputReady = strToLong((rxBuffer + 4), &tempOutput, RX_BUFFER_SIZE);

                    // Only up to 24 positions are allowed for OFF commands.
                    if(tempOutput > MAX_IO_MASK)
                    {
                        outputReady = 0;
                    }

                    tempOutput = output & (~tempOutput);
                }

                changeOutput();
            }
            else if((rxBuffer[0] == 'G') && (rxBuffer[1] == 'E') && (rxBuffer[2] == 'T'))
            {
                // Receive GET command from the host terminal.
                // Convert output value to string.
                txDataPos = longToStr(&output, txBuffer);
                txDataPos++;
                
                // Send message to the host terminal.                
                SCON |= TI;
            }
            else if((rxBuffer[0] == 'T') && (rxBuffer[1] == 'O') && (rxBuffer[2] == 'G') && (rxBuffer[3] == '='))
            {
                // Received TOG command from the host.
                outputReady = strToLong((rxBuffer + 4), &tempOutput, RX_BUFFER_SIZE);

                // Only up to 24 positions are allowed for OFF commands.
                if(tempOutput > MAX_IO_MASK)
                {
                    outputReady = 0;
                }

                tempOutput = tempOutput ^ output;
                changeOutput();
            }
            else if((rxBuffer[0] == 'C') && (rxBuffer[1] == 'L') && (rxBuffer[2] == 'R'))
            {
                // Receive CLR command from the host terminal.
                tempOutput = 0;
                outputReady = 1;
                changeOutput();
            }
            else if((rxBuffer[0] == 'S') && (rxBuffer[1] == 'T') && (rxBuffer[2] == 'R'))
            {
                // Receive STR command from the host terminal.
                saveValueToEEPROM(&output);

                // Save current relay terminal configuration into EEPROM.
                outputReady = 1;
                returnStatusMsg(&outputReady);
            }
            else if((rxBuffer[0] == 'V') && (rxBuffer[1] == 'E') && (rxBuffer[2] == 'R'))
            {
                // Receive VER command from the host terminal.
                returnVersion();
            }
            else
            {
                // Unknown command from the host terminal.
                returnStatusMsg(&outputReady);
            }

            // Free input data buffer.
            freeStr(rxBuffer, RX_BUFFER_SIZE);

            // Clear flags and reset counter to capture the next incoming command from the host.
            outputReady = 0;
            rxDataPos = 0;
            commandReady = 0;
        }
        else
        {
            // Commands are not available from host.
            delay10us();
        }
    }   
}

void changeOutput()
{
    // Check flag to change the relay output(s).
    if(outputReady)
    {
        // Update relay positions and status variable.
        tempOutput = tempOutput & MAX_IO_MASK;
        updateOutput(&tempOutput);
        output = tempOutput;
    }

    // Notify command status to the host terminal.
    returnStatusMsg(&outputReady);
}

void returnVersion()
{
    txBuffer[8] = 'E';
    txBuffer[7] = 'L';
    txBuffer[6] = 'E';
    txBuffer[5] = 'C';
    txBuffer[4] = 'T';
    txBuffer[3] = '1';
    txBuffer[2] = '0';

    txBuffer[1] = 10;
    txBuffer[0] = 13;
    txDataPos = 9; 

    // Send message to the host terminal.
    SCON |= TI;
}

void returnStatusMsg(unsigned char *status)
{
    if(*status)
    {
        // Send 'OK' if the status is TRUE.
        txBuffer[3] = 'O';
        txBuffer[2] = 'K';

        txBuffer[1] = 10;
        txBuffer[0] = 13;
        txDataPos = 4;        
    }
    else
    {
        // Send 'FAIL' if the status is FALSE.
        txBuffer[5] = 'F';
        txBuffer[4] = 'A';
        txBuffer[3] = 'I';
        txBuffer[2] = 'L';

        txBuffer[1] = 10;
        txBuffer[0] = 13;
        txDataPos = 6; 
    }

    // Send message to the host terminal.
    SCON |= TI;
}

void initSystem()
{
	// P1.0 [OUT] : Shift register - ~RESET
    // P1.1 [OUT] : Shift register - SHIFT-CLOCK
    // P1.2 [OUT] : Shift register - LATCH-CLOCK
    // P1.3 [OUT] : Shift register - ~OUTPUT-ENABLE
    // P1.4 [OUT] : Shift register - DATA
    P1M1 = 0x00;
    P1M0 = 0xFF;
    P1 = 0x08;

    // P3.0 [IN]  : Serial RxD.
    // P3.1 [OUT] : Serial TxD.
    // P3.2 [IN]  : Startup configuration jumper.
    P3M1 = P3M1 | 0x04;
    P3M0 = P3M0 & 0xFB;
    P3 = P3 | 0x04;

    // Stop TIMER2.
    AUXR &= ~(T2R);

    // Setup UART port as 9600-baud with 8N1. User TIMER2 as baud rate generator.
    AUXR1 &= ~(S1_S1 | S1_S0);
    SCON &= ~(SM0);
    SCON |= (SM1 | REN);
    AUXR |= S1ST2;                    

    // Set baud rate as 9600.
    T2L = 0xE0;
    T2H = 0xFE;
    AUXR &= ~(T2CT); 
    AUXR |= T2_12; 

    // Set interrupts related to UART.
    IP |= PS;                           
    SCON &= ~(TI | RI);                
    IE |= (EA | ES); 

    // Initialize global variables.
    rxDataPos = 0;
    txDataPos = 0;
    commandReady = 0;
    outputReady = 0;
    output = 0;

    // Start TIMER2 to activate the UART.
    AUXR |= T2R;

    // Start shift register from reset.
    P1 = 0x01;
}