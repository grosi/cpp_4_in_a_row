/**
 * \file        Player.hpp
 * \brief       abstract class for the different types of players (human, bot or remote)
 * \date        2014-03-29
 * \version     0.0.1
 *
 * \addtogroup  player
 * @{
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>



class Player {
protected:
	std::string name;
	int gamesWinnerCtr;
	Game* owner;

public:
	Player(Game* game);
	virtual ~Player();

	void eventHwBtnEnt();
	void eventHwPot();
	void eventCommStonePlace();
	void eventTimer();
	virtual void drawStone();

};

#endif /* PLAYER_HPP_ */

/**
 * @}
 */
