/**
 * \file        StateResult.hpp
 * \brief       This is the result state of the application.
 * \date        2014-03-29
 * \version     0.1
 * \author		Kevin Gerber
 *
 * \addtogroup  State
 * @{
 */

#ifndef STATERESULT_HPP_
#define STATERESULT_HPP_

#include <stdint.h>
#include "App4GewinnT4.hpp"
#include "State.hpp"

/**
 * \class	StateResult
 * \brief	This class represent the game result state. It shows the
 * 			result and statistic of the played games.
 */
class StateResult : public State {
	private:
		//String stateName;

	public:
		/* Constructor and deconstructor */
		StateResult(App4GewinnT4 *owner);
		~StateResult();

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


#endif /* STATERESULT_HPP_ */

/**
 * @}
 */
