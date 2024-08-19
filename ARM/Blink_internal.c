
/*
 * BLINK STM32F407VG Internal LEDs
 */
#include"STM32F407VGT6_GPIO.h"
#include"STM32F407VGT6_RCC.h"
void delay()
{
volatile uint32_t count=1000000;
while(--count);
}
int main(void)
{
	volatile  uint32_t *pGPIOclken=(uint32_t*)0x40023830;   //Intialising the RCC AHB1ENB register
	GPIO_R *GPIOD =  ((GPIO_R*)0X40020C00);                 //Intialising the GPIOD port

	*pGPIOclken|=(1<<3);                                    //Enabling CLOCK to the GPIO port D for blink internal leds
	GPIOD->MODER &=0x00FFFFFF;                              //clear the 23 to 31 bit positions in the GPIOD_MODER REGISTER for setting
	GPIOD->MODER |=0x55000000;                              //GPIOD mode is set to output mode PD12 to PD15

    /* Loop forever */
	while(1)                                               //PD12 to PD15 blink LEDs
	{
		GPIOD->ODR |=0x1000;                               //GPIOD output data register(ODR) storing data
	    delay();                                           //small delay
	    GPIOD->ODR|=0x3000;
	    delay();
	    GPIOD->ODR |=0x7000;
		delay();
		GPIOD->ODR |=0xF000;
		delay();
	    GPIOD->ODR &=0x0000;
	    delay();
	}
	for(;;);
}
