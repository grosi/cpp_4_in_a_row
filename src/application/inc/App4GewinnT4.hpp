/**
 * \file        App4GewinnT4.hpp
 * \brief       Manages the hole game and the programm states.
 * \date        2014-03-29
 * \version     0.1
 * \author		Kevin Gerber
 */

#ifndef APP4GEWINNT4_HPP_
#define APP4GEWINNT4_HPP_

class Timer;
class Hardware;
class Communication;
class State;
class Game;
class Player;

#include "Game.hpp"

/**
 * \class	App4GewinnT4
 * \brief	This is the main class who is instanced in the main function to run the application.
 * \todo	Inherit from TimerListener!
 */
class App4GewinnT4 {
	private:
		Timer *objTimer;
		Hardware *objHardware;
		Communication *objCommunication;

	private:
		State *currentState;
		Game *currentGame;

	private:
		playerLineUp_t gameMode;

	public:
		/* Constructor and destructor */
		App4GewinnT4();
		~App4GewinnT4();

		/* Public methods */
		State* getCurrentState(void);
		void nextState(State *next_state);
		void gameCreate(playerLineUp_t line_up);
		void gameDestroy(void);

		bool getGameModeMultiplayer(void) { return (gameMode != PLAYER_SELF_BOT); }
		Player* getCurrentPlayer(void);
		void newGameRound(void);

		/* Inherit methods */
		void timerEvent(void);
};

#endif /* APP4GEWINNT4_HPP_ */
