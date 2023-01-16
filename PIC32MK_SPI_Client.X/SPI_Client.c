#include "SPI_Client.h"
#include "main.h"

char dummy, stat, data; 
int length; 
char arrayData[100];
char dac[100] = "Blvin"; //Dummy data 
int receiveMode=1;
void poll(void)
{
   while(SPI6STATbits.SPITBF); // while Transmit buffer full 
   while(!SPI6STATbits.SPIRBF); // While Receive buffer full
}
void SPI_Client_Init(void)
{
    /*Pin Configuration
     * CS - RC0 
     * SCK - RA1
     * MISO - RG9
     * MOSI - RB0 
     */
    
    // Chip Select
    /*edited here set back to zero*/
    TRISCbits.TRISC0 = 0;   // Set as output
    ANSELCbits.ANSC0 = 0;   // Set as digital 

    //MISO 
    TRISGbits.TRISG9 = 1;   // set as input
    ANSELGbits.ANSG9 = 0;    // set as analog
    
    //MOSI 
    TRISBbits.TRISB0 = 0;   // set as output 
    ANSELBbits.ANSB0 = 0;    // set as output
    
    //SCK
    TRISAbits.TRISA1 = 1; 
    ANSELAbits.ANSA1 = 0;
    
    /*Peripheral Pin Select*/
    SCK6Rbits.SCK6R = 0b0000; 

    SDI6Rbits.SDI6R = 0b1010; 
    RPB0Rbits.RPB0R = 0b10001;
    
    /*Disable Interrupts*/
    IEC7bits.SPI6EIE =0;
    IEC7bits.SPI6RXIE=0; 
    IEC7bits.SPI6TXIE=0;
    SPI6CON = 0;

    /*SPI6 Configuration*/
    SPI6CONbits.ON = 0;         // Turn off SPI  
    SPI6CONbits.ENHBUF = 0;     // turn off enhanced buffer mode
    SPI6CONbits.MODE16 = 0;     // 8-bit mode 
    SPI6CONbits.DISSDO = 0;     // Enable data out
    SPI6CONbits.SMP = 0;
    // Data being clocked from the rising edge of the SCK 
    SPI6CONbits.CKE = 1;       
    SPI6CONbits.CKP = 0;
    SPI6STATbits.SPIROV = 0;    // Clear overflow flag 
    SPI6CONbits.MSTEN = 0;      // clear master master mode. 
//
    SPI6CONbits.SRXISEL = 1;    // Interrupt when buffer is not empty
    IEC7bits.SPI6RXIE =1;
    IPC57bits.SPI6RXIP = 5;     // Set SPIRX interrupt priority to 7 
    IPC57bits.SPI6RXIS = 3;     // Set SPIRX sub-priority to 3 
    IFS7bits.SPI6RXIF = 0;   // clear the interrupt flag 
    SPI6CONbits.ON = 1;         // Enable SPI6
    
}
void SPI_readWrite(void)
{  
    //function for reading and writing simultaneously; Not used in main file 
    SPI6BUF = 0b00000000; // Dummy data sent 
    while(SPI6STATbits.SPITBF); // while Transmit buffer full
    while(!SPI6STATbits.SPIRBF); // while Receive buffer full
    data = SPI6BUF;

    data = data+1; 
    SPI6BUF = data;
    while(SPI6STATbits.SPITBF);
    while(!SPI6STATbits.SPIRBF);
    dummy = SPI6BUF;

}
//void SPI_Slave_write(char msg)
//{
//    char dummy;
//    SPI6BUF = msg;              // the data byte sent to buffer
//    poll();
//    //while(!SPI6STATbits.SPIRBF);
//    dummy = SPI6BUF; 
//}

unsigned char SPI_Slave_read(void)
{
    //reading data
    SPI6BUF = 0b00000000;       // dummy data sent to buffer
    poll();
    return SPI6BUF;
}


void __ISR(_SPI6_RX_VECTOR,IPL5AUTO) SPI_RX_Handler(void)
{      
    //Interrupt service routine to negate need of CS pin 
    data= SPI6BUF;
    SPI6BUF = data;
    IFS7bits.SPI6RXIF = 0;   // clear the interrupt flag
    
}


