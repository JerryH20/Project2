/*
 * Hardware.h
 *
 *  Created on: Nov 4, 2022
 *      Author: jerry
 */

#ifndef SRC_HARDWARE_H_
#define SRC_HARDWARE_H_

extern void SystemInit(void);		// Initialize clock at startup.
extern void HardwareInit(void);

// Address of GPIOA registers.
#define GPIOA_MODE				(*((volatile unsigned long *)0x48000000))
#define GPIOA_OTYPER			(*((volatile unsigned long *)0x48000004))
#define GPIOA_ODR					(*((volatile unsigned long *)0x48000014))




#endif /* SRC_HARDWARE_H_ */
