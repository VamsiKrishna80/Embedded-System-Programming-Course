/*
Glow the LEDs in following order
7 then 7,6 then 7,6, 5...... then 7,6,5,4,3,2,1,0
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
    uint16_t LED[8]={0x0080,0x00c0,0x00e0,0x00f0,0x00f8,0x00fc,0x00fe,0x00ff};
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
