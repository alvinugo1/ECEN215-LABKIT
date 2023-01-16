/* 
 * File:   SPI_Master.h
 * Author: A68422
 *
 * Created on November 18, 2022, 8:39 AM
 */

#ifndef SPI_MASTER_H
#define	SPI_MASTER_H

#ifdef	__cplusplus
extern "C" {
#endif

void SPI_Master_Init(void); 
void SPI_start(void); 
void SPI_stop(void);
void SPI_write(char msg);
unsigned char SPI_read(void);
void SPI_Slave_write(char msg);
void SPI_writeRead(void);
void poll(void); 
void SPI_ReadWString(char *arrayData, int length);
void SPI_read_2(unsigned char num, char *buf);

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_MASTER_H */