void SPI_Write_String(char *arrayData, int length){
    int i = 0;
    //while(PORTCbits.RC0); // for polling function; Create dependence on CS Pin 
    
    //Loops through each byte and writes to buffer to be received by master
    for(i = 0; i<length; i++){
        
        SPI_Slave_write(arrayData[i]);
    }
    //while(PORTCbits.RC0);
  }

void SPI_Slave_write(char msg)
{
    char dummy;
    SPI6BUF = msg;              // the data byte sent to buffer
    poll();
    //while(!SPI6STATbits.SPIRBF);
    dummy = SPI6BUF; 
}



////////////////////////////////////// Commented Funtions, Ignore ///////////////////////////////////////////////////////

/*
void SPI_Write_String(char *arrayData){
   while (*arrayData) {
        SPI_Slave_write(*arrayData);
        arrayData++;
    }
  }
*/
 
/*
void SPI_Write_String(char *arrayData, int length){
    int i = 0;
    
    for(i = 0; i<length; i++){
        SPI_RX_Handler(arrayData[i]);
    }
  }
 */

//
//void UART_config(void) {
//            
//    /* PPS remap tx, rx pins */
//    U2RXR = 0x0C; //rx pin PC3
//    RPC2R = 0x02; //tx pin PC2
//    TRISCbits.TRISC3 = 1; // Make PC3 an input
//    ANSELCbits.ANSC3 = 0;
//    
//    U2BRG = (_XTAL_FREQ / 2 / 4 / BAUDRATE) - 1; // UxBRG(HIGH SPEED) = Fpb / 4 / Baudrate - 1
//    
//    U2MODEbits.BRGH = 1; //high speed mode
//    U2MODEbits.PDSEL = 0; //8bit no parity
//    U2MODEbits.STSEL = 0; //1 stop bit       
//        
//    U2STAbits.URXEN = 1; //enable receiver
//    U2STAbits.UTXEN = 1; //enable transmitter    
//    
//    U2MODEbits.ON = 1; //enable
//   
//}
//
//void UART_putch(uint8_t ch) {
//    while (U2STAbits.UTXBF); //wait buffer empty
//    U2TXREG = ch; //transmit
//}
//
//void UART_puts(char *str) {
//    while (*str) {
//        UART_putch(*str);
//        str++;
//    }
//}
//
//uint8_t UART_getch(void) {
//    //uint8_t co = "i";
//    //uint8_t ca = "j";
//    //UART_putch(co);
//    while (!U2STAbits.URXDA); //wait rx data available
//    //UART_putch(ca);
//    if(U2STAbits.OERR)
//    {
//        U2STAbits.OERR = 0; //clear overrun error manually
//    }
//    
//    return U2RXREG;
//}
//
//void UART_gets(char *str, uint16_t len) {
//    int i;
//    
//    for (i = 0; i < len; i++) {
//        str[i] = UART_getch();
//    }
//}
//
//void readUART(char * message, int maxLength){ 
//  char c = 'i';  
//  
//  char data = 0;
//  int complete = 0, num_bytes = 0;
//  // loop until you get a '\r' or '\n'
//  while (!complete) {
//    //printf("%c", c);
//    if (U2STAbits.URXDA) { // if data is available
//      //printf("%c", c);
//      data = U2RXREG;      // read the data
//      //UART_putch(data);
//      if ((data == '\n') || (data == '\r')) {
//        complete = 1;
//      } else {
//        message[num_bytes] = data;
//        ++num_bytes;
//        // roll over if the array is too small
//        if (num_bytes >= maxLength) {
//          num_bytes = 0;
//        }
//      }
//    }
//  }
//  //printf("num of bytes is %d", num_bytes);
//  //printf("message is %s", message);
//  // end the string
//  message[num_bytes] = '\0';
//  //printf("message is %s", message);
//  //printf("%c", c);
//}

/*
void __ISR(_SPI6_RX_VECTOR,IPL5AUTO) SPI_RX_Handler(void)
{      
    data= SPI6BUF;
    SPI6BUF = 0b01010100; 
    IFS7bits.SPI6RXIF = 0;   // clear the interrupt flag  
}
*/