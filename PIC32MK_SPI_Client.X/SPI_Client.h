/* 
 * File:   SPI_Client.h
 * Author: A68422
 *
 * Created on November 18, 2022, 8:47 AM
 */

#ifndef SPI_CLIENT_H
#define	SPI_CLIENT_H

#ifdef	__cplusplus
extern "C" {
#endif

void SPI_Client_Init(void); 
void poll(void); 
void delay(void);
void SPI_readWrite(void);
void SPI_Slave_write(char msg);
unsigned char SPI_Slave_read(void);
void SPI_Write_String(char *arrayData, int length);



#ifdef	__cplusplus
}
#endif

#endif	/* SPI_CLIENT_H */

