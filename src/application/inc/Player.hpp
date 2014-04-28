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
#include "Game.hpp"
//class Game;



class Player {
protected:
	std::string name;
	int gamesWinnerCtr;
	Game* current_game;

public:
	Player(Game*);
	virtual ~Player();

	void eventHwBtnEnt();
	void eventHwPot();
	uint8_t eventCommStonePlace(uint8_t);
	void eventTimer();
	virtual void drawStone();

};

#endif /* PLAYER_HPP_ */

/**
 * @}
 */
