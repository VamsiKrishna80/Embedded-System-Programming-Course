#include"STM32F407xx.h"
const int16_t ANODE_SEG[]={0x00C0,0x00F9,0x00A4,0x00B0,0x0099,0x0092,0x0082,0x00F8,0x0080,0x0090};
const int16_t Dis_Sel[]={0x0001,0x0002,0x0004,0x0008};
int16_t DisplayDigit(int16_t digit)
{

  if(digit==0)
  {
    return ANODE_SEG[digit];
  }
  else if(digit==1)
  {
     return ANODE_SEG[digit];
  }
   else if(digit==2)
  {
    return ANODE_SEG[digit];
  }
   else if(digit==3)
  {
    return ANODE_SEG[digit];
  }
   else if(digit==4)
  {
    return ANODE_SEG[digit];
  }
   else if(digit==5)
  {
    return ANODE_SEG[digit];
  }
   else if(digit==6)
  {
    return ANODE_SEG[digit];
  }
    else if(digit==7)
  {
    return ANODE_SEG[digit];
  }
   else if(digit==8)
  {
    return ANODE_SEG[digit];
  }
    else if(digit==9)
  {
    return ANODE_SEG[digit];
  }
    else
    {
    	return 0x00ff;
    }
}

void Display4(int16_t Number,uint16_t Delay)
{
	GPIOA_PCLK_EN();
		GPIOD_PCLK_EN();

		    GPIO_R *GPIOA =  ((GPIO_R*)0X40020000);                 //Intializing the GPIOA port
			GPIO_R *GPIOD =  ((GPIO_R*)0X40020C00);

		GPIOA->MODER &= ~(0x0000FFFF);
		GPIOA->MODER |=  0x00005555;

		GPIOD->MODER &= ~(0x000000FF);
		GPIOD->MODER |= 0x00000055;

		volatile int16_t j=0,i=0,Digits[4],Digit1,Digit2,Digit3,Digit4;
		int16_t Dis_Sel[]={0x0001,0x0002,0x0004,0x0008};
		if(Number>999)
		  {
		    Digit1=Number/1000;
		    Digit2=(Number/100)%10;
		    Digit3=(Number%100)/10;
		    Digit4=Number%10;
		  }
		  else if(Number>99){
		    Digit4=Number%10;
		    Digit3=(Number/10)%10;
		    Digit2=Number/100;
		    Digit1=0;
		  }
		  else if(Number>9){
		    Digit4=Number%10;
		    Digit3=Number/10;
		    Digit2=0;
		    Digit1=0;
		  }
		  else if(Number > 0 && Number < 10)
		  {
		    Digit4=Number;
		    Digit3=0;
		    Digit2=0;
		    Digit1=0;
		  }
		  Digits[0]=DisplayDigit(Digit1);
		  Digits[1]=DisplayDigit(Digit2);
		  Digits[2]=DisplayDigit(Digit3);
		  Digits[3]=DisplayDigit(Digit4);
		  j=0;
while(j<Delay)
{
        	GPIOA->ODR = 0x00ff;
			GPIOD->ODR = 0;
			for( i = 0;i < 4;i++)
			{
			   GPIOA->ODR = Digits[i];
			   GPIOD->ODR = Dis_Sel[i];
			   delay(1);
			   GPIOD->ODR = 0x0000;
			}
         j++;
}
}
int main(void)
{
	int16_t Delay=50;

	while(1)
	{

    for(int16_t i=0;i<10000;i++)
    {
    	Display4(i,Delay);
    	delay(1);
    }
	}
}
