/*
   1. Configure the mask bits of the 23 interrupt lines using EXTI_IMR
   2. Configure the Trigger selection bits of the interrupt lines (EXTI_RTSR and EXTI_FTSR)
   3.Configure the enable and mask bits that control the NVIC IRQ channel mapped to the
   4.Configure the MASK bits of SYSCFG_CRx for enabling port

   -> external interrupt controller (EXTI) so that an interrupt coming from one of the 23 lines can be correctly acknowledged.
    //  Address of EXTI 0x4001 3C00
   -> Px-0 that means EXTI0 is to be set-> EXTI_IMR |=IRQ_EXTI0;  // #define IRQ_EXTI0 1<<0
   -> PORT A is to be set    //SYSCFG_EXTICR1 address 0x40013808
   -> SYSCFG_EXTICR1 |= PORTA0 //  PORTA0 = 0x0;
   -> raising or falling edge
   -> EXTI_RTSR |= IRQ_EXTI0;
   -> WE have to enble the NVIC IRQ in processor side
                                  -> NVIC_ISER[0] // Can enable 0 to 31
                                  -> NVIC_ISER[1] // can enble 32 to 61
                                  etc.................
EXTI_PR is set when a interupt occurs so we have to clear this bit by writing '1' in interupt handler
 */

#include"STM32F407xx.h"
void Delay(uint16_t delay);
#define TIMER6_ENCLK() RCC->RCC_APB1ENR|=(1<<4)
#define SET_UIF 0x0001
#define RESET_UIF 0xFFFE
#define IRQ_EXTI0 1<<0
#define PORTA0 0x0
#define IRQ6_EXTI0 1<<6
int main()
{

    GPIOA_PCLK_EN();
    GPIO_R *gpioa = GPIOA;

	gpioa->MODER &=~0x00000003; // Onboard Switch congiration
    gpioa->IDR = 0;

    uint32_t *SYSCFG_EXTI0 = (uint32_t*)0x40013808;  // Address of SYSCFG_EXTI0
    uint32_t *EXTI_IMR = (uint32_t*)0x40013C00;       // Address of EXTI_IMR
    uint32_t *EXTI_RTSR = (uint32_t*)0x40013C08;      // Address of EXTI_RTSR
    //uint32_t *EXTI_PR = (uint32_t*)0x40013C14;      // Address of EXTI_PR
    uint32_t *NVIC_ISER = (uint32_t*)0xE000E100;      // Address of NVIC_ISER

    *EXTI_IMR |=IRQ_EXTI0;  // Enabling EXTI0 for PA0
    *SYSCFG_EXTI0 |= PORTA0; // Enabling PORTA
    *EXTI_RTSR |= IRQ_EXTI0;   // Enabling RAISING edge for EXTI0
    *NVIC_ISER |= IRQ6_EXTI0; // IRQ 6 for EXTI0
	while(1);
}
void EXTI0_IRQHandler(void)
{
	Delay(250);
	GPIOD_PCLK_EN();
	GPIO_R *gpiod = GPIOD;

	gpiod->MODER |= 0x55000000;   // led congiration
	gpiod->OSPEEDR |= 0xAA000000;
	gpiod->OTYPER |= 0;
	gpiod->PUPDR |= 0;

	uint32_t *EXTI_PR = (uint32_t*)0x40013C14;
   gpiod->ODR ^= 0x8000;                             // PD15 - Toggling the Onboard blue led
   *EXTI_PR |= 1<<0;                                 // Clearing the EXTI pending register by writing 1'
}
void Delay(uint16_t delay)
{
	    TIMER6_ENCLK();
	   TIMER67_R *Timer6 = TIMER6;
	   Timer6->CR1|=1<<7;
	   	Timer6->PSC = 16000-1;
	    Timer6->ARR = delay;
	   	Timer6->CR1 |= 1<<0; //Enabling counter
	   	while(!Timer6->SR & 0x0001);
    	Timer6->SR &= ~0x0001;
	}
