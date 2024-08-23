//Press 0th switch glow odd LEDs
/*
Press any switch glow 7th LED, delay,6th LED, delay ...
*/
#include"STM32F407VGT6_GPIO.h"
void delay()                      //delay function
{
volatile uint32_t count=500000;
while(--count);
}
void DELAY()                      //delay function
{
volatile uint32_t count=1000000;
while(--count);
}
int main(void)
{
	volatile  uint32_t *pGPIOclken=(uint32_t*)0x40023830;   //Intializing the RCC AHB1ENB register
	GPIO_R *GPIOA =  ((GPIO_R*)0X40020000);                 //Intializing the GPIOA port
	GPIO_R *GPIOD =  ((GPIO_R*)0X40020C00);                 //Intializing the GPIOD port

	*pGPIOclken|=(1<<0);                                    //Enabling CLOCK to the GPIO port A
	*pGPIOclken|=(1<<3);                                    //Enabling CLOCK to the GPIO port D

	    // Configure PA0-PA7 as output (for LEDs)
	    GPIOA->MODER &= ~(0x0000FFFF);  // Clear mode bits for PA0-PA7
	    GPIOA->MODER |=  (0x00005555);  // Set PA0-PA7 as output mode (01)

	    // Configure PD0-PD7 as input with pull-down resistors (for pushbuttons)
	    GPIOD->MODER &= ~(0x0000FFFF);  // Clear mode bits for PD0-PD7 (input mode: 00)
	    GPIOD->PUPDR &= ~(0x0000FFFF);  // Clear pull-up/pull-down bits
	    GPIOD->PUPDR |=  (0x0000AAAA);  // Set pull-down for PD0-PD7 (10 binary = 2

    /* Loop forever */
     while(1)
     	{
    	     if((GPIOD->IDR & 0x0001)==0x0001)
    	      		{
    	      			delay();
    	      		   GPIOA->ODR=0x00AA;
    	      		   DELAY();
    	      		   GPIOA->ODR=0;
    	      		}
     	}
	for(;;);
}
