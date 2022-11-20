/*
 * Hardware.c
 *
 *  Created on: Nov 4, 2022
 *      Author: jerry
 */

#include "hardware.h"
#include "hardwareIRQs.h"


void SystemInit(void)
{	// SystemInit(): This function is called at startup just after reset and
    // before branch to main program. This call is made inside the
	// "startup_stm32f0xx.s" file.
    // User can setups the default system clock (System clock source, PLL Multiplier
    // and Divider factors, AHB/APBx prescalers and Flash settings).

// Page 47 of the STM32F Reference Manual shows the device Memory Map
// Page 100 shows the Clock system schematic
// The clock for the NUCLEO-F072RB development board can be selected from the 8MHz clock from the STLINK debug board
// and feeds into Pin 5 PF0-OSC_IN.
// Clock control register addresses - Sect 6.4.15, page 136 document RM0091
// Found out how to write register without declaring a variable
// at https://www.coursera.org/lecture/embedded-software-hardware/9-register-definition-files-6pqVq
#define RCC_CR			(*((volatile unsigned long *)0x40021000))
#define RCC_CFGR		(*((volatile unsigned long *)0x40021004))
#define RCC_AHBENR		(*((volatile unsigned long *)0x40021014))

	// Enable external clock (HSE)
	// RCC_CR_HSEBYP is bit 16
	// RCC_CR_HSEON is bit 18
	// RCC_CR_HSERDY is bit 17 - set to 1 after 6 cycles
	RCC_CR = 0x00050000;
	// Select system clock source as HSE clock
	//  *((volatile unsigned long *)RCC_CFGR)= 0x00000001;
	RCC_CFGR = 0x00000001;

	// BIt 17..21 is clock enable for Port A..F
	RCC_AHBENR = 0x003E0000;

	// Setup SysTick - 1msec clock
	STK_RVR = 999;		// Number of clocks to count down from.
	STK_CVR = 0;		// Clear count down, undefined on pwr up
	STK_CSR |= 0x03;	// Start system tick counting and to request IRQ when reach 0.
}



void HardwareInit(void)
{

	GPIOA_MODE |= 0x00000400;	// Set pin 5 as an output
	// GPIOA_OTYPER - outputs default to push-pull, no need to set
	GPIOA_ODR = 0x00000020;	// Write to Bit 5 - Green LED


}
