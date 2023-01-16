#include "main.h"
#include "common.h"
#include "uart.h"

uint8_t ch;
char buffer[100] = "PyC32MZ UART Demo" ;
char buff[100] = "here!";




void I2C_Master_Init(void);
void I2C_start(void);
void I2C_write(void);
void I2C_stop(void);
void I2C_writeRead1(void);
void I2C_writeReadN(void);
char data[10];

void main(void) {
    
    configPerformance();
    
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;
    ANSELF = 0;
    ANSELG = 0;
    //ANSELH = 0;    
    //ANSELJ = 0;     
    
    //TRISHbits.TRISH2 = 0; //LED output  
    TRISGbits.TRISG12 = 1;
    
    I2C_Master_Init();
    UART_config();
    I2C_start();
    I2C_writeReadN();
    I2C_stop();
    while(1)
    {   
        //UART_puts(buff);
        while(PORTGbits.RG12); // wait until the button is pressed
        while(!PORTGbits.RG12); // wait until the button is released
        //I2C_start();
        //I2C_writeReadN();
        //I2C_stop();
        //printf("%c", data);
        UART_puts(data);
    }
    
    

}

void _mon_putc (char c)
{
    UART_putch(c);
}

void I2C_Master_Init(void)
{
    // turn on I2C1 
    I2C2CONbits.ON = 1;
    
    // Set to 7-bit addressing mode
    I2C2CONbits.A10M = 0;
    
    // set baudrate to 100kHz 24MHz EC oscillator
    I2C2BRG = 117;
    
}
void I2C_start(void)
{
    
    // Start 
    I2C2CONbits.SEN = 1; 
    
    //wait until start is finished 
    while(I2C2CONbits.SEN);
}

void I2C_write(void)
{
      //24LC02B address 1010xxx
    //load I2C1TRN with 1010 - address, 000 - don't care, '0' - means write
    I2C2TRN = 0b10100000;
    
    // wait until finish transmit
    while(I2C2STATbits.TRSTAT);
    
    // transmit data (a)
    I2C1TRN = 0b01100001;  
    while(I2C2STATbits.TRSTAT);

}

void I2C_writeRead1(void)
{   
    int c = 0;
    //UART_puts(buffer); 
    I2C2TRN = 0b00010001;
    //UART_puts(buffer); 
    while(I2C2STATbits.TRSTAT); 
    //UART_puts(buffer);
    I2C2CONbits.RCEN = 1;       // Enable recieve
    //UART_puts(buffer);
    while(I2C2CONbits.RCEN );   // wait until recieve is finished
    //UART_puts(buffer);
    I2C2CONbits.ACKEN  = 1;     // sends ack 
    //UART_puts(buffer);
    while(I2C2CONbits.ACKEN);    // wait until the ack is cleared
    //UART_puts(buffer);
     // transmit NACK 
    I2C2CONbits.ACKDT = 1;  
    //UART_puts(buffer);
    data[0] = I2C2RCV;          // empty recieve buffer
    //UART_puts(buffer);
    while(I2C2STATbits.RBF);    // wait until buffer is cleared
    //printf("%c", data);
    UART_puts(data); 
    
}

void I2C_writeReadN(void){
    int c = 0; 
    int num = 6; 
    
    I2C2TRN = 0b00010001; // Arduino address
    while(I2C2STATbits.TRSTAT); 
    
    int i = 0; 
    while( i < num){
        I2C2CONbits.RCEN = 1; // enable receive 
        while(I2C2CONbits.RCEN ); //wait until receive is finished 
        
        if(i == num-1){
            I2C2CONbits.ACKDT = 1; //send NACK on last byte reception 
        
        }
        I2C2CONbits.ACKEN  = 1;  //send ACK
        while(I2C2CONbits.ACKEN); //wait until the ack is cleared
        
        data[i] = I2C2RCV;     // empty recieve buffer
        while(I2C2STATbits.RBF); //wait until buffer is cleared 
        
        i++; 
    }
    


}

void I2C_stop(void)
{   
    // send stop bits 
    I2C2CONbits.PEN = 1;
    // wait until the stop bits is sent 
    while(I2C2CONbits.PEN);
}