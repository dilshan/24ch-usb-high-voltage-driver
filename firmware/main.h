//-------------------------------------------------------------
// 24-Channel USB relay driver.
// 
// Last updated: Dilshan Jayakody [3rd Feb 2023]
//
// Update log:
// [03/02/2021] - Initial version - Dilshan Jayakody.
//-------------------------------------------------------------

#ifndef USB_RELAY_CARD_MAIN
#define USB_RELAY_CARD_MAIN

#define RX_BUFFER_SIZE  14
#define TX_BUFFER_SIZE  10

static unsigned char rxDataPos, txDataPos;
static unsigned char commandReady, outputReady;
static unsigned char rxBuffer[RX_BUFFER_SIZE];
static unsigned char txBuffer[TX_BUFFER_SIZE];
static unsigned char data;

unsigned long output, tempOutput;

void returnStatusMsg(unsigned char *status);
void changeOutput(void);
void returnVersion(void);
void initSystem(void);

#endif /* USB_RELAY_CARD_MAIN */