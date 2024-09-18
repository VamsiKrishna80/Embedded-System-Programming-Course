/******************************* PA 0 to 8 for data line D0 to D8 *************************/
/******************************* PB 0 and 1 for rs and en R/w is connected to gnd ***********************/

#include "STM32F407xx.h"

void LCD_INIT(void);
void LCD_data(unsigned char data);
void LCD_cmd(unsigned char cmd);
void LCD_string(char *str, char length);
void delayMs(int n);
void GPIOAB_INIT(void);

/**************************************** GPIO_INIT ****************************************************************/
GPIO_R *GPIOA = gpioa;
GPIO_R *GPIOB = gpiob;

/****************************************  Delay function (16 MHz CPU clock) ****************************************/
void delayMs(int n) {
    int i;
    for (; n > 0; n--)
       for (i = 0; i < 3195; i++) ;
}

int main() {

/******************* Enable the clock for GPIOA and GPIOB ************************************************/
		    GPIOA_PCLK_EN();
		    GPIOB_PCLK_EN();

/**************************************** Initialize LCD *******************************************/
            LCD_INIT();

    while (1) {
        LCD_cmd(0x80);                       // Set cursor to the first line
        LCD_string("Embedded", 8);

        LCD_cmd(0xC0);                        // Set cursor to the second line
        LCD_string("System", 6);
    }
}

/*********************  Sending data to LCD  ****************************************************/
void LCD_data(unsigned char data) {

    GPIOB->ODR |= (1 << 0);                   // RS = 1 (data mode)
    GPIOA->ODR = data;                        // Send data to D0-D7 pins

    GPIOB->ODR |= (1 << 1);                   // EN = 1 (Enable the LCD)
    delayMs(1);
    GPIOB->ODR &= ~(1 << 1);                  // EN = 0 (Disable the LCD)

    delayMs(4);                               // Small delay for processing
}

/***********************   Sending commands to LCD **********************************************/
void LCD_cmd(unsigned char cmd) {

    GPIOB->ODR &= ~(1 << 0);                   // RS = 0 (command mode)
    GPIOA->ODR = cmd;                          // Send command to D0-D7 pins

    GPIOB->ODR |= (1 << 1);                    // EN = 1 (Enable the LCD)
    delayMs(1);
    GPIOB->ODR &= ~(1 << 1);                   // EN = 0 (Disable the LCD)

    delayMs(4);                                // Small delay for processing
}

/*******************************  Send a string to the LCD **************************************/
void LCD_string(char *str, char length) {
    for (int i = 0; i < length; i++) {
        LCD_data(*str++);
    }
}

/********************************************    LCD initialization ******************************************************/
void LCD_INIT(void) {

    // LCD initialization sequence
	delayMs(30);                                       // Wait for LCD to power up
	    LCD_cmd(0x38);                                 // 8-bit mode, 2 lines
	    delayMs(5);                                    // Wait for the command to take effect
	    LCD_cmd(0x0C);                                 // Display ON, cursor OFF
	    delayMs(5);                                    // Short delay
	    LCD_cmd(0x06);                                 // Auto-increment cursor
	    delayMs(5);                                    // Short delay
	    LCD_cmd(0x01);                                 // Clear display
	    delayMs(2);                                    // Delay after clearing display
}
void GPIOAB_INIT(void)
{
	// Initialize GPIOA (PA0 and PA7 as output for D0 to D7)
	     GPIOA->MODER &= ~(0x0000FFFF);                       // Clear mode for PA0-PA7
	     GPIOA->MODER |= 0x00005555;                          // Set PA0-PA7 to output mode

	// Initialize GPIOB (PB0 and PB1 as output for RS and EN)
	     GPIOB->MODER &= ~(0x0000000F);                        // Clear mode for PB0 and PB1
	     GPIOB->MODER |= 0x00000005;                           // Set PB0, PB1 as output mode
}
