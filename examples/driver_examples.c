/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

/*! The buffer size for ADC */
#define ADC_B_BUFFER_SIZE 16
static uint8_t ADC_B_buffer[ADC_B_BUFFER_SIZE];

static void convert_cb_ADC_B(const struct adc_dma_descriptor *const descr)
{
}

/**
 * Example of using ADC_B to generate waveform.
 */
void ADC_B_example(void)
{
	/* Enable ADC freerun mode in order to make example work */
	adc_dma_register_callback(&ADC_B, ADC_DMA_COMPLETE_CB, convert_cb_ADC_B);
	adc_dma_enable_channel(&ADC_B, 0);
	adc_dma_read(&ADC_B, ADC_B_buffer, ADC_B_BUFFER_SIZE);
}

/*! The buffer size for ADC */
#define ADC_A_BUFFER_SIZE 16
static uint8_t ADC_A_buffer[ADC_A_BUFFER_SIZE];

static void convert_cb_ADC_A(const struct adc_dma_descriptor *const descr)
{
}

/**
 * Example of using ADC_A to generate waveform.
 */
void ADC_A_example(void)
{
	/* Enable ADC freerun mode in order to make example work */
	adc_dma_register_callback(&ADC_A, ADC_DMA_COMPLETE_CB, convert_cb_ADC_A);
	adc_dma_enable_channel(&ADC_A, 0);
	adc_dma_read(&ADC_A, ADC_A_buffer, ADC_A_BUFFER_SIZE);
}

static void button_on_PC08_pressed(void)
{
}

static void button_on_PC25_pressed(void)
{
}

static void button_on_PC26_pressed(void)
{
}

static void button_on_PC11_pressed(void)
{
}

static void button_on_PB22_pressed(void)
{
}

static void button_on_PB24_pressed(void)
{
}

static void button_on_PA10_pressed(void)
{
}

static void button_on_PA11_pressed(void)
{
}

static void button_on_PA12_pressed(void)
{
}

static void button_on_PA13_pressed(void)
{
}

static void button_on_PB14_pressed(void)
{
}

/**
 * Example of using EXTERNAL_IRQ
 */
void EXTERNAL_IRQ_example(void)
{

	ext_irq_register(PIN_PC08, button_on_PC08_pressed);
	ext_irq_register(PIN_PC25, button_on_PC25_pressed);
	ext_irq_register(PIN_PC26, button_on_PC26_pressed);
	ext_irq_register(PIN_PC11, button_on_PC11_pressed);
	ext_irq_register(PIN_PB22, button_on_PB22_pressed);
	ext_irq_register(PIN_PB24, button_on_PB24_pressed);
	ext_irq_register(PIN_PA10, button_on_PA10_pressed);
	ext_irq_register(PIN_PA11, button_on_PA11_pressed);
	ext_irq_register(PIN_PA12, button_on_PA12_pressed);
	ext_irq_register(PIN_PA13, button_on_PA13_pressed);
	ext_irq_register(PIN_PB14, button_on_PB14_pressed);
}

void FG_I2C_example(void)
{
	struct io_descriptor *FG_I2C_io;

	i2c_m_sync_get_io_descriptor(&FG_I2C, &FG_I2C_io);
	i2c_m_sync_enable(&FG_I2C);
	i2c_m_sync_set_slaveaddr(&FG_I2C, 0x12, I2C_M_SEVEN);
	io_write(FG_I2C_io, (uint8_t *)"Hello World!", 12);
}

void AFE_I2C_example(void)
{
	struct io_descriptor *AFE_I2C_io;

	i2c_m_sync_get_io_descriptor(&AFE_I2C, &AFE_I2C_io);
	i2c_m_sync_enable(&AFE_I2C);
	i2c_m_sync_set_slaveaddr(&AFE_I2C, 0x08, I2C_M_SEVEN);
	io_write(AFE_I2C_io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using FLASH to write "Hello World" using the IO abstraction.
 */
static uint8_t example_FLASH[12] = "Hello World!";

void FLASH_example(void)
{
	struct io_descriptor *io;
	spi_m_sync_get_io_descriptor(&FLASH, &io);

	spi_m_sync_enable(&FLASH);
	io_write(io, example_FLASH, 12);
}

void I2C_0_example(void)
{
	struct io_descriptor *I2C_0_io;

	i2c_m_sync_get_io_descriptor(&I2C_0, &I2C_0_io);
	i2c_m_sync_enable(&I2C_0);
	i2c_m_sync_set_slaveaddr(&I2C_0, 0x12, I2C_M_SEVEN);
	io_write(I2C_0_io, (uint8_t *)"Hello World!", 12);
}


