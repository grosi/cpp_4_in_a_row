/**
 * \file        StateCommError.hpp
 * \brief       This is the error state of the application.
 * \date        2014-03-29
 * \version     0.1
 * \author		Kevin Gerber
 *
 * \addtogroup  State
 * @{
 */

#ifndef STATECOMMERROR_HPP_
#define STATECOMMERROR_HPP_

#include <stdint.h>
#include "App4GewinnT4.hpp"
#include "State.hpp"

/**
 * \class	StateCommError
 * \brief	This class represent the error state. It is used if the communication fails.
 */
class StateCommError : public State {
	private:
		//String stateName;

	public:
		/* Constructor and deconstructor */
		StateCommError(App4GewinnT4 *owner);
		~StateCommError();

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

#endif /* STATECOMMERROR_HPP_ */

/**
 * @}
 */
