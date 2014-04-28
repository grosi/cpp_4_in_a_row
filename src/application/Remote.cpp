/**
 * \file        Remote.cpp
 * \brief       class for the remote-player
 * \date        2014-03-29
 * \version     0.0.1
 *
 * \addtogroup  remote
 * \brief       remote player functionalities
 * @{
 */

#include "Player.hpp"
#include "Remote.hpp"
#include "Game.hpp"

Remote::Remote(Game* game): Player(game){
	// TODO Auto-generated constructor stub

}

Remote::~Remote() {
	// TODO Auto-generated destructor stub
}


uint8_t Remote::eventCommStonePlace(uint8_t column) {
	current_game->stonePlace(column);

	return current_game->field->checkWinner();
}

/**
 * @}
 */
