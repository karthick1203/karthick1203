/*
 * CFile1.c
 *
 * Created: 2021-12-28 7:59:18 PM
 *  Author: ganes
 */ 

#include "mcp4541.h"


void initMCP4541(void)
{
	static uint8_t wiper=0x80 ;
	static uint8_t wiper0[2] ;
	static uint8_t tcon[2] ;
	
	
	writeMCP4541(writeprot,increment, 0x01);
    writeMCP4541(wiperLock0,increment, 0x01);
    writeMCP4541(volatileWiper0,writeData, wiper);
	readMCP4541(volatileWiper0,readData, &wiper0[0]);
	readMCP4541(tconReg,readData, &tcon[0]);
	delay_ms(10);
}

void writeMCP4541( MemoryMap_t memAddr,Command_Operation_t bit, uint8_t data)
{
	struct io_descriptor *CHG_POT_io;
    uint8_t cmdbyte[2] = { getCommandbyte(memAddr,bit), data};

	i2c_m_sync_get_io_descriptor(&CHG_POT, &CHG_POT_io);
	i2c_m_sync_enable(&CHG_POT);
	i2c_m_sync_set_slaveaddr(&CHG_POT,SLAVEADDRESS , I2C_M_SEVEN);
	io_write(CHG_POT_io,&cmdbyte,2);
	i2c_m_sync_set_slaveaddr(&CHG_POT,SLAVEADDRESS ,I2C_M_SEVEN);
	   
}

void readMCP4541( MemoryMap_t memAddr,Command_Operation_t bit, uint8_t *data)
{
	struct io_descriptor *CHG_POT_io;
	uint8_t cmdbyte = getCommandbyte( memAddr,bit);	
	i2c_m_sync_get_io_descriptor(&CHG_POT, &CHG_POT_io);
	i2c_m_sync_enable(&CHG_POT);
	i2c_m_sync_set_slaveaddr(&CHG_POT,SLAVEADDRESS , I2C_M_RD);
	io_write(CHG_POT_io,&cmdbyte,1);
	io_read(CHG_POT_io,data,2);
}





uint8_t getCommandbyte( MemoryMap_t memAddr,Command_Operation_t bit)
{
	uint8_t command = (memAddr & 0x0f) << 4 ;	
	switch(bit)
	{	
		case writeData:
			command &= ~(1UL << 3);
			command &= ~(1UL << 2);
		break;
		case increment:
			command &= ~(1UL << 3);
			command |= 1UL << 2;
		break; 
		case decrement:
			command &= ~(1UL << 2);
			command |= 1UL << 3;
		break;
		case readData:
			command |= 1UL << 2;
			command |= 1UL << 3;
		break;
	}	
	return(command);
}





