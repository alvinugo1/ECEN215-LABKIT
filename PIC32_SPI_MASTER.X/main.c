/*
;*******************************************************************************;
;                 CODE OWNERSHIP AND DISCLAIMER OF LIABILITY                    ;
;                                                                               ;
; Microchip Technology Incorporated ("Microchip") retains all ownership and     ;
; intellectual property rights in the code accompanying this message and in all ;
; derivatives hereto.  You may use this code, and any derivatives created by    ;
; any person or entity by or on your behalf, exclusively with Microchip?s       ;
; proprietary products.  Your acceptance and/or use of this code constitutes    ;
; agreement to the terms and conditions of this notice.                         ;
;                                                                               ;
; CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS". NO           ;
; WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED ;
; TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A ;
; PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP?S       ;
; PRODUCTS,COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.      ;
;                                                                               ;
; YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE,       ;
; WHETHER IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF        ;
; STATUTORY DUTY), STRICT LIABILITY, INDEMNITY,CONTRIBUTION, OR OTHERWISE, FOR  ;
; ANY INDIRECT, SPECIAL, PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, ;
; DAMAGE, FOR COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE CODE,       ;
; HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR    ;
; THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW,         ;
; MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED; TO THIS CODE,   ;
; SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO     ;
; HAVE THIS CODE DEVELOPED.                                                     ;
;                                                                               ;
; You agree that you are solely responsible for testing the code and determining;
; its suitability.  Microchip has no obligation to modify, test, certify, or    ;
; support the code.                                                             ;
;*******************************************************************************;
*//*
// DEVCFG3
#pragma config USERID = 0xFFFF          // Enter Hexadecimal value (Enter Hexadecimal value)
#pragma config FMIIEN = ON              // Ethernet RMII/MII Enable (MII Enabled)
#pragma config FETHIO = ON              // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config PGL1WAY = ON             // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
#pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config FUSBIDIO = ON            // USB USBID Selection (Controlled by the USB Module)

// DEVCFG2
#pragma config FPLLIDIV = DIV_3         // System PLL Input Divider (8x Divider)
#pragma config FPLLRNG = RANGE_5_10_MHZ// System PLL Input Range (34-68 MHz Input)
#pragma config FPLLICLK = PLL_POSC      // System PLL Input Clock Selection (POSC is input to the System PLL)
#pragma config FPLLMULT = MUL_50       // System PLL Multiplier (PLL Multiply by 128)
#pragma config FPLLODIV = DIV_2        // System PLL Output Clock Divider (32x Divider)
#pragma config UPLLFSEL = FREQ_24MHZ    // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

// DEVCFG1
#pragma config FNOSC = POSC             // Oscillator Selection Bits (Primary Osc (HS,EC))
#pragma config DMTINTV = WIN_127_128    // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Disable SOSC)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = EC            // Primary Oscillator Configuration (HS osc mode)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FCKSM = CSECME           // Clock Switching and Monitor Selection (Clock Switch Enabled, FSCM Enabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WDTSPGM = STOP           // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config WINDIS = NORMAL          // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled)
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window size is 25%)
#pragma config DMTCNT = DMT31           // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config FDMTEN = OFF             // Deadman Timer Enable (Deadman Timer is disabled)

// DEVCFG0
#pragma config DEBUG = OFF             // Background Debugger Enable (Debugger is disabled)
#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
#pragma config ICESEL = ICS_PGx2       // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config TRCEN = ON               // Trace Enable (Trace features in the CPU are enabled)
#pragma config BOOTISA = MIPS32         // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config FECCCON = OFF_UNLOCKED   // Dynamic Flash ECC Configuration (ECC and Dynamic ECC are disabled (ECCCON bits are writable))
#pragma config FSLEEP = OFF             // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config DBGPER = PG_ALL          // Debug Mode CPU Access Permission (Allow CPU access to all permission regions)
#pragma config SMCLR = MCLR_NORM        // Soft Master Clear Enable bit (MCLR pin generates a normal system Reset)
#pragma config SOSCGAIN = GAIN_2X       // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config SOSCBOOST = ON           // Secondary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config POSCGAIN = GAIN_2X       // Primary Oscillator Gain Control bits (2x gain setting)
#pragma config POSCBOOST = ON           // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config EJTAGBEN = NORMAL        // EJTAG Boot (Normal EJTAG functionality)

// DEVCP0
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

// SEQ3
#pragma config TSEQ = 0xFFFF            // Boot Flash True Sequence Number (Enter Hexadecimal value)
#pragma config CSEQ = 0xFFFF            // Boot Flash Complement Sequence Number (Enter Hexadecimal value)
*/
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include "main.h"
#include "SPI_Master.h"
#include "UART_main.h"
#include "UART_common.h"
#include "uart.h"
#include "string.h"

/*
 * 
 */

void DELAY(unsigned int ms)
{
    for(int i=0; i<ms; i++ ){
        for(int j=0;j<1000; j++ );
    }
}
uint8_t ch;
char buffer[100] = "PIC32MZ 403 Demo" ;

/* I2C Function calls */
void I2C_Master_Init(void);
void I2C_start(void);
void I2C_write(void);
void I2C_stop(void);
void I2C_writeRead1(void);
void I2C_writeReadN(void);

/* varaible initializations and definitions */
char data[10];
char get[10];
char plix[10] = "1";
char recdata[10]; 
uint8_t message; 
char cha[10];
char che[] = "abcdef"; 



int main(int argc, char** argv) {
    LATDbits.LATD4 = 1;             
    SPI_Master_Init();
    I2C_Master_Init();
    UART_config();
    TRISGbits.TRISG12 = 1; 
    I2C_start();
    I2C_writeReadN();
    I2C_stop();
    
    printf("%s", buffer); 
    while(1){
        
        readUART(cha, 4); 
        if(!strcmp(cha , "SPI\0")){
            SPI_ReadWString(che,5);
        }
        
        else if(!strcmp(cha , "I2C\0")){
            UART_puts(data);
        }
    }
    return (0);
}

void _mon_putc (char c)
{
    UART_putch(c);
}

/* I2C function definitions */
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
    I2C2TRN = 0b00010001;
    while(I2C2STATbits.TRSTAT); 
    I2C2CONbits.RCEN = 1;       // Enable recieve
    while(I2C2CONbits.RCEN );   // wait until recieve is finished
    I2C2CONbits.ACKEN  = 1;     // sends ack 
    while(I2C2CONbits.ACKEN);    // wait until the ack is cleared
    // transmit NACK 
    I2C2CONbits.ACKDT = 1;  
    data[0] = I2C2RCV;          // empty recieve buffer
    while(I2C2STATbits.RBF);    // wait until buffer is cleared
    UART_puts(data); 
    
}

void I2C_writeReadN(void){ 
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
