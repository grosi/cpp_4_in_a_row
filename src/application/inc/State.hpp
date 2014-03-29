/**
 * \file        State.hpp
 * \brief       Interface off all program states.
 * \date        2014-03-29
 * \version     0.1
 * \author		Kevin Gerber
 *
 * \addtogroup  State
 * \brief		This is the module group of all program states.
 * @{
 */

#ifndef STATE_HPP_
#define STATE_HPP_

#include <stdint.h>
#include <string>
#include "App4GewinnT4.hpp"

/**
 * \class	State
 * \brief	This is the interface of all states used in the application.
 */
class State {
	private:
		App4GewinnT4 *context;

	protected:
		std::string stateName;

	public:
		/* Constructor and deconstructor */
		State(App4GewinnT4 *owner);
		virtual ~State();

		/* Virtual methods for the communication */
		virtual void commConnect(void);
		virtual void commDisconnect(void);
		virtual void commGameReq(void);
		virtual void commGameStart(void);
		virtual void commGameEsc(void);
		virtual void commStonePlace(uint8_t col);
		virtual void commError(void);

		/* Virtual methods for the hardware inputs */
		virtual void hwBtnEntr(void);
		virtual void hwBtnEsc(void);
		virtual void hwPot(uint32_t pot_value);

		/* Virtual methods for the timer event */
		virtual void timerEvent(void);

		/* Virtual methods for the state mechanisms */
		virtual void paintFullScreen(void);
};

#endif /* STATE_HPP_ */

/**
 * @}
 */
