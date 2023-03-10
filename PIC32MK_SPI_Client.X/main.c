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
*/
// PIC32MK1024GPE100 Configuration Bit Settings

// 'C' source line config statements

// DEVCFG3
#pragma config USERID = 0xFFFF          // Enter Hexadecimal value (Enter Hexadecimal value)
#pragma config FUSBIDIO2 = ON           // USB2 USBID Selection (USBID pin is controlled by the USB2 module)
#pragma config FVBUSIO2 = ON            // USB2 VBUSON Selection bit (VBUSON pin is controlled by the USB2 module)
#pragma config PGL1WAY = ON             // Permission Group Lock One Way Configuration bit (Allow only one reconfiguration)
#pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config FUSBIDIO1 = ON           // USB1 USBID Selection (USBID pin is controlled by the USB1 module)
#pragma config FVBUSIO1 = ON            // USB2 VBUSON Selection bit (VBUSON pin is controlled by the USB1 module)

// DEVCFG2
#pragma config FPLLIDIV = DIV_8         // System PLL Input Divider (8x Divider)
#pragma config FPLLRNG = RANGE_54_64_MHZ// System PLL Input Range (54-64 MHz Input)
#pragma config FPLLICLK = PLL_FRC       // System PLL Input Clock Selection (FRC is input to the System PLL)
#pragma config FPLLMULT = MUL_128       // System PLL Multiplier (PLL Multiply by 128)
#pragma config FPLLODIV = DIV_32        // System PLL Output Clock Divider (32x Divider)
#pragma config VBATBOREN = ON           // VBAT BOR Enable (Enable ZPBOR during VBAT Mode)
#pragma config DSBOREN = ON             // Deep Sleep BOR Enable (Enable ZPBOR during Deep Sleep Mode)
#pragma config DSWDTPS = DSPS32         // Deep Sleep Watchdog Timer Postscaler (1:2^36)
#pragma config DSWDTOSC = LPRC          // Deep Sleep WDT Reference Clock Selection (Select LPRC as DSWDT Reference clock)
#pragma config DSWDTEN = OFF             // Deep Sleep Watchdog Timer Enable (Enable DSWDT during Deep Sleep Mode)
#pragma config FDSEN = ON               // Deep Sleep Enable (Enable DSEN bit in DSCON)
#pragma config BORSEL = HIGH            // Brown-out trip voltage (BOR trip voltage 2.1v (Non-OPAMP deviced operation))
#pragma config UPLLEN = OFF             // USB PLL Enable (USB PLL Disabled)

// DEVCFG1
#pragma config FNOSC = POSC             // Oscillator Selection Bits (Primary Osc (HS,EC))
#pragma config DMTINTV = WIN_127_128    // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enable Secondary Oscillator)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = HS             // Primary Oscillator Configuration (External clock mode)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FCKSM = CSECME           // Clock Switching and Monitor Selection (Clock Switch Enabled, FSCM Enabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WDTSPGM = STOP           // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config WINDIS = NORMAL          // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config FWDTEN = OFF              // Watchdog Timer Enable (WDT Enabled)
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window size is 25%)
#pragma config DMTCNT = DMT31           // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config FDMTEN = ON              // Deadman Timer Enable (Deadman Timer is enabled)

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is disabled)
#pragma config JTAGEN = ON              // JTAG Enable (JTAG Port Enabled)
#pragma config ICESEL = ICS_PGx1        // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config TRCEN = ON               // Trace Enable (Trace features in the CPU are enabled)
#pragma config BOOTISA = MIPS32         // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config FSLEEP = OFF             // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config DBGPER = PG_ALL          // Debug Mode CPU Access Permission (Allow CPU access to all permission regions)
#pragma config SMCLR = MCLR_NORM        // Soft Master Clear Enable (MCLR pin generates a normal system Reset)
#pragma config SOSCGAIN = GAIN_2X       // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config SOSCBOOST = ON           // Secondary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config POSCGAIN = GAIN_LEVEL_3  // Primary Oscillator Gain Control bits (Gain Level 3 (highest))
#pragma config POSCBOOST = ON           // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config EJTAGBEN = NORMAL        // EJTAG Boot Enable (Normal EJTAG functionality)

// DEVCP
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

// SEQ
#pragma config TSEQ = 0xFFFF            // Boot Flash True Sequence Number (Enter Hexadecimal value)
#pragma config CSEQ = 0xFFFF            // Boot Flash Complement Sequence Number (Enter Hexadecimal value)

#include "main.h"
#include "SPI_Client.h"

/*
 * 
 */


int main(int argc, char** argv) {
    __builtin_disable_interrupts(); 
    SPI_Client_Init();  
    __builtin_enable_interrupts(); 
    while(1){
       
    }
    return (0);
}


