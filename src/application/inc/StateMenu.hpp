/**
 * \file        StateMenu.hpp
 * \brief       This is the menu state of the application.
 * \date        2014-03-29
 * \version     0.1
 * \author		Kevin Gerber
 *
 * \addtogroup  State
 * @{
 */

#ifndef STATEMENU_HPP_
#define STATEMENU_HPP_

#include <stdint.h>
#include "App4GewinnT4.hpp"
#include "State.hpp"

/**
 * \class	StateMenu
 * \brief	This class represent the menu state.
 */
class StateMenu : public State {
	private:

	public:
		/* Constructor and destructor */
		StateMenu(App4GewinnT4 *owner);
		~StateMenu();

		/* Inherit methods for the communication */
		void commConnect(void);
		void commDisconnect(void);
		void commGameReq(void);
		void commGameStart(void);
		void commGameEsc(void);
		void commStonePlace(uint8_t col);
		void commError(void);

		/* Inherit methods for the hardware inputs */
		void hwBtnEntr(void);
		void hwBtnEsc(void);
		void hwPot(uint32_t pot_value);

		/* Inherit methods for the timer event */
		void timerEvent(void);

		/* Inherit methods for the state mechanisms */
		void paintFullScreen(void);
};

#endif /* STATEMENU_HPP_ */

/**
 * @}
 */
