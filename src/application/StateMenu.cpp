/**
 * \file        StateMenu.cpp
 * \brief       This is the menu state of the application.
 * \date        2014-03-29
 * \version     0.1
 * \author		Kevin Gerber
 *
 * \addtogroup  State
 * @{
 */

#include "State.hpp"
#include "StateMenu.hpp"

#include "StateGame.hpp"
#include "StateCommError.hpp"

#include "Game.hpp"
#include "Player.hpp"

/**
 * \brief	Constructor of the menu state.
 */
StateMenu::StateMenu(App4GewinnT4 *owner) : State(owner) {
	stateName = "State: Menu";
}

/**
 * \brief	Destructor of the menu state.
 */
StateMenu::~StateMenu() {

}

/**
 * \brief	A new connection to the remote CARME Kit is detected.
 * 			This event comes from the communication.
 */
void StateMenu::commConnect(void) {
	/* Repaint hole screen */
	this->paintFullScreen();
}

/**
 * \brief	The Communication with the remote CARME Kit is broken up.
 * 			This event comes from the communication.
 */
void StateMenu::commDisconnect(void) {
	/* Repaint hole screen */
	this->paintFullScreen();
}

/**
 * \brief	A game request from the remote CARME Kit is received.
 * 			This event comes from the communication.
 */
void StateMenu::commGameReq(void) {
	/* Repaint hole screen */
	this->paintFullScreen();
}

/**
 * \brief	The remote CARME Kit accepted the game request. The game can startet now.
 * 			This event comes from the communication.
 */
void StateMenu::commGameStart(void) {
	Player *player1;
	Player *player2;

	/* Allocate the players */
	/* Spieler 1 Remote (Timer), Spieler 2 ich */
	//player1 = new Remote();

	/* Starts an new game. */
	//currentGame = new Game(context, player1, player2);

	/* Change to the game state */
	context->nextState(new StateGame(context));
}

/**
 * \brief	The remote player wants to break up a running game.
 * 			This event comes from the communication.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateMenu::commGameEsc(void) {

}

/**
 * \brief	The remote player sets a stone.
 * 			This event comes from the communication.
 * \param	col is the column number, where the stone was set.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateMenu::commStonePlace(uint8_t col) {

}

/**
 * \brief	An intern communication failure occurs.
 */
void StateMenu::commError(void) {
	/* Change to the game state */
	context->nextState(new StateCommError(context));
}

/**
 * \brief	Rising edge of the enter button. This event comes from the hardware.
 */
void StateMenu::hwBtnEntr(void) {

}

/**
 * \brief	Rising edge of the escape button. This event comes from the hardware.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateMenu::hwBtnEsc(void) {

}

/**
 * \brief	The potentiometer value is changed. This event comes from the hardware.
 * \param	pot_value is the new value of the potentiometer.
 */
void StateMenu::hwPot(uint32_t pot_value) {

}

/**
 * \brief	Event from the timer.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateMenu::timerEvent(void) {

}

/**
 * \brief	The whole LCD Screen must be repainted.
 */
void StateMenu::paintFullScreen(void) {

}

/**
 * @}
 */
