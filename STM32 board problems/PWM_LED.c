  /*    1.configuring the output pin
                    a). select the output mode by writing the CCxS (x = channel number) bits in CCMR2 register
                    b).  select the polarity by writing CCxP bit in CCER register

           2. select the PWM mode( PWM1 or PWM2) by writing OCxM bits in CCMRx

          3.Program the Perioed and the duty cycle respectively in ARR and CCRx Registers

          4.SET the preload bit in CCMRx register and the ARPE bit in CR1 register

          5.Select the counting mode
                   a) PWM edge aligned mode: the count must be configured up counter or down counting.
                   b) PWM center Aligned mode: The counter mode must be center aligned counting mode (CMS bits differnt from 00)
                   c) Selecting Upcounter in DIRECTION bit '0' for UPCOUNTER and '1' for DOWNCOUNTER

          6. Enable the capture compare

          7. Enable the counter

*/

#include"STM32F407xx.h"
#define period 250                                                              // Total ON time + OFF time
//#define duty_cycle 20                                                    // ON Time
#define CC4S_OUPUTMODE ~0x0300                         // CC4S_OUPUTMODE
#define CC4P_ACTIVEHIGH ~0x0200                          // CC4P_ACTIVEHIGH
#define OC4M_PWM1 0x6000                                        //OC4M_PWM1
#define OC4PE 1<<11                                                      // OC4PE
#define ARPE 1<<7
#define Edge_Aligned ~0x0060
#define DIR_UP ~0x0010
#define CC4P 1<<12
#define CEN 1<<0
int main()
{
/***********************************************************************************************************/
     //                                                     Enabling Timer4 and GPIOD clock source
/**********************************************************************************************************/
    GPIOD_PCLK_EN();
    TIMER4_PCLK_EN();

/**********************************************************************************************************/
 //                                                       Configuring PD15 As TIMER4 Channel4
/**********************************************************************************************************/

    GPIO_R *gpiod = GPIOD;
    gpiod->MODER |= 1<<31;                                                                                                                                                                                           // Alternate function mode
    gpiod->AFR[1] |= 1<<29;                                                                                                                                                                                            // Selecting ALTERNETE FUNCTION 2 for timer4 channel 4
 
/**********************************************************************************************************/
  //                                                                 1.configuring the output pin
/**********************************************************************************************************/

     TIMER4->CCMR2 &=CC4S_OUPUTMODE;                                                                                                                                                          // select the output mode by writing the CCxS (x = channel number) bits in CCMR2 register
    TIMER4->CCER  &=CC4P_ACTIVEHIGH;                                                                                                                                                              // select the polarity by writing CCxP bit in CCER register

/**********************************************************************************************************/
    //                                        2.select the PWM mode( PWM1 or PWM2) by writing OCxM bits in CCMRx
/**********************************************************************************************************/


    TIMER4->CCMR2 |=OC4M_PWM1;

    /*110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
    else inactive. In downcounting, channel 1 is inactive (OC1REF=‘0) as long as
    TIMx_CNT>TIMx_CCR1 else active (OC1REF=1).
    111: PWM mode 2 - In upcounting, channel 1 is inactive as long as TIMx_CNT<TIMx_CCR1
    else active. In downcounting, channel 1 is active as long as TIMx_CNT>TIMx_CCR1 else
    inactive
    */

/**********************************************************************************************************/
    //                                  3.Program the Perioed and the duty cycle respectively in ARR and CCRx Registers
/**********************************************************************************************************/

    TIMER4->PSC = 160;                                                                                                                                                                                                      // Setting internal clk source 16Mhz to 100khz each tick having 1 millisecond
    TIMER4->ARR = period;                                                                                                                                                                                                 // total on and off time

/**********************************************************************************************************/
    // 4.SET the preload bit in CCMRx register and the ARPE bit in CR1 register
/**********************************************************************************************************/

    TIMER4->CCMR2 |= OC4PE;
    TIMER4->CR1 |=ARPE;

 /**********************************************************************************************************/

     * 5.Select the counting mode
     * a) PWM edge aligned mode: the count must be configured up counter or down counting.
     * b) PWM center Aligned mode: The counter mode must be center aligned counting mode (CMS bits differnt from 00)

/**********************************************************************************************************/

    TIMER4->CR1 &=Edge_Aligned;
    TIMER4->CR1 &= DIR_UP;                                                                                                                                                                                        //Selecting Upcounter in DIRECTION bit '0' for UPCOUNTER and '1' for DOWNCOUNTER

/**********************************************************************************************************/
    //6. Enable the capture compare
/**********************************************************************************************************/

    TIMER4->CCER |= CC4P;

/**********************************************************************************************************/
    //7. Enable the counter
/**********************************************************************************************************/

    TIMER4->CR1 |= CEN;
   	while(1)
   	{
   		for(int16_t duty_cycle = 0; duty_cycle< period;duty_cycle++)
   		{
   	 TIMER4->CCR4 = duty_cycle;
   	 for(int16_t j=0;j<10000;j++);
   	    }
   		for(int16_t duty_cycle = period; duty_cycle> 0;duty_cycle--)
   		   		{
   		   	 TIMER4->CCR4 = duty_cycle;
   		   	 for(int16_t j=0;j<10000;j++);
   		   	    }
      	 for(int16_t j=0;j<20000;j++);
   	}
}
