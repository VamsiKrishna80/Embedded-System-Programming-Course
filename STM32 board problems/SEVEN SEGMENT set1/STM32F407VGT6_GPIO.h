/*
 * STM32F4VGT6_GPIO.h
 *
 *  Created on: Aug 18, 2024
 *      Author: vamsi
 */

#ifndef STM32F407VGT6_GPIO_H_
#define STM32F407VGT6_GPIO_H_
#include<stdint.h>

/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 */

#define GPIOA_BASEADDR         0X40020000
#define GPIOB_BASEADDR         0X40020400
#define GPIOC_BASEADDR         0X40020800
#define GPIOD_BASEADDR         0X40020C00
#define GPIOE_BASEADDR         0X40021000

typedef struct
{
	volatile uint32_t MODER;                        //GPIO port mode register
	volatile uint32_t OTYPER;                       //GPIO port output type register
	volatile uint32_t OSPEEDR;                      //GPIO port output speed register
	volatile uint32_t PUPDR;                        //GPIO port pull-up/pull-down register
	volatile uint32_t IDR;                          //GPIO port input data register
	volatile uint32_t ODR;                          //GPIO port output data register
	volatile uint32_t BSRR;                         //GPIO port bit set/reset register
	volatile uint32_t LCKR;                         //GPIO port configuration lock register
	volatile uint32_t AFR[2];                       //GPIO alternate function register 0 - LOW  /  1 - HIGH
}GPIO_R;

#endif /* STM32F407VGT6_GPIO_H_ */

