/*
Press any switch & Display should start from
that number till nine and restart from that number
till 9. Continuous loop.
*/
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
uint8_t ReadSwitch(void)
{
 volatile  uint32_t *pGPIOclken=(uint32_t*)0x40023830;   //Intializing the RCC AHB1ENB register
 GPIO_R *GPIOD =  ((GPIO_R*)0X40020C00);                 //Intializing the GPIOD port
 uint16_t Switch = (GPIOD->IDR);
 *pGPIOclken|=(1<<3);
  // Configure PD0-PD7 as input with pull-down resistors (for pushbuttons)
	    GPIOD->MODER &= ~(0x000FFFFF);  // Clear mode bits for PD0-PD7 (input mode: 00)

  if((Switch & 0x0001)==0x0001)
  {
    delay();
    return 0;
  }
  else if((Switch & 0x0002)==0x0002)
  {
    delay();
    return 1;
  }
   else if((Switch & 0x0004)==0x0004)
  {
      delay();
    return 2;
  }
   else if((Switch & 0x0008)==0x0008)
  {
      delay();
    return 3;
  }
  else if((Switch & 0x0010)==0x0010)
  {
      delay();
    return 4;
  }
  else if((Switch & 0x0020)==0x0020)
  {
      delay();
    return 5;
  }
   else if((Switch & 0x0040)==0x0040)
  {
      delay();
    return 6;
  }
   else if((Switch & 0x0080)==0x0080)
  {
       delay();
    return 7;
  }
    else if((Switch & 0x0100)==0x0100)
  {
      delay();
    return 8;
  }
   else if((Switch & 0x0200)==0x0200)
  {
       delay();
    return 9;
  }
  else
  {
    return 10;
  }
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
     uint16_t SEVEN_SEG[]={0x003f,0x0006,0x005b,0x004f,0x0066,0x006d,0x007d,0x0007,0x007f,0x006f};
     uint8_t Switch=10;
     GPIOA->ODR=0;
    /* Loop forever */
     while(1)
     	{
          Switch=ReadSwitch();
    if(Switch>=0 && Switch<=9)
          {
   switch(Switch)
    {
      case 0:
          while(1)
          {
          for(uint8_t i=0;i<10;i++)
          {
              GPIOA->ODR=SEVEN_SEG[i];
              DELAY();
          }
          }
            break;
      case 1:
          while(1)
          {
          for(uint8_t i=1;i<10;i++)
          {
              GPIOA->ODR=SEVEN_SEG[i];
              DELAY();
          }
          }
            break;
      case 2:
         while(1)
          {
          for(uint8_t i=2;i<10;i++)
          {
              GPIOA->ODR=SEVEN_SEG[i];
              DELAY();
          }
          }
            break;
      case 3:
          while(1)
          {
          for(uint8_t i=3;i<10;i++)
          {
              GPIOA->ODR=SEVEN_SEG[i];
              DELAY();
          }
          }
            break;
      case 4:
          while(1)
          {
          for(uint8_t i=4;i<10;i++)
          {
              GPIOA->ODR=SEVEN_SEG[i];
              DELAY();
          }
          }
            break;
      case 5:
          while(1)
          {
          for(uint8_t i=5;i<10;i++)
          {
              GPIOA->ODR=SEVEN_SEG[i];
              DELAY();
          }
          }
            break;
      case 6:
         while(1)
          {
          for(uint8_t i=6;i<10;i++)
          {
              GPIOA->ODR=SEVEN_SEG[i];
              DELAY();
          }
          }
            break;
      case 7:
         while(1)
          {
          for(uint8_t i=7;i<10;i++)
          {
              GPIOA->ODR=SEVEN_SEG[i];
              DELAY();
          }
          }
            break;
      case 8:
          while(1)
          {
          for(uint8_t i=8;i<10;i++)
          {
              GPIOA->ODR=SEVEN_SEG[i];
              DELAY();
          }
          }
            break;
     case 9:
          while(1)
          {
          for(uint8_t i=9;i<10;i++)
          {
              GPIOA->ODR=SEVEN_SEG[i];
              DELAY();
          }
          }
            break;
    }
          }
     	}
	for(;;);
}

