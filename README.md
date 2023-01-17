# ECEN215-LABKIT
This README file provides an overview of the Microcontroller (MCU) subsystem used in the project. The MCU subsystem was validated to fulfill the criteria needed to support the logical and processing needs of the other subsystems. This includes communicating at most 2 bytes of data between the MCU and Sensor subsystem via SPI, and communicating 14 bits of data via SPI and I2C to the Power and Signal generation subsystem. All of which is controlled via commands from the Application subsystem via UART communication.

The validation process involved a combined final validation of all integrated subsystems' requirements and was done with the use of if-else statements to switch between SPI and I2C protocols via command from a console. For example, when the command "I2C" is sent to the PIC microcontroller via UART it prints 6 bytes of data "howdy!" from the connected arduino via I2C. Similarly, the command "SPI" triggers the PIC microcontroller to print "n" bytes of the data transferred from the client device.

The PIC32 is configured via C code using the XC32 compiler on MPLAB X. This IDE was used for the configuration of all the communication protocols of the MCU subsystem which were programmed as standalone projects without the use of Harmony.

The I2C communication protocol was validated using an Arduino UNO (Slave) and PIC32MZ Curiosity board (Master) with 10k pull-up resistors connected between the SCL and SDA lines. The protocol begins by enabling the I2C configuration bits to send the start signal before executing the receive conditions. It sends the "ACK" command to acknowledge received data and accumulates more data until the "NACK" command is set to skip the acknowledge signal. The Stop command is set to terminate communication. The use of a for loop in this function allows for the communication of N number of bytes of data. A baud rate of 100kHz is set using a 24MHz EC oscillator and can be configured higher to meet the demands of integrated subsystems.

The SPI communication protocol was validated using a PIC32MK1024GPE100 MCU on a starter kit (Slave) and PIC32MZ2048EM100 chip on a Curiosity Curiosity board (Master). Data is read on the rising edge of the SCK. The protocol works by initializing the SPI start condition. It sends dummy data to clock the reply back in. The transaction polls as it waits for the Transmit and receive buffers before looping back to receive more bytes of data. After which the stop conditions are sent. This protocol utilizes a HS oscillator at 24MHz to meet the demands of the other integrated subsystems.

PCB Gerber files have also been included to complement firmwire design. 

If you have any questions or concerns about the Microcontroller subsystem, please reach out to me for assistance.




