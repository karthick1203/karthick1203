#include <atmel_start.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	/* Replace with your application code */
	
	while (1) {
		//initMCP4541();
		AFE_I2C_test()	;	
		delay_ms(1000);
	}
}
