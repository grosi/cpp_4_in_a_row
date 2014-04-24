/**
 * \file        StateResult.cpp
 * \brief       This is the result state of the application.
 * \date        2014-03-29
 * \version     0.1
 * \author		Kevin Gerber
 *
 * \addtogroup  State
 * @{
 */

#include "State.hpp"
#include "StateResult.hpp"

#include "StateMenu.hpp"
#include "StateGame.hpp"
#include "StateCommError.hpp"

#include "Communication.h"

/**
 * \brief	Constructor.
 */
StateResult::StateResult(App4GewinnT4 *owner) : State(owner) {
	stateName = "State: Result";
}

/**
 * \brief	Destructor.
 */
StateResult::~StateResult() {

}

/**
 * \brief	A new connection to the remote CARME Kit is detected.
 * 			This event comes from the communication.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateResult::commConnect(void) {
	/* No implementation needed */
}

/**
 * \brief	The Communication with the remote CARME Kit is broken up.
 * 			This event comes from the communication.
 */
void StateResult::commDisconnect(void) {
	/* Only needed in multiplayer mode */
	if (context->getGameModeMultiplayer()) {
		/* stop the game */
		context->gameDestroy();
		/*! \todo Error Message */
		context->nextState(new StateCommError(context));
	}
}

/**
 * \brief	A game request from the remote CARME Kit is received.
 * 			This event comes from the communication.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateResult::commGameReq(void) {
	/* No implementation needed */
}

/**
 * \brief	The remote CARME Kit accepted the game request. The game can startet now.
 * 			This event comes from the communication.
 */
void StateResult::commGameStart(void) {
	/* Only needed in multiplayer mode */
	if (context->getGameModeMultiplayer()) {
		/* Starts a new round */
		context->newGameRound();

		/* Change into game state */
		context->nextState(new StateGame(context));
	}
}

/**
 * \brief	The remote player wants to break up a running game.
 * 			This event comes from the communication.
 */
void StateResult::commGameEsc(void) {
	/* Only needed in multiplayer mode */
	if (context->getGameModeMultiplayer()) {
		/* Stop the game */
		context->gameDestroy();
		/* Change into menu state */
		context->nextState(new StateMenu(context));
	}
}

/**
 * \brief	The remote player sets a stone.
 * 			This event comes from the communication.
 * \param	col is the column number, where the stone was set.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateResult::commStonePlace(uint8_t col) {
	/* No implementation needed */
}

/**
 * \brief	An intern communication failure occurs.
 */
void StateResult::commError(void) {
	/* Change to the game state */
	context->nextState(new StateCommError(context));
}

/**
 * \brief	Rising edge of the enter button. This event comes from the hardware.
 */
void StateResult::hwBtnEntr(void) {
	/* In multiplier mode send the message to the remote */
	if (context->getGameModeMultiplayer()) {
		Communication *obj_communication;

		obj_communication = Communication::getInstance();
		obj_communication->commTxGameStart();
	}

	/* Starts a new game round */
	context->newGameRound();
	/* Change into game state */
	context->nextState(new StateGame(context));
}

/**
 * \brief	Rising edge of the escape button. This event comes from the hardware.
 */
void StateResult::hwBtnEsc(void) {
	/* In multiplier mode send the escape message */
	if (context->getGameModeMultiplayer()) {
		Communication *obj_communication;

		obj_communication = Communication::getInstance();
		obj_communication->commTxGameEsc();
	}

	/* Stop the game */
	context->gameDestroy();
	/* Change into menu state */
	context->nextState(new StateMenu(context));
}

/**
 * \brief	The potentiometer value is changed. This event comes from the hardware.
 * \param	pot_value is the new value of the potentiometer.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateResult::hwPot(uint32_t pot_value) {
	/* No implementation needed */
}

/**
 * \brief	Event from the timer.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateResult::timerEvent(void) {
	/* No implementation needed */
}

/**
 * \brief	The whole LCD Screen must be repainted.
 */
void StateResult::paintFullScreen(void) {

}

/**
 * @}
 */
