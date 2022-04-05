/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

struct adc_dma_descriptor    ADC_B;
struct adc_dma_descriptor    ADC_A;
struct spi_m_sync_descriptor FLASH;

struct i2c_m_sync_desc FG_I2C;

struct i2c_m_sync_desc AFE_I2C;

struct i2c_m_sync_desc I2C_0;

struct i2c_m_sync_desc CHG_POT;

/**
 * \brief ADC initialization function
 *
 * Enables ADC peripheral, clocks and initializes ADC driver
 */
static void ADC_B_init(void)
{
	hri_mclk_set_APBCMASK_ADC0_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, ADC0_GCLK_ID, CONF_GCLK_ADC0_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));

	adc_dma_init(&ADC_B, ADC0);

	// Disable digital pin circuitry
	gpio_set_pin_direction(CHG_24V_IN_SENS, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(CHG_24V_IN_SENS, PINMUX_PA02B_ADC0_AIN0);

	// Disable digital pin circuitry
	gpio_set_pin_direction(INA225_OUT, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(INA225_OUT, PINMUX_PB09B_ADC0_AIN3);

	// Disable digital pin circuitry
	gpio_set_pin_direction(P_SENS, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(P_SENS, PINMUX_PA04B_ADC0_AIN4);

	// Disable digital pin circuitry
	gpio_set_pin_direction(IN_24V_SENS, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(IN_24V_SENS, PINMUX_PA05B_ADC0_AIN5);

	// Disable digital pin circuitry
	gpio_set_pin_direction(OUT_24V_SENS, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(OUT_24V_SENS, PINMUX_PA06B_ADC0_AIN6);

	// Disable digital pin circuitry
	gpio_set_pin_direction(CHG_OUT_SENS, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(CHG_OUT_SENS, PINMUX_PA07B_ADC0_AIN7);

	// Disable digital pin circuitry
	gpio_set_pin_direction(OR_OUT_SENS, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(OR_OUT_SENS, PINMUX_PC00B_ADC0_AIN8);

	// Disable digital pin circuitry
	gpio_set_pin_direction(BAT_SENS, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(BAT_SENS, PINMUX_PC01B_ADC0_AIN9);

	// Disable digital pin circuitry
	gpio_set_pin_direction(P_OUT_SENS, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(P_OUT_SENS, PINMUX_PC02B_ADC0_AIN10);

	// Disable digital pin circuitry
	gpio_set_pin_direction(VREF_2V5, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(VREF_2V5, PINMUX_PA03B_ADC0_VREFP);
}

/**
 * \brief ADC initialization function
 *
 * Enables ADC peripheral, clocks and initializes ADC driver
 */
static void ADC_A_init(void)
{
	hri_mclk_set_APBCMASK_ADC1_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, ADC1_GCLK_ID, CONF_GCLK_ADC1_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));

	adc_dma_init(&ADC_A, ADC1);

	// Disable digital pin circuitry
	gpio_set_pin_direction(MAX14752_OUT, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(MAX14752_OUT, PINMUX_PB05B_ADC1_AIN7);
}

void EXTERNAL_IRQ_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, EIC_GCLK_ID, CONF_GCLK_EIC_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_mclk_set_APBAMASK_EIC_bit(MCLK);

	// Set pin direction to input
	gpio_set_pin_direction(AFE_ALERT, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(AFE_ALERT,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(AFE_ALERT, PINMUX_PC08A_EIC_EXTINT0);

	// Set pin direction to input
	gpio_set_pin_direction(OR_BAT_FAULT, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(OR_BAT_FAULT,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(OR_BAT_FAULT, PINMUX_PC25A_EIC_EXTINT1);

	// Set pin direction to input
	gpio_set_pin_direction(AFE_DFETOFF, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(AFE_DFETOFF,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(AFE_DFETOFF, PINMUX_PC26A_EIC_EXTINT2);

	// Set pin direction to input
	gpio_set_pin_direction(OR_LINE_FAULT, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(OR_LINE_FAULT,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(OR_LINE_FAULT, PINMUX_PC11A_EIC_EXTINT3);

	// Set pin direction to input
	gpio_set_pin_direction(V12_STAT, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(V12_STAT,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(V12_STAT, PINMUX_PB22A_EIC_EXTINT6);

	// Set pin direction to input
	gpio_set_pin_direction(B_24V_FAULT, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(B_24V_FAULT,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(B_24V_FAULT, PINMUX_PB24A_EIC_EXTINT8);

	// Set pin direction to input
	gpio_set_pin_direction(FG_EXT_EN, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(FG_EXT_EN,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(FG_EXT_EN, PINMUX_PA10A_EIC_EXTINT10);

	// Set pin direction to input
	gpio_set_pin_direction(AFE_EXT_EN, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(AFE_EXT_EN,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(AFE_EXT_EN, PINMUX_PA11A_EIC_EXTINT11);

	// Set pin direction to input
	gpio_set_pin_direction(AFE_DDSG, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(AFE_DDSG,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(AFE_DDSG, PINMUX_PA12A_EIC_EXTINT12);

	// Set pin direction to input
	gpio_set_pin_direction(AFE_DCHG, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(AFE_DCHG,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(AFE_DCHG, PINMUX_PA13A_EIC_EXTINT13);

	// Set pin direction to input
	gpio_set_pin_direction(FET_DRV_FAULT, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(FET_DRV_FAULT,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(FET_DRV_FAULT, PINMUX_PB14A_EIC_EXTINT14);

	ext_irq_init();
}

void FG_I2C_PORT_init(void)
{

	gpio_set_pin_pull_mode(FG_SDA,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(FG_SDA, PINMUX_PA08C_SERCOM0_PAD0);

	gpio_set_pin_pull_mode(FG_SCL,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(FG_SCL, PINMUX_PA09C_SERCOM0_PAD1);
}

void FG_I2C_CLOCK_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM0_GCLK_ID_CORE, CONF_GCLK_SERCOM0_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM0_GCLK_ID_SLOW, CONF_GCLK_SERCOM0_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));

	hri_mclk_set_APBCMASK_SERCOM0_bit(MCLK);
}

void FG_I2C_init(void)
{
	FG_I2C_CLOCK_init();
	i2c_m_sync_init(&FG_I2C, SERCOM0);
	FG_I2C_PORT_init();
}

void AFE_I2C_PORT_init(void)
{

	gpio_set_pin_pull_mode(AFE_SDA,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(AFE_SDA, PINMUX_PA16C_SERCOM1_PAD0);

	gpio_set_pin_pull_mode(AFE_SCL,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(AFE_SCL, PINMUX_PA17C_SERCOM1_PAD1);
}

void AFE_I2C_CLOCK_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM1_GCLK_ID_CORE, CONF_GCLK_SERCOM1_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM1_GCLK_ID_SLOW, CONF_GCLK_SERCOM1_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));

	hri_mclk_set_APBCMASK_SERCOM1_bit(MCLK);
}

void AFE_I2C_init(void)
{
	AFE_I2C_CLOCK_init();
	i2c_m_sync_init(&AFE_I2C, SERCOM1);
	AFE_I2C_PORT_init();
}

void FLASH_PORT_init(void)
{

	// Set pin direction to input
	gpio_set_pin_direction(FLASH_MISO, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(FLASH_MISO,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(FLASH_MISO, PINMUX_PA22C_SERCOM3_PAD0);

	gpio_set_pin_level(FLASH_CLK,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(FLASH_CLK, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(FLASH_CLK, PINMUX_PA23C_SERCOM3_PAD1);

	gpio_set_pin_level(FLASH_MOSI,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(FLASH_MOSI, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(FLASH_MOSI, PINMUX_PA21D_SERCOM3_PAD3);
}

void FLASH_CLOCK_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM3_GCLK_ID_CORE, CONF_GCLK_SERCOM3_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM3_GCLK_ID_SLOW, CONF_GCLK_SERCOM3_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));

	hri_mclk_set_APBCMASK_SERCOM3_bit(MCLK);
}

void FLASH_init(void)
{
	FLASH_CLOCK_init();
	spi_m_sync_init(&FLASH, SERCOM3);
	FLASH_PORT_init();
}

void I2C_0_PORT_init(void)
{

	gpio_set_pin_pull_mode(SDA_B_24V_POT,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(SDA_B_24V_POT, PINMUX_PB12C_SERCOM4_PAD0);

	gpio_set_pin_pull_mode(SCL__B_24V_POT,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(SCL__B_24V_POT, PINMUX_PB13C_SERCOM4_PAD1);
}

void I2C_0_CLOCK_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM4_GCLK_ID_CORE, CONF_GCLK_SERCOM4_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM4_GCLK_ID_SLOW, CONF_GCLK_SERCOM4_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));

	hri_mclk_set_APBCMASK_SERCOM4_bit(MCLK);
}

void I2C_0_init(void)
{
	I2C_0_CLOCK_init();
	i2c_m_sync_init(&I2C_0, SERCOM4);
	I2C_0_PORT_init();
}

void CHG_POT_PORT_init(void)
{

	gpio_set_pin_pull_mode(SDA_CHG_POT,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(SDA_CHG_POT, PINMUX_PB16C_SERCOM5_PAD0);

	gpio_set_pin_pull_mode(SCL_CHG_POT,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(SCL_CHG_POT, PINMUX_PB17C_SERCOM5_PAD1);
}

void CHG_POT_CLOCK_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM5_GCLK_ID_CORE, CONF_GCLK_SERCOM5_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM5_GCLK_ID_SLOW, CONF_GCLK_SERCOM5_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));

	hri_mclk_set_APBCMASK_SERCOM5_bit(MCLK);
}

void CHG_POT_init(void)
{
	CHG_POT_CLOCK_init();
	i2c_m_sync_init(&CHG_POT, SERCOM5);
	CHG_POT_PORT_init();
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA18

	// Set pin direction to input
	gpio_set_pin_direction(AFE_CFETOFF, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(AFE_CFETOFF,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(AFE_CFETOFF, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA19

	gpio_set_pin_function(AFE_HDQ, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA20

	gpio_set_pin_function(FLASH_CS, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA24

	// Set pin direction to input
	gpio_set_pin_direction(AFE_DPCHG, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(AFE_DPCHG,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(AFE_DPCHG, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA25

	// Set pin direction to input
	gpio_set_pin_direction(AFE_DPDSG, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(AFE_DPDSG,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(AFE_DPDSG, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB00

	gpio_set_pin_level(MCU_DDSG,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(MCU_DDSG, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(MCU_DDSG, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB01

	gpio_set_pin_level(MCU_DCHG,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(MCU_DCHG, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(MCU_DCHG, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB02

	gpio_set_pin_level(MCU_PDSG,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(MCU_PDSG, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(MCU_PDSG, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB03

	gpio_set_pin_level(MCU_PCHG,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(MCU_PCHG, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(MCU_PCHG, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB15

	gpio_set_pin_level(BMS_SHDN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(BMS_SHDN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(BMS_SHDN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB18

	gpio_set_pin_level(B_SENS_EN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(B_SENS_EN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(B_SENS_EN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB19

	gpio_set_pin_level(FLASH_WP,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(FLASH_WP, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(FLASH_WP, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB20

	gpio_set_pin_level(FLASH_HOLD,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(FLASH_HOLD, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(FLASH_HOLD, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB21

	gpio_set_pin_level(P_SENS_EN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(P_SENS_EN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(P_SENS_EN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB23

	gpio_set_pin_level(V12_EN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(V12_EN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(V12_EN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB25

	gpio_set_pin_level(MCU_B_24V_SHDN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(MCU_B_24V_SHDN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(MCU_B_24V_SHDN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB31

	gpio_set_pin_level(AFE_RST,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(AFE_RST, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(AFE_RST, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC06

	gpio_set_pin_level(IN_24V_SENS_EN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(IN_24V_SENS_EN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(IN_24V_SENS_EN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC07

	gpio_set_pin_level(OR_OUT_SENS_EN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(OR_OUT_SENS_EN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(OR_OUT_SENS_EN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC09

	gpio_set_pin_level(MCU_CHG_SHDN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	//gpio_set_pin_direction(MCU_CHG_SHDN, GPIO_DIRECTION_OUT);
	//gpio_set_pin_function(MCU_CHG_SHDN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC10

	gpio_set_pin_level(BAT_24V_EN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(BAT_24V_EN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(BAT_24V_EN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC12

	gpio_set_pin_level(CHG_IN_24V_SENS_EN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(CHG_IN_24V_SENS_EN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(CHG_IN_24V_SENS_EN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC13

	gpio_set_pin_level(CHG_OUT_SENS_EN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(CHG_OUT_SENS_EN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(CHG_OUT_SENS_EN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC14

	gpio_set_pin_level(P_OUT_SENS_EN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(P_OUT_SENS_EN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(P_OUT_SENS_EN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC15

	gpio_set_pin_level(OUT_24V_SENS_EN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(OUT_24V_SENS_EN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(OUT_24V_SENS_EN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC16

	gpio_set_pin_level(MAX14752_S0,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(MAX14752_S0, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(MAX14752_S0, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC17

	gpio_set_pin_level(MAX14752_S1,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(MAX14752_S1, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(MAX14752_S1, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC18

	gpio_set_pin_level(MAX14752_S2,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(MAX14752_S2, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(MAX14752_S2, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC19

	gpio_set_pin_level(A_3V3_EN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(A_3V3_EN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(A_3V3_EN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC20

	// Set pin direction to input
	gpio_set_pin_direction(CHG_STAT1, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(CHG_STAT1,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(CHG_STAT1, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC21

	// Set pin direction to input
	gpio_set_pin_direction(CHG_STAT2, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(CHG_STAT2,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(CHG_STAT2, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC24

	gpio_set_pin_level(LINE_24V_EN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(LINE_24V_EN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LINE_24V_EN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC27

	gpio_set_pin_level(AFE_WAKE,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(AFE_WAKE, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(AFE_WAKE, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PC28

	gpio_set_pin_level(MCU_FUSE,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(MCU_FUSE, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(MCU_FUSE, GPIO_PIN_FUNCTION_OFF);

	ADC_B_init();
	ADC_A_init();

	EXTERNAL_IRQ_init();

	FG_I2C_init();

	AFE_I2C_init();

	FLASH_init();

	I2C_0_init();

	CHG_POT_init();
}
