/*
 * afe76942.c
 *
 * Created: 2022-01-03 12:15:22 AM
 *  Author: ganes
 */ 
#include "afe76942.h"


void AFE_I2C_test(void)
{
	struct io_descriptor *AFE_I2C_io;
	static uint8_t Addr=0x08 ;
	uint8_t DeviCeNumberCmd[3]={0x3E,5};
	static uint8_t DeviCeNumberRead[10] ;
	static uint8_t tcon[2] ;
	
	
	i2c_m_sync_get_io_descriptor(&AFE_I2C, &AFE_I2C_io);
	i2c_m_sync_enable(&AFE_I2C);
	i2c_m_sync_set_slaveaddr(&AFE_I2C, 0x08, I2C_M_SEVEN);
	io_write(AFE_I2C_io,&DeviCeNumberCmd[0], 2);
	io_read(AFE_I2C_io,&DeviCeNumberRead[0], 3);
	delay_ms(100);
}