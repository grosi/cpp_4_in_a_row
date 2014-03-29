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
class State;
class Game;

/**
 * \class	App4GewinnT4
 * \brief	This is the main class who is instanced in the main function to run the application.
 * \todo	Inherit from TimerListener!
 */
class App4GewinnT4 {
	private:
		Timer *objTimer;
		State *currentState;
		Game *game;

	public:
		/* Constructor and deconstructor */
		App4GewinnT4(Timer *hw_timer);
		~App4GewinnT4();

		/* Public methods */
		State* getCurrentState(void);
		void nextState(State *next_state);
		void gameCreate(void);
		void gameDestroy(void);

		/* Inherit methods */
		void timerEvent(void);
};

#endif /* APP4GEWINNT4_HPP_ */
