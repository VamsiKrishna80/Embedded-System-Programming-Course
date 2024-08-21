/*
Glow the LEDs in following order
0 then 0,1 then 0,1, 2...... then 0,1,2,3,4,5,6,7
with delay.
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

	*pGPIOclken|=(1<<0);                                    //Enabling CLOCK to the GPIO port A for glow EXTERNAL leds
	GPIOA->MODER &=0xFFFF0000;                              //clear the 0 to 15 bit positions in the GPIOA_MODER REGISTER for setting OUTPUT MODE pin 0 to 7
	GPIOA->MODER |=0x00005555;                              //GPIOA mode is set to output mode
    uint16_t LED[8]={0x001,0x0003,0x0007,0x000f,0x001f,};
    /* Loop forever */
	while(1)
	{
	    for(uint8_t i=0;i<8;i++)
        {
		GPIOA->ODR =LED[i];
		delay();
        }
	    GPIOA->ODR =0;
	    delay();
	}
	for(;;);
}
