//Display numbers in following order: 0,2,4,6,8,9,7,5,3,1
#include"STM32F407VGT6_GPIO.h"
void delay()                      //delay function
{
volatile uint32_t count=900000;
while(--count);
}
void DELAY()                      //delay function
{
volatile uint32_t count=900000;
while(--count);
}
int main(void)
{
	volatile  uint32_t *pGPIOclken=(uint32_t*)0x40023830;   //Intializing the RCC AHB1ENB register
	GPIO_R *GPIOA =  ((GPIO_R*)0X40020000);                 //Intializing the GPIOA port

	*pGPIOclken|=(1<<0);                                    //Enabling CLOCK to the GPIO port A
	    // Configure PA0-PA7 as output (for LEDs)
	    GPIOA->MODER &= ~(0x0000FFFF);  // Clear mode bits for PA0-PA7
	    GPIOA->MODER |=  (0x00005555);  // Set PA0-PA7 as output mode (01)
     uint16_t SEVEN_SEG_WD[]={0x00bf,0x0086,0x00db,0x00cf,0x00e6,0x00ed,0x00fd,0x0087,0x00ff,0x00ef};
     uint16_t SEVEN_SEG_WOD[]={0x003f,0x0006,0x005b,0x004f,0x0066,0x006d,0x007d,0x0007,0x007f,0x006f};
     uint8_t ZeroToNine[17]={0x77,0x7f,0x39,0x3f,0x79,0x71,0x7d,0x76,0x06,0x38,0x3f,0x73,0x77,0x6d,0x3e,0x6e,0x5b};
     uint16_t ORDER[]={0x003f,0x005b,0x0066,0x007d,0x007f,0x006f,0x0007,0x006d,0x004f,0x0006};
     while(1)
     	{
     	    for(int8_t i=0;i<10;i=i+1)
            {
                GPIOA->ODR=ORDER[i];
                DELAY();
            }
     	}
}




