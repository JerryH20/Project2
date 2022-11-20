// HardwareIRQs.h
// Cortex-M0 Processor Interruption and Exception Handlers

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HardwareIRQs_h
#define HardwareIRQs_h

extern unsigned long int msecTimer;


// Nested Vector Interrupt Controller registers.
// There are 32 possible IRQs. They are enabled by setting bit in IER.
// An IRQ priority is set by IRP0..IRP7. A value of zero is highest priority.
// When IRQ occurs, it is cleared by clearing the bit in the Clear Register.
#define NVIC_IER (*(unsigned long *)0xE000E100)		// IRQ Enable
#define NVIC_ICER (*(unsigned long *)0XE000E180)	// IRQ Clear
#define NVIC_ISPR (*(unsigned long *)0XE000E200)	// IRQ Set Pending if read a "1"
#define NVIC_ISCR (*(unsigned long *)0XE000E280)	// IRQ Clear Pending, write "1" to clear
#define NVIC_IPR0 (*(unsigned long *)0XE000E400)	// IRQ Priority
#define NVIC_IPR1 (*(unsigned long *)0XE000E404)
#define NVIC_IPR2 (*(unsigned long *)0XE000E408)
#define NVIC_IPR3 (*(unsigned long *)0XE000E40C)
#define NVIC_IPR4 (*(unsigned long *)0XE000E410)
#define NVIC_IPR5 (*(unsigned long *)0XE000E414)
#define NVIC_IPR6 (*(unsigned long *)0XE000E418)
#define NVIC_IPR7 (*(unsigned long *)0XE000E41C)

#define STK_CSR		(*(unsigned long *)0xE000E010)	// Set bits 0 & 1 to enable countdown and IRQ request.
#define STK_RVR		(*(unsigned long *)0xE000E014)	// #(clocks-1) to countdown from
#define STK_CVR		(*(unsigned long *)0xE000E018)	// write 0 to clear, undefined on pwr up

#define REG_SHPR3	(*(unsigned long *)0xE000ED20)	// System handler priority register 3
											// upper byte is SysTick priority, defaults to 0.

//ICSR




/*!< Interrupt Number Definition */
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */

/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  PVD_VDDIO2_IRQn             = 1,      /*!< PVD & VDDIO2 Interrupt through EXTI Lines 16 and 31             */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_CRS_IRQn                = 4,      /*!< RCC & CRS global Interrupt                                      */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  TSC_IRQn                    = 8,      /*!< Touch Sensing Controller Interrupts                             */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_6_7_IRQn    = 11,     /*!< DMA1 Channel 4 to Channel 7 Interrupt                           */
  ADC1_COMP_IRQn              = 12,     /*!< ADC1 and COMP interrupts (ADC interrupt combined with EXTI Lines 21 and 22 */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_DAC_IRQn               = 17,     /*!< TIM6 global and DAC channel underrun error Interrupt            */
  TIM7_IRQn                   = 18,     /*!< TIM7 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt & EXTI Line26 Interrupt (USART2 wakeup) */
  USART3_4_IRQn               = 29,     /*!< USART3 and USART4 global Interrupt                              */
  CEC_CAN_IRQn                = 30,     /*!< CEC and CAN global Interrupts & EXTI Line27 Interrupt           */
  USB_IRQn                    = 31      /*!< USB global Interrupt  & EXTI Line18 Interrupt                   */
} IRQn_Type;



/* Exported functions prototypes ---------------------------------------------*/
void NMI_Handler(void);
void HardFault_Handler(void);
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

#endif // HardwareIRQs_h
