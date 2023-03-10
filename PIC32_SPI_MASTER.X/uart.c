#include "uart.h"
#include "SPI_Master.h"
#include "main.h"
/* UART FUNCTION DEFINITIONS */

void UART_config(void) {
            
    /* PPS remap tx, rx pins */
    U2RXR = 0x0C; //rx pin PC3
    RPC2R = 0x02; //tx pin PC2
    TRISCbits.TRISC3 = 1; // Make PC3 an input
    ANSELCbits.ANSC3 = 0;
    
    U2BRG = (_XTAL_FREQ / 2 / 4 / BAUDRATE) - 1; // UxBRG(HIGH SPEED) = Fpb / 4 / Baudrate - 1
    
    U2MODEbits.BRGH = 1; //high speed mode
    U2MODEbits.PDSEL = 0; //8bit no parity
    U2MODEbits.STSEL = 0; //1 stop bit       
        
    U2STAbits.URXEN = 1; //enable receiver
    U2STAbits.UTXEN = 1; //enable transmitter    
    
    U2MODEbits.ON = 1; //enable
   
}

void UART_putch(uint8_t ch) {
    while (U2STAbits.UTXBF); //wait buffer empty
    U2TXREG = ch; //transmit
}

void UART_puts(char *str) {
    while (*str) {
        UART_putch(*str);
        str++;
    }
}

uint8_t UART_getch(void) {
    while (!U2STAbits.URXDA); //wait rx data available
    if(U2STAbits.OERR)
    {
        U2STAbits.OERR = 0; //clear overrun error manually
    }
    
    return U2RXREG;
}

void UART_gets(char *str, uint16_t len) {
    int i;
    
    for (i = 0; i < len; i++) {
        str[i] = UART_getch();
    }
}

void readUART(char * message, int maxLength){ 
  char c = 'i';  
  
  char data = 0;
  int complete = 0, num_bytes = 0;
  // loop until you get a '\r' or '\n'
  while (!complete) {
    
    if (U2STAbits.URXDA) { // if data is available
      data = U2RXREG;      // read the data
      if ((data == '\n') || (data == '\r')) {
        complete = 1;
      } else {
        message[num_bytes] = data;
        ++num_bytes;
        // roll over if the array is too small
        if (num_bytes >= maxLength) {
          num_bytes = 0;
        }
      }
    }
  }
  // end the string
  message[num_bytes] = '\0';
}