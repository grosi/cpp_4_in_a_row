/**
 * \file        Player.cpp
 * \brief       abstract class for the different types of players (human, bot or remote)
 * \date        2014-03-29
 * \version     0.0.1
 *
 * \addtogroup  player
 * \brief       abstract class with common player characteristics
 * @{
 */

#include "inc/Player.hpp"

Player::Player(Game* game): current_game(game) {
	// TODO Auto-generated constructor stub

}

Player::~Player() {
	// TODO Auto-generated destructor stub
}


uint8_t Player::eventCommStonePlace(uint8_t column) {
	return 0;
}

/**
 * @}
 */

