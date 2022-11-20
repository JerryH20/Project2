// HardwareIRQs.c
// Cortex-M0 Processor Interruption and Exception Handlers
// IRQ function names and addresses are declared in startup_stm32f072xb.s
#include "HardwareIRQs.h"

unsigned long int msecTimer;


void NMI_Handler(void)
{  // Non-maskable interrupt
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

void HardFault_Handler(void)
{	// Hard fault interrupt
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

void SVC_Handler(void)
{	// System service call via SWI instruction
  /* USER CODE BEGIN SVC_IRQn 0 */

  /* USER CODE END SVC_IRQn 0 */
  /* USER CODE BEGIN SVC_IRQn 1 */

  /* USER CODE END SVC_IRQn 1 */
}

void PendSV_Handler(void)
{	// Pendable request for system service
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

void SysTick_Handler(void)
{  	// System tick timer
	// Increment global variable "msecTimer" every 1msec, used as application time base.
  msecTimer += 1;	// IRQ occurs every 1 msec, number of msec since last power-up
}

//IRQ function names and addresses are declared in startup_stm32f072xb.s
/*
void WWDG_IRQHandler() {};
void PVD_VDDIO2_IRQHandler
void RTC_IRQHandler
void FLASH_IRQHandler
void RCC_CRS_IRQHandler
void EXTI0_1_IRQHandler
void EXTI2_3_IRQHandler
void EXTI4_15_IRQHandler
void TSC_IRQHandler
void DMA1_Channel1_IRQHandler
void DMA1_Channel2_3_IRQHandler
void DMA1_Channel4_5_6_7_IRQHandler
void ADC1_COMP_IRQHandler
void TIM1_BRK_UP_TRG_COM_IRQHandler
void TIM1_CC_IRQHandler
void TIM2_IRQHandler
void TIM3_IRQHandler
void TIM6_DAC_IRQHandler
void TIM7_IRQHandler
void TIM14_IRQHandler
void TIM15_IRQHandler
void TIM16_IRQHandler
void TIM17_IRQHandler
void I2C1_IRQHandler
void I2C2_IRQHandler
void SPI1_IRQHandler
void SPI2_IRQHandler
void USART1_IRQHandler
void USART2_IRQHandler
void USART3_4_IRQHandler
void CEC_CAN_IRQHandler
void USB_IRQHandler
*/


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
