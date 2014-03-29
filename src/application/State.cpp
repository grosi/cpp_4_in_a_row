/**
 * \file        State.cpp
 * \brief       Interface off all program states.
 * \date        2014-03-29
 * \version     0.1
 * \author		Kevin Gerber
 *
 * \addtogroup  State
 * \brief		This is the module group of all program states.
 * @{
 */
#include "State.hpp"

/**
 * \brief	Constructor.
 * \param	hw_timer Pointer to the single hardware timer.
 */
State::State(App4GewinnT4 *owner) : context(owner) {

}

/**
 * \brief	Deconstructor.
 */
State::~State() {

}

/**
 * @}
 */
