/**
 * \file        StateGame.cpp
 * \brief       This is the game state of the application.
 * \date        2014-03-29
 * \version     0.1
 * \author		Kevin Gerber
 *
 * \addtogroup  State
 * @{
 */

#include "State.hpp"
#include "StateGame.hpp"

#include "StateMenu.hpp"
#include "StateCommError.hpp"

#include "Communication.h"

#include "Player.hpp"

/**
 * \brief	Constructor.
 */
StateGame::StateGame(App4GewinnT4 *owner) : State(owner) {
	stateName = "State: Game";
}

/**
 * \brief	Destructor.
 */
StateGame::~StateGame() {

}

/**
 * \brief	A new connection to the remote CARME Kit is detected.
 * 			This event comes from the communication.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateGame::commConnect(void) {
	/* No implementation needed */
}

/**
 * \brief	The Communication with the remote CARME Kit is broken up.
 * 			This event comes from the communication.
 */
void StateGame::commDisconnect(void) {
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
void StateGame::commGameReq(void) {
	/* No implementation needed */
}

/**
 * \brief	The remote CARME Kit accepted the game request. The game can started now.
 * 			This event comes from the communication.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateGame::commGameStart(void) {
	/* No implementation needed */
}

/**
 * \brief	The remote player wants to break up a running game.
 * 			This event comes from the communication.
 */
void StateGame::commGameEsc(void) {
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
 */
void StateGame::commStonePlace(uint8_t col) {
	Player *current_player;

	/* Only needed in multiplayer mode */
	if (context->getGameModeMultiplayer()) {
		current_player = context->getCurrentPlayer();
		current_player->eventCommStonePlace(col);
	}
}

/**
 * \brief	An intern communication failure occurs.
 */
void StateGame::commError(void) {
	/* Change to the game state */
	context->nextState(new StateCommError(context));
}

/// \todo Vereinfachen Spalte übergeben. Dafür selber Corsor zeichnen oder dafür ne funktion!!!
/// Besprechung mit Simu.

/// \todo Statewechsel wenn spiel zu enden ist????

/**
 * \brief	Rising edge of the enter button. This event comes from the hardware.
 */
void StateGame::hwBtnEntr(void) {
	Player *current_player;

	current_player = context->getCurrentPlayer();
	current_player->eventHwBtnEnt();
}

/**
 * \brief	Rising edge of the escape button. This event comes from the hardware.
 */
void StateGame::hwBtnEsc(void) {
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
 */
void StateGame::hwPot(uint32_t pot_value) {
	Player *current_player;

	current_player = context->getCurrentPlayer();
	current_player->eventHwPot();
}

/**
 * \brief	Event from the timer.
 */
void StateGame::timerEvent(void) {
	Player *current_player;

	current_player = context->getCurrentPlayer();
	current_player->eventTimer();
}

/**
 * \brief	The whole LCD Screen must be repainted.
 */
void StateGame::paintFullScreen(void) {

}

/**
 * @}
 */
