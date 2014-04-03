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

/**
 * \brief	Constructor.
 * \param	hw_timer Pointer to the single hardware timer.
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
 * \todo	Implement.
 */
void App4GewinnT4::gameCreate(void) {
//	Player *player1;
//	Player *player2;
//
//	/* Allocate the players */
//
//	/* Make a new game */
//	game = new Game(player1, player2);
}

/**
 * \brief	Destroys an game.
 * \todo	Implementation.
 */
void App4GewinnT4::gameDestroy(void) {

}

/**
 * \brief	Timer interrupt, which is called each 10ms.
 */
void App4GewinnT4::timerEvent(void) {
	currentState->timerEvent();
}
