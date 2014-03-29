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

/**
 * \brief	Constructor.
 */
StateGame::StateGame(App4GewinnT4 *owner) : State(owner) {
	stateName = "State: Game";
}

/**
 * \brief	Deconstructor.
 */
StateGame::~StateGame() {

}

/**
 * \brief	A new connection to the remote CARME Kit is detected.
 * 			This event comes from the communication.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateGame::commConnect(void) {

}

/**
 * \brief	The Communication with the remote CARME Kit is broken up.
 * 			This event comes from the communication.
 */
void StateGame::commDisconnect(void) {

}

/**
 * \brief	A game request from the remote CARME Kit is received.
 * 			This event comes from the communication.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateGame::commGameReq(void) {

}

/**
 * \brief	The remote CARME Kit accepted the game request. The game can startet now.
 * 			This event comes from the communication.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateGame::commGameStart(void) {

}

/**
 * \brief	The remote player wants to break up a running game.
 * 			This event comes from the communication.
 */
void StateGame::commGameEsc(void) {

}

/**
 * \brief	The remote player sets a stone.
 * 			This event comes from the communication.
 * \param	col is the column number, where the stone was set.
 */
void StateGame::commStonePlace(uint8_t col) {

}

/**
 * \brief	An intern communication failure occurs.
 */
void StateGame::commError(void) {

}

/**
 * \brief	Rising edge of the enter button. This event comes from the hardware.
 */
void StateGame::hwBtnEntr(void) {

}

/**
 * \brief	Rising edge of the escape button. This event comes from the hardware.
 */
void StateGame::hwBtnEsc(void) {

}

/**
 * \brief	The potentiometer value is changed. This event comes from the hardware.
 * \param	pot_value is the new value of the potentiometer.
 */
void StateGame::hwPot(uint32_t pot_value) {

}

/**
 * \brief	Event from the timer.
 */
void StateGame::timerEvent(void) {

}

/**
 * \brief	The whole LCD Screen must be repainted.
 */
void StateGame::paintFullScreen(void) {

}

/**
 * @}
 */
