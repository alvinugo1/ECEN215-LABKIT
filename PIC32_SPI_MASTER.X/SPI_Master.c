#include "SPI_Master.h"
#include "main.h"
#include "UART_main.h"
#include "UART_common.h"
#include "uart.h"

unsigned char dummy, stat, Data,hey,yo; 
unsigned char data1='a';
char receivedData[10]; 

void SPI_start(void)
{
    LATDbits.LATD4 = 0; 
}
void SPI_stop(void)
{ 
    LATDbits.LATD4 = 1; 
}
void poll(void)
{
   while(SPI1STATbits.SPITBF);
   while(!SPI1STATbits.SPIRBF); 
}
void SPI_Master_Init(void)
{
    /*
     * Chip Select = D4 
     * MISO = D14
     * MOSI = D3
     * SCK = D1 
     */
    ANSELD = 0;                     // Set portD as digital 
    TRISDbits.TRISD14 = 1;  
    TRISDbits.TRISD4 = 0;           // Chip select set to output.
    
    // PPS for SDI and SDO pins 
    SDI1Rbits.SDI1R = 0b1011;       // Set the SDI pin to RPD14
    RPD3Rbits.RPD3R = 0b0101;       // Set the RPD3R to SDO pin  
    
    //************** SPI1 Setup *******************//
      
    // Turn off all interrupts 
    IEC3bits.SPI1TXIE = 0;
    IEC3bits.SPI1RXIE = 0;
    IEC3bits.SPI1EIE = 0;
    
    SPI1CONbits.ON = 0;         // Turn off SPI  
    SPI1CONbits.ENHBUF = 0;     // turn off enhanced buffer mode
    
    // HS oscillator is 24MHz 
    SPI1BRG = 23; 
    
    SPI1CONbits.MODE16 = 0;     // 8-bit mode 
    SPI1CONbits.DISSDO = 0;     // Enable data out
    SPI1CONbits.SMP = 1;
    // Data being clocked from the rising edge of the SCK 
    SPI1CONbits.CKE = 1;       
    SPI1CONbits.CKP = 0;
    SPI1STATbits.SPIROV = 0;    // Clear overflow flag 
    SPI1CONbits.MSTEN = 1;      // Enable master mode. 
    SPI1CONbits.ON = 1;         // Enable SPI1 
}
void SPI_write(char Msg)
{
     //Writing data
    //SPI_start();
    
    SPI1BUF = Msg;              // the data byte
    poll();
    dummy = SPI1BUF;
    
    //SPI_stop();
    
}

void SPI_Slave_write(char msg)
{
    SPI1BUF = msg;              // the data byte
    poll();
    dummy = SPI1BUF;
}

unsigned char SPI_read(void)
{
    //reading data
    char msg; 
    //SPI_start();
    
    SPI1BUF = 0b00000000;       // dummy data
    poll();
    msg = SPI1BUF;
    
    //SPI_stop();
    return msg;
}
//unsigned char SPI_read_2(unsigned char num, char *buf)
//{
//    //reading data
//    //char msg;
//    int index;
//    SPI_start();
//    for (index = 0; index < num; index++) 
//    {
//        SPI1BUF = 0b00000000;       // dummy data
//        poll();
//        buf[index] = SPI1BUF;
//    }
//    SPI_stop();
//    return buf;
//}

/*void SPI_read(void)
{
    //reading data
    char msg[10]; 
    SPI_start();
    
    SPI1BUF = 0b0000000000000000000000000000000;       // dummy data
    poll();
    msg = SPI1BUF;
    
    SPI_stop();
    //return msg;
}*/

unsigned char SPI_Slave_read(void)
{
    //reading data
    SPI1BUF = 0b00000000;       // dummy data
    poll();
    return SPI1BUF;
}
void SPI_writeRead(void)
{
    //Writing data
    
    SPI_start();
    SPI1BUF = data1;              // the data byte
    poll();
    dummy = SPI1BUF;

    SPI1BUF = 0b00000000;       // dummy data
    poll();
    Data = SPI1BUF;
    printf("%c", Data);
    SPI_stop();
}

void SPI_ReadWString(char *arrayData, int length){
   int i = 0;
   SPI_start();
   for(i = 0; i<length; i++){
       //data1 = arrayData[i];
       SPI_write(arrayData[i]);
       receivedData[i] = SPI_read();
       
   }
   printf("%s", receivedData);
   SPI_stop();
  
  }
 
 