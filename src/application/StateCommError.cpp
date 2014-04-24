/**
 * \file        StateCommError.cpp
 * \brief       This is the error state of the application.
 * \date        2014-03-29
 * \version     0.1
 * \author		Kevin Gerber
 *
 * \addtogroup  State
 * @{
 */

#include "State.hpp"
#include "StateCommError.hpp"

#include "StateMenu.hpp"

/**
 * \brief	Constructor.
 */
StateCommError::StateCommError(App4GewinnT4 *owner) : State(owner) {
	stateName = "State: Communication Error";
}

/**
 * \brief	Deconstructor.
 */
StateCommError::~StateCommError() {

}

/**
 * \brief	A new connection to the remote CARME Kit is detected.
 * 			This event comes from the communication.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateCommError::commConnect(void) {
	/* No implementation needed */
}

/**
 * \brief	The Communication with the remote CARME Kit is broken up.
 * 			This event comes from the communication.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateCommError::commDisconnect(void) {
	/* No implementation needed */
}

/**
 * \brief	A game request from the remote CARME Kit is received.
 * 			This event comes from the communication.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateCommError::commGameReq(void) {
	/* No implementation needed */
}

/**
 * \brief	The remote CARME Kit accepted the game request. The game can startet now.
 * 			This event comes from the communication.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateCommError::commGameStart(void) {
	/* No implementation needed */
}

/**
 * \brief	The remote player wants to break up a running game.
 * 			This event comes from the communication.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateCommError::commGameEsc(void) {
	/* No implementation needed */
}

/**
 * \brief	The remote player sets a stone.
 * 			This event comes from the communication.
 * \param	col is the column number, where the stone was set.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateCommError::commStonePlace(uint8_t col) {
	/* No implementation needed */
}

/**
 * \brief	An intern communication failure occurs.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateCommError::commError(void) {
	/* No implementation needed */
}

/**
 * \brief	Rising edge of the enter button. This event comes from the hardware.
 */
void StateCommError::hwBtnEntr(void) {
	/* Change to the menu state */
	context->nextState(new StateMenu(context));
}

/**
 * \brief	Rising edge of the escape button. This event comes from the hardware.
 */
void StateCommError::hwBtnEsc(void) {
	/* Change to the menu state */
	context->nextState(new StateMenu(context));
}

/**
 * \brief	The potentiometer value is changed. This event comes from the hardware.
 * \param	pot_value is the new value of the potentiometer.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateCommError::hwPot(uint32_t pot_value) {
	/* No implementation needed */
}

/**
 * \brief	Event from the timer.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateCommError::timerEvent(void) {
	/* No implementation needed */
}

/**
 * \brief	The whole LCD Screen must be repainted.
 */
void StateCommError::paintFullScreen(void) {

}

/**
 * @}
 */
