/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef DRIVER_INIT_INCLUDED
#define DRIVER_INIT_INCLUDED

#include "atmel_start_pins.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <hal_atomic.h>
#include <hal_delay.h>
#include <hal_gpio.h>
#include <hal_init.h>
#include <hal_io.h>
#include <hal_sleep.h>

#include <hal_adc_dma.h>
#include <hal_adc_dma.h>

#include <hal_ext_irq.h>

#include <hal_i2c_m_sync.h>

#include <hal_i2c_m_sync.h>
#include <hal_spi_m_sync.h>

#include <hal_i2c_m_sync.h>

#include <hal_i2c_m_sync.h>

extern struct adc_dma_descriptor ADC_B;
extern struct adc_dma_descriptor ADC_A;

extern struct i2c_m_sync_desc FG_I2C;

extern struct i2c_m_sync_desc       AFE_I2C;
extern struct spi_m_sync_descriptor FLASH;

extern struct i2c_m_sync_desc I2C_0;

extern struct i2c_m_sync_desc CHG_POT;

void FG_I2C_CLOCK_init(void);
void FG_I2C_init(void);
void FG_I2C_PORT_init(void);

void AFE_I2C_CLOCK_init(void);
void AFE_I2C_init(void);
void AFE_I2C_PORT_init(void);

void FLASH_PORT_init(void);
void FLASH_CLOCK_init(void);
void FLASH_init(void);

void I2C_0_CLOCK_init(void);
void I2C_0_init(void);
void I2C_0_PORT_init(void);

void CHG_POT_CLOCK_init(void);
void CHG_POT_init(void);
void CHG_POT_PORT_init(void);

/**
 * \brief Perform system initialization, initialize pins and clocks for
 * peripherals
 */
void system_init(void);

#ifdef __cplusplus
}
#endif
#endif // DRIVER_INIT_INCLUDED
