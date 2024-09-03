#include"STM32F407xx.h"
const int16_t ANODE_SEG[]={0x00C0,0x00F9,0x00A4,0x00B0,0x0099,0x0092,0x0082,0x00F8,0x0080,0x0090};
const int16_t Dis_Sel[]={0x0001,0x0002,0x0004,0x0008};
int8_t Read_KeyPad(void)
{
	GPIOB_PCLK_EN();
	GPIOC_PCLK_EN();

    GPIO_R *GPIOb = GPIOB;
    GPIO_R *GPIOc = GPIOC;

    GPIOb->MODER &= ~(0x000000FF);
    GPIOb->MODER |=   0x00000055;


    GPIOc->MODER &= ~(0xFFFFFFFF);
       GPIOc->MODER |=   0x00000000;

    for(int8_t i = 0;i < 5;i++)
    {


    	GPIOb->ODR = 1 << i;

        if((GPIOb->ODR & 0X0001)==0X0001)
                {
                    delay(100);
                         if((GPIOc->IDR & 0x0001)== 0x0001)
                                {
                                     return 1;
                                }
                    else if((GPIOc->IDR & 0x0002)== 0x0002)
                                {
                                     return 2;
                                }
                    else if((GPIOc->IDR & 0x0004) == 0x0004)
                                {
                                     return 3;
                                }
                    else if((GPIOc->IDR & 0x0008) == 0x0008)
                                {
                                     return 10;
                                }
                }
        else if((GPIOb->ODR & 0X0002)==0X0002)
                {
                    delay(100);
                    if((GPIOc->IDR & 0x0001)== 0x0001)
                                {
                                     return 4;
                                }
                    else if((GPIOc->IDR & 0x0002)== 0x0002)
                                {
                                     return 5;
                                }
                    else if((GPIOc->IDR & 0x0004) == 0x0004)
                                {
                                     return 6;
                                }
                    else if((GPIOc->IDR & 0x0008) == 0x0008)
                                {
                                     return 11;
                                }
                }
        else if((GPIOb->ODR & 0X0004)==0X0004)
                {
                    delay(100);
                    if((GPIOc->IDR & 0x0001)== 0x0001)
                                {
                                     return 7;
                                }
                    else if((GPIOc->IDR & 0x0002)== 0x0002)
                                {
                                     return 8;
                                }
                    else if((GPIOc->IDR & 0x0004) == 0x0004)
                                {
                                     return 9;
                                }
                    else if((GPIOc->IDR & 0x0008) == 0x0008)
                                {
                                     return 12;
                                }
                }
        else if((GPIOb->ODR & 0X0008)==0X0008)
                {
                    delay(100);
                    if((GPIOc->IDR & 0x0001)== 0x0001)
                                {
                                     return 13;
                                }
                    else if((GPIOc->IDR & 0x0002)== 0x0002)
                                {
                                     return 0;
                                }
                    else if((GPIOc->IDR & 0x0004) == 0x0004)
                                {
                                     return 14;
                                }
                    else if((GPIOc->IDR & 0x0008) == 0x0008)
                                {
                                     return 15;
                                }
                }
          }
    return -1;
}

int16_t DisplayDigit(int16_t digit)
{

  if(digit>=0 && digit <=9 )
  {
    return ANODE_SEG[digit];
  }
    else
    {
    	return 0x00ff;
    }
}
void Display1(int16_t Number,int16_t Delay)
{
	            GPIOA_PCLK_EN();
		     	GPIOD_PCLK_EN();

			    GPIO_R *GPIOa = GPIOA;                 //Intializing the GPIOA port
				GPIO_R *GPIOd =  GPIOD;
				GPIOa->MODER &= ~(0x0000FFFF);
			    GPIOa->MODER |=  0x00005555;

				GPIOd->MODER &= ~(0x000000FF);
				GPIOd->MODER |= 0x00000055;
				 int16_t j=0,Digits[1];
			     int16_t Dis_Sel[1]={0x0008};
			     Digits[0]=DisplayDigit(Number);


			     while(j<Delay)
			     {
			    	 GPIOa->ODR = 0x00ff;
			    	 GPIOd->ODR = 0;

			     GPIOa->ODR = Digits[0];
			     GPIOd->ODR = Dis_Sel[0];
			     delay(1);
			    GPIOd->ODR = 0x0000;
			     j++;
			     }
}
void Display4(int16_t Number, uint16_t Delay) {
    GPIOA_PCLK_EN();  // Enable GPIOA clock
    GPIOD_PCLK_EN();  // Enable GPIOD clock

    GPIO_R *GPIOa = GPIOA;  // Initialize GPIOA port
    GPIO_R *GPIOd = GPIOD;  // Initialize GPIOD port

    // Set GPIOA pins 0-7 as output (for 7-segment data)
    GPIOa->MODER &= ~(0x0000FFFF);
    GPIOa->MODER |= 0x00005555;

    // Set GPIOD pins 0-3 as output (for digit selection)
    GPIOd->MODER &= ~(0x000000FF);
    GPIOd->MODER |= 0x00000055;

    // Break down the number into individual digits
    int16_t Digits[4],Number1,Digit1,Digit2,Digit3,Digit4;
    Number1=Number;
      if(Number>999)
     {
       Digit4=Number/1000;
       Digit3=(Number/100)%10;
       Digit2=(Number%100)/10;
       Digit1=Number%10;
     }
     else if(Number > 99 && Number < 1000){
       Digit1=Number%10;
       Digit2=(Number/10)%10;
       Digit3=Number/100;
       Digit4=0;
     }
     else if(Number > 9 && Number < 100){
       Digit1=Number%10;
       Digit2=Number/10;
       Digit3=0;
       Digit4=0;
     }
     else if(Number >= 0 && Number < 10)
     {
       Digit1=Number;
       Digit2=0;
       Digit3=0;
       Digit4=0;
     }
     /*
     else
     {
       Digit4=9;
       Digit3=9;
       Digit2=9;
       Digit1=9;
     }
     */
     Digits[0]=DisplayDigit(Digit1);
     Digits[1]=DisplayDigit(Digit2);
     Digits[2]=DisplayDigit(Digit3);
     Digits[3]=DisplayDigit(Digit4);
    int16_t Dis_Sel[] = {0x0001, 0x0002, 0x0004, 0x0008},j=0;  // Digit selection array

    while(j<Delay) {
        GPIOa->ODR = 0x00FF;  // Clear the display
        GPIOd->ODR = 0;

        // Display each digit in a loop
        for (volatile int16_t i = 0; i < 4; i++) {
            GPIOa->ODR = Digits[i];  // Set the data for the current digit
            GPIOd->ODR = Dis_Sel[i];  // Select the current digit
            delay(1);  // Short delay for visibility
            GPIOd->ODR = 0x0000;  // Deselect the digit
        }
        j++;
    }
}

int main(void)
{
	int16_t Delay=50;
	int8_t Number;
    GPIOE_PCLK_EN();  // Enable GPIOA clock
    GPIO_R *GPIOe = GPIOE;  // Initialize GPIOA port
    GPIOe->MODER &= ~(0x0000FFFF);
        GPIOe->MODER |= 0x00000001;



	while(1)
	{

   Number = Read_KeyPad();
   if(Number <16 && Number >= 0)
   {
 	//Display4(Number,Delay);
// 	delay(1);
	   GPIOe->ODR = 0x0001;
	   delay(1000);
	   GPIOe->ODR =0;
}
	}
}
