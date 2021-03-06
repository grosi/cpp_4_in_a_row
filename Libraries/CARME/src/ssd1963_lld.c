/**
 *****************************************************************************
 * @addtogroup	CARME
 * @{
 * @addtogroup	CARME_LCD
 * @{
 * @defgroup	CARME_LCD_CTRL CTRL
 * @brief		CARME-M4 LCD Low level driver
 * @{
 *
 * @file		ssd1963_lld.c
 * @version		1.0
 * @date		2012-10-10
 * @author		rct1
 *
 * @brief		Low level driver for the SSD1963 Graphic-Controller.
 *
 *****************************************************************************
 * @copyright
 * @{
 *
 * This software can be used by students and other personal of the Bern
 * University of Applied Sciences under the terms of the MIT license.
 * For other persons this software is under the terms of the GNU General
 * Public License version 2.
 *
 * Copyright &copy; 2013, Bern University of Applied Sciences.
 * All rights reserved.
 *
 *
 * ##### MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 * ##### GNU GENERAL PUBLIC LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA  02110-1301, USA.
 *
 * @}
 *****************************************************************************
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*----- Header-Files -------------------------------------------------------*/
#include <stdint.h>					/* Standard integer formats				*/
#include <carme.h>

/*----- Macros -------------------------------------------------------------*/
/**
 * \brief	SSD1963 command and data register base address.
 */
#define GL_LCD_BASE		(FSMC_LCD_SSD1963_BASE)

/**
 * \brief	SSD1963 command and data register.
 */
#define GL_LCD			((SSD1963_T *) (GL_LCD_BASE))

/**
 * \brief	LCD Background light GPIO.
 */
#define GUI_GPIO_BACKLIGHT		GPIOH, GPIO_Pin_10

/*----- Data types ---------------------------------------------------------*/
/**
 * \struct	_SSD1963_T
 * \typedef	SSD1963_T
 * \brief	SSD1963 command and data register structure.
 */
typedef struct _SSD1963_T {
	__IO uint16_t CMD;
	__IO uint16_t DATA;
} SSD1963_T;

/**
 * \brief	LCD Port and Pin association
 */
static CARME_Port_Pin_t LCD_Port_Pin[] = {
        { GUI_GPIO_BACKLIGHT, GPIO_Mode_OUT },	/**< LCD Backlight			*/
        { CARME_AGPIO_9, GPIO_Mode_IN },		/**< LCD/VGA				*/
};

/*----- Function prototypes ------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/

/*----- Implementation -----------------------------------------------------*/
/**
 *****************************************************************************
 * \brief		Initialize the communication interface to the SSD1963 LCD-
 *				Controller.
 *
 * \return		None
 *****************************************************************************
 */
void SSD1963_LLD_Init(void) {

	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;

	CARME_GPIO_Init(LCD_Port_Pin, &GPIO_InitStruct,
	                sizeof(LCD_Port_Pin) / sizeof(CARME_Port_Pin_t));

	GPIO_WriteBit(GUI_GPIO_BACKLIGHT, 1);
}

/**
 *****************************************************************************
 * \brief		Write command to display controller.
 *
 * \param[in]	cmd		command to write.
 * \return		None
 *****************************************************************************
 */
inline void SSD1963_WriteCommand(uint16_t cmd) {
	GL_LCD->CMD = cmd;
}

/**
 *****************************************************************************
 * \brief		Write data to display controller.
 *
 * \param[in]	data	ram data to write.
 * \return		None
 *****************************************************************************
 */
inline void SSD1963_WriteData(uint16_t data) {
	GL_LCD->DATA = data;
}

/**
 *****************************************************************************
 * \brief		Read data from the display controller.
 *
 * \return		16 Bit value
 *****************************************************************************
 */
inline uint16_t SSD1963_ReadData(void) {
	return GL_LCD->DATA;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 * @}
 * @}
 */
