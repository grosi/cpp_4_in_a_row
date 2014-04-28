/**
 * \file        Bot.hpp
 * \brief       class for the AI
 * \date        2014-03-29
 * \version     0.0.1
 *
 * \addtogroup  bot
 * @{
 */

#ifndef BOT_HPP_
#define BOT_HPP_

#include "Player.hpp"

class Bot : public Player {
private:
	int timerCtr;

public:
	Bot(Game*);
	virtual ~Bot();

	void eventTimer();
};

#endif /* BOT_HPP_ */

/**
 * @}
 */
