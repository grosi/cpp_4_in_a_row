/**
 * \file        Remote.hpp
 * \brief       class for the remote-player
 * \date        2014-03-29
 * \version     0.0.1
 *
 * \addtogroup  remote
 * @{
 */

#ifndef REMOTE_HPP_
#define REMOTE_HPP_

#include "Player.hpp"

class Game;

//class Player;

class Remote : public Player {
public:
	Remote(Game*);
	virtual ~Remote();

	uint8_t eventCommStonePlace(uint8_t);
};

#endif /* REMOTE_HPP_ */

/**
 * @}
 */
