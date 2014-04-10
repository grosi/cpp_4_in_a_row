/**
 * \file        Game.cpp
 * \brief       game-control class
 * \date        2014-03-29
 * \version     0.0.1
 *
 * \addtogroup  game
 * \brief       class for game controlling
 * @{
 */

#include "Player.hpp"
#include "inc/Game.hpp"

Game::Game(App4GewinnT4 app, Player* player_1, Player* player_2) {
	this->app = app;
	this->player_1 = player_1;
	this->player_2 = player_2;
	current_player = &player_1;

}

Game::~Game() {


}

/**
 * \fn		getCurrentPlayer
 * \brief	give back a reference to the current player
 *
 * \return 	reference to current player
 */
Player* Game::getCurrentPlayer() {
	return *current_player;
}


/**
 * \fn		newGameRound
 * \brief	draw gamefield new request
 */
void Game::newGameRound() {

}

/**
 * @}
 */
