/**
 * \file        App4GewinnT4.cpp
 * \brief       Manages the hole game and the programm states.
 * \date        2014-03-29
 * \version     0.1
 * \author		Kevin Gerber
 */

#include "App4GewinnT4.hpp"
#include "State.hpp"

/**
 * \brief	Constructor.
 * \param	hw_timer Pointer to the single hardware timer.
 */
App4GewinnT4::App4GewinnT4(Timer *hw_timer) : objTimer(hw_timer) {
	/* Makes the first state */
	//currentState = new StateMenu(this);
}

/**
 * \brief	Deconstructor.
 */
App4GewinnT4::~App4GewinnT4() {
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
}

/**
 * \brief	Generate a new game.
 * \todo	Implement.
 */
void App4GewinnT4::gameCreate(void) {

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
