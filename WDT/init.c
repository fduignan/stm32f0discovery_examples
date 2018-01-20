// Initialization and interrupt vectors for the LPC1114 microcontroller
// No claims are made as to the suitability of this code for any 
// purpose whatsoever.  Use at your own risk!
// Does not include initialization for C++ global/static objects
// so probably best to use this with C projects for now.
// Latest version of this code can be found by visiting
// http://eleceng.dit.ie/frank and follow the links
// Author: Frank Duignan

#include "stm32f05xxx.h"
void init(void);
void Default_Handler(void);
int main();
// The following are 'declared' in the linker script
extern unsigned char  INIT_DATA_VALUES;
extern unsigned char  INIT_DATA_START;
extern unsigned char  INIT_DATA_END;
extern unsigned char  BSS_START;
extern unsigned char  BSS_END;
// the section "vectors" is placed at the beginning of flash 
// by the linker script
void Reset_Handler(void);

const void * Vectors[] __attribute__((section(".vectors"))) ={
	(void *)0x20002000, 	/* Top of stack */ 
	Reset_Handler,   		/* Reset Handler */
	Default_Handler,	/* NMI */
	Default_Handler,	/* Hard Fault */
	0,	                /* Reserved */
	0,                   	/* Reserved */
	0,                   	/* Reserved */
	0,                   	/* Reserved */
	0,                   	/* Reserved */
	0,                   	/* Reserved */
	0,                   	/* Reserved */
	Default_Handler,	/* SVC */
	0,                   	/* Reserved */
	0,                   	/* Reserved */
	Default_Handler,     	/* PendSV */
	Default_Handler,     	/* SysTick */		
/* External interrupt handlers follow */
	Default_Handler, 	/* PIO0_0 */
	Default_Handler, 	/* PIO0_1 */
	Default_Handler, 	/* PIO0_2 */
	Default_Handler, 	/* PIO0_3 */
	Default_Handler, 	/* PIO0_4 */
	Default_Handler, 	/* PIO0_5 */
	Default_Handler, 	/* PIO0_6 */
	Default_Handler, 	/* PIO0_7 */
	Default_Handler, 	/* PIO0_8 */
	Default_Handler, 	/* PIO0_9 */
	Default_Handler, 	/* PIO0_10 */
	Default_Handler, 	/* PIO0_11 */
	Default_Handler,	/* PIO1_0 */
	Default_Handler ,  	/* C_CAN */
	Default_Handler, 	/* SSP1 */
	Default_Handler, 	/* I2C */
	Default_Handler, 	/* CT16B0 */
	Default_Handler, 	/* CT16B1 */
	Default_Handler, 	/* CT32B0 */
	Default_Handler, 	/* CT32B1 */
	Default_Handler, 	/* SSP0 */
	Default_Handler,	/* UART */
	Default_Handler, 	/* RESERVED */
	Default_Handler, 	/* RESERVED */
	Default_Handler, 	/* ADC */
	Default_Handler, 	/* WDT */
	Default_Handler, 	/* BOD */
	Default_Handler, 	/* RESERVED */
	Default_Handler, 	/* PIO3 */
	Default_Handler, 	/* PIO2 */
	Default_Handler, 	/* PIO1 */
	Default_Handler 	/* PIO0 */
};

void Reset_Handler()
{
// do global/static data initialization

	
	
	main();
}

void Default_Handler()
{
	while(1);
}
