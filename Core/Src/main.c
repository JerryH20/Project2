// main.c
#include "main.h"
#include "hardware.h"
#include "hardwareIRQs.h"


int main(void)
{
unsigned long int LED_timer = 0;

	HardwareInit();

  while (1)
  {
  	if (msecTimer < 10000)
  	{	// for first 10 seconds use loop to turn LED on/off
  		for (unsigned long int j=0; j<1; j++)
  			GPIOA_ODR = 0x00000000;  // Turn LED off
  		for (unsigned long int j=0; j<1; j++)
  			GPIOA_ODR = 0x00000020;  // Turn LED on
  	}
  	else
  	{	// use IRQ millisecond timer...
  		if (msecTimer >= LED_timer)
  		{
  			if ( (GPIOA_ODR & 0x0000020) != 0)
  			{
  				GPIOA_ODR = 0x00000000;  // Turn LED off
  				LED_timer = msecTimer + 1000;
  			}
  			else
  			{
  				GPIOA_ODR = 0x00000020;		// Turn LED on
  				LED_timer = msecTimer + 200;
  			}
  		}
  	}

  }

}

