/**
*****************************************************************************
**
**  File        : main.cpp
**
**  Abstract    : main function.
**
**  Functions   : main
**
**  Environment : Atollic TrueSTUDIO(R)
**                STMicroelectronics STM32F4xx Standard Peripherals Library
**
**  Distribution: The file is distributed “as is,” without any warranty
**                of any kind.
**
**  (c)Copyright Atollic AB.
**  You may use this file as-is or modify it according to the needs of your
**  project. This file may only be built (assembled or compiled and linked)
**  using the Atollic TrueSTUDIO(R) product. The use of this file together
**  with other tools than Atollic TrueSTUDIO(R) is not permitted.
**
*****************************************************************************
*/

/* Includes */
#include "stm32f4xx.h"
#include "application/TestClass.hpp"

#include "carme.h"
#include "carme_io1.h"
#include "lcd.h"

/* Private macro */

/* Private variables */
static const char* pcHello = "Hello freeRTOS";         /* welcome text        */
static const char* pcCounterText = "Task 1 cycle: ";   /* task 1 text         */

/* Private function prototypes */

/* Private functions */


/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
  int i = 1;

  char str[] = "Kevin kanns ;)";

  /**
  *  IMPORTANT NOTE!
  *  The symbol VECT_TAB_SRAM needs to be defined when building the project
  *  if code has been located to RAM and interrupts are used. 
  *  Otherwise the interrupt table located in flash will be used.
  *  See also the <system_*.c> file and how the SystemInit() function updates 
  *  SCB->VTOR register.  
  *  E.g.  SCB->VTOR = 0x20000000;  
  */

  CARME_Init();
	CARME_IO1_Init();
	CARME_IO1_LED_Set(0x0F,0xFF);


  LCD_Init();

  /* Display welcome text */
  LCD_DrawCircle(50,50,50,GUI_COLOR_BLUE);
  LCD_SetFont(&font_8x16B);
//  LCD_SetFont(&font_8x16);
  LCD_DisplayStringXY(140, 100, pcCounterText);
//  LCD_GetFont();

  /* TODO - Add your application code here */

  //TestClass test;

  /* Infinite loop */
  while (1)
  {
	i++;
  }
}
