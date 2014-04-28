/**
 * \file        App4GewinnT4.cpp
 * \brief       Manages the hole game and the programm states.
 * \date        2014-03-29
 * \version     0.1
 * \author		Kevin Gerber
 */

#include "App4GewinnT4.hpp"
#include "StateMenu.hpp"

#include "Timer.h"
#include "Hardware.h"
#include "Communication.h"

#include "Player.hpp"
#include "Self.hpp"
#include "Bot.hpp"
#include "Remote.hpp"

/**
 * \brief	Constructor.
 */
App4GewinnT4::App4GewinnT4() {
	/* Add the communication and the hardware timer listener */
	objTimer = Timer::getInstance();

	/* Hardware */
	objHardware = Hardware::getInstance();
	objTimer->addActionListener();

	/* UART communication */
	objCommunication = Communication::getInstance();
	objTimer->addActionListener();

	/* Makes the first state */
	currentState = new StateMenu(this);

	/* Draw the first screen */
	currentState->paintFullScreen();
}

/**
 * \brief	Destructor.
 */
App4GewinnT4::~App4GewinnT4() {
	/* Remove the communication and the hardware timer listener */
	objTimer->removeActionListener();
	objTimer->removeActionListener();

	/* Deletes the current state */
	delete currentState;
}

/**
 * \brief	Get a reference to the current state.
 * \return	Reference to the current state.
 */
State* App4GewinnT4::getCurrentState(void) {
	return currentState;
}

/**
 * \brief	Change the current state.
 * \param	next_state is the new program state.
 */
void App4GewinnT4::nextState(State *next_state) {
	/* First delete the old state */
	delete currentState;

	/* Set the new state */
	currentState = next_state;

	/* Repaint the Screen */
	currentState->paintFullScreen();
}

/**
 * \brief	Generate a new game.
 * \param[in]	line_up configures the two players.
 */
void App4GewinnT4::gameCreate(playerLineUp_t line_up) {
	/* Make a new game */
	currentGame = new Game(this, line_up);
}

/**
 * \brief	Destroys an game.
 */
void App4GewinnT4::gameDestroy(void) {
	delete currentGame;

	/// \todo testen ob noetig!
	currentGame = NULL;
}

/**
 * \brief	Timer interrupt, which is called each 10ms.
 */
void App4GewinnT4::timerEvent(void) {
	currentState->timerEvent();
}

/**
 * \brief	Gets a pointer to the current player.
 * \return	Pointer to the current Player. NULL if no game is running.
 */
Player* App4GewinnT4::getCurrentPlayer(void) {
	Player *current_player = NULL;

	if (currentGame != NULL) {
		current_player = currentGame->getCurrentPlayer();
	}

	return current_player;
}

/**
 * \brief	Starts a new game round.
 */
void App4GewinnT4::newGameRound(void) {
	if (currentGame != NULL) {
		currentGame->newGameRound();
	}
}
