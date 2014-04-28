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

#include "Hardware.h"
#include "Communication.h"

#include "Game.hpp"
#include "Player.hpp"

#include "lcd.h"

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
	/* Starts an new game. */
	context->gameCreate(PLAYER_SELF_REMOTE);

	/* Change to the game state */
	context->nextState(new StateGame(context));
}

/**
 * \brief	The remote player wants to break up a running game.
 * 			This event comes from the communication.
 */
void StateMenu::commGameEsc(void) {
	/* Cancel a game request */
	/* Repaint hole screen */
	this->paintFullScreen();
}

/**
 * \brief	The remote player sets a stone.
 * 			This event comes from the communication.
 * \param	col is the column number, where the stone was set.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateMenu::commStonePlace(uint8_t col) {
	/* No implementation needed */
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
	Hardware *obj_hardware;
	Communication *obj_communication;

	obj_hardware = Hardware::getInstance();
	obj_communication = Communication::getInstance();

	if (obj_hardware->getPortValue() >= 4) {
		/* Cancel a open game request */
		if (!obj_communication->getStateGame()) {
			obj_communication->commTxGameEsc();
		}
		/* Singleplayer game */
		context->gameCreate(PLAYER_SELF_BOT);
		/* Change the state */
		context->nextState(new StateGame(context));
	}
	else {
		/* Multiplayer game */
		if (obj_communication->getStateGame()) {
			/* Send a game request */
			obj_communication->commTxGameReq();
			/* Repaint Screen */
			this->paintFullScreen();
		}
		else {
			/* Response the game request */
			obj_communication->commTxGameStart();
			/* Start multiplayer game */
			context->gameCreate(PLAYER_SELF_REMOTE);
			/* Change the state */
			context->nextState(new StateGame(context));
		}
	}
}

/**
 * \brief	Rising edge of the escape button. This event comes from the hardware.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateMenu::hwBtnEsc(void) {
	/* No implementation needed */
}

/**
 * \brief	The potentiometer value is changed. This event comes from the hardware.
 * \param	pot_value is the new value of the potentiometer.
 */
void StateMenu::hwPot(uint32_t pot_value) {
	/* Repaint hole screen for the options selector */
	this->paintFullScreen();
}

/**
 * \brief	Event from the timer.
 * \note	This state does not support this event. Therefore no implementation is needed.
 */
void StateMenu::timerEvent(void) {
	/* No implementation needed */
}

/**
 * \brief	The whole LCD Screen must be repainted.
 */
void StateMenu::paintFullScreen(void) {
	// Status Poti, Verbindung holen
	// Bildschirm zeichnen
	Hardware *obj_hardware;
	Communication *obj_communication;

	obj_hardware = Hardware::getInstance();
	obj_communication = Communication::getInstance();

	/* Clear screen */
	LCD_DrawRectF(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, GUI_COLOR_BLACK);

	/* Title */
	LCD_DisplayStringXY(10, 10, "4 GewinnT4");

	// Vielleicht doch besser eine Abstraktion mehr????

	/* Menu point: remote game */
	if (obj_hardware->getPortValue() < 4) {
		/* Active */
		//-------
		LCD_DrawRectF(60, 60, 60, 20, GUI_COLOR_DARK_GREY);
		LCD_DrawRect(60, 60, DISPLAY_WIDTH, DISPLAY_HEIGHT, GUI_COLOR_CYAN);
		if (obj_communication->getStateGame()) {
			LCD_DisplayStringXY(60, 60, "Request Remote Game");
		}
		else {
			LCD_DisplayStringXY(60, 60, "Start Remote Game");
		}
		//-----
	}
	else {
		/* Not active */
		//-------
		LCD_DrawRectF(60, 60, 60, 20, GUI_COLOR_DARK_GREY);
		LCD_DrawRect(60, 60, DISPLAY_WIDTH, DISPLAY_HEIGHT, GUI_COLOR_CYAN);
		if (obj_communication->getStateGame()) {
			LCD_DisplayStringXY(60, 60, "Request Remote Game");
		}
		else {
			LCD_DisplayStringXY(60, 60, "Start Remote Game");
		}
		//-----
	}

	/* Menu point: single game */
	if (obj_hardware->getPortValue() >= 4) {
		/* Active */
		//-------
		LCD_DrawRectF(60, 60, 60, 20, GUI_COLOR_DARK_GREY);
		LCD_DrawRect(60, 60, DISPLAY_WIDTH, DISPLAY_HEIGHT, GUI_COLOR_CYAN);
		LCD_DisplayStringXY(60, 60, "Start Single Game");
		//-----
	}
	else {
		/* Not active */
		//-------
		LCD_DrawRectF(60, 60, 60, 20, GUI_COLOR_DARK_GREY);
		LCD_DrawRect(60, 60, DISPLAY_WIDTH, DISPLAY_HEIGHT, GUI_COLOR_CYAN);
		LCD_DisplayStringXY(60, 60, "Start Single Game");
		//-----
	}
}

/**
 * @}
 */
