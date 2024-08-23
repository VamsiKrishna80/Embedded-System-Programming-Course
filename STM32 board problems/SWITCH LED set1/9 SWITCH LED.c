/*
Press any switch 0th LED ON, OFF
1st LED ON, OFF....
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

	    // Configure PA0-PA7 as output (for LEDs)
	    GPIOA->MODER &= ~(0x0000FFFF);  // Clear mode bits for PA0-PA7
	    GPIOA->MODER |=  (0x00005555);  // Set PA0-PA7 as output mode (01)

	    // Configure PD0-PD7 as input with pull-down resistors (for pushbuttons)
	    GPIOD->MODER &= ~(0x0000FFFF);  // Clear mode bits for PD0-PD7 (input mode: 00)
	    GPIOD->PUPDR &= ~(0x0000FFFF);  // Clear pull-up/pull-down bits
	    GPIOD->PUPDR |=  (0x0000AAAA);  // Set pull-down for PD0-PD7 (10 binary = 2

	    uint16_t LED[]={0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0080};
	       /* Loop forever */
     while(1)
     	{
    	     if((GPIOD->IDR & 0x0001)==0x0001)
    	      		{
    	      			delay();
    	      		for(uint8_t i=0;i<8;i++)
    	      		{
    	      		    GPIOA->ODR =LED[i];
    	      		     delay();
    	      		}
    	      		 GPIOA->ODR =0x0000;
    	      		}
    	     else if((GPIOD->IDR & 0x0002)==0x00002)
     		     		{
     		     			delay();
     		     		for(uint8_t i=0;i<8;i++)
     		     		{
     		     		    GPIOA->ODR =LED[i];
     		     		     delay();
     		     		}
     		     		 GPIOA->ODR =0x0000;
     		     		}
     		else if((GPIOD->IDR & 0x0004)==0x00004)
     		     		{
     		     			delay();
     		     		for(uint8_t i=0;i<8;i++)
     		     		{
     		     		    GPIOA->ODR =LED[i];
     		     		     delay();
     		     		}
     		     		 GPIOA->ODR =0x0000;
     		     		}
     		else if((GPIOD->IDR & 0x0008)==0x00008)
     		     		{
     		     			delay();
     		     		for(uint8_t i=0;i<8;i++)
     		     		{
     		     		    GPIOA->ODR =LED[i];
     		     		     delay();
     		     		}
     		     		 GPIOA->ODR =0x0000;
     		     		}
     		else if((GPIOD->IDR & 0x00010)==0x00010)
     		     		{
     		     			delay();
     		     		for(uint8_t i=0;i<8;i++)
     		     		{
     		     		    GPIOA->ODR =LED[i];
     		     		     delay();
     		     		}
     		     		 GPIOA->ODR =0x0000;
     		     		}
     		else if((GPIOD->IDR & 0x0020)==0x00020)
     		     		{
     		     			delay();
     		     		for(uint8_t i=0;i<8;i++)
     		     		{
     		     		    GPIOA->ODR =LED[i];
     		     		     delay();
     		     		}
     		     		 GPIOA->ODR =0x0000;
     		     		}
     		else if((GPIOD->IDR & 0x0040)==0x00040)
     		     		{
     		     			delay();
     		     		for(uint8_t i=0;i<8;i++)
     		     		{
     		     		    GPIOA->ODR =LED[i];
     		     		     delay();
     		     		}
     		     		 GPIOA->ODR =0x0000;
     		     		}
     		else if((GPIOD->IDR & 0x0080)==0x00080)
     		     		{
     		     			delay();
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
