/*
Press 3rd switch glow 0th LED, delay,1st LED, delay ...
*/
#include"STM32F407VGT6_GPIO.h"
void delay()                      //delay function
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

	GPIOA->MODER &=0xFFFF0000;                              //clear the 0 to 15 bit positions in the GPIOA_MODER REGISTER for setting OUTPUT MODE pin 0 to 7
	GPIOA->MODER |=0x00005555;                              //GPIOA mode is set to output mode

	GPIOD->MODER &=0xFFFF0000;                              //clear the 0 to 15 bit positions in the GPIOD_MODER REGISTER for setting INPUT MODE pin 0 to 7
	GPIOD->MODER |=0x00000000;                              //GPIOA mode is set to input mode

	GPIOD->PUPDR&=0xFFFF0000;
	GPIOD->PUPDR|=0x0000AAAA;                               // Enabling Internal pulldown resistor

    uint16_t LED[]={0x0001,0x0003,0x007,0x000F,0x001F,0x003F,0x007F,0x00FF,0x007F,0x003F,0x001F,0x000F,0x007,0x0003,0x0001};
    /* Loop forever */
	while(1)
	{
		if((GPIOD->IDR & 0x0008)==0x0008)
		{
		for(uint8_t i=0;i<8;i++)
		{
			 GPIOA->ODR =LED[i];
			 delay();
		}
		GPIOA->ODR =0x0000;
	}
	}
	for(;;);
}
