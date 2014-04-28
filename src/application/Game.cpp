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
#include "Game.hpp"
#include "Player.hpp"
#include "Self.hpp"
#include "Remote.hpp"
#include "Bot.hpp"

Game::Game(App4GewinnT4* app, playerLineUp_t line_up) {
	Self test(this);
	player1 = &test;
	this->mainApp = app;

	/* player setup */
	switch(line_up)
	{
	case PLAYER_SELF_REMOTE:
		player1 = new Self(this);
		player2 = new Remote(this);
		currentPlayer = &player1;
		break;
	case PLAYER_REMOTE_SELF:
		player1 = new Remote(this);
		player2 = new Self(this);
		currentPlayer = &player1;
		break;
	case PLAYER_SELF_BOT:
		player1 = new Self(this);
		player2 = new Bot(this);
		currentPlayer = &player1;
		break;
	case PLAYER_BOT_SELF:
		player1 = new Bot(this);
		player2 = new Self(this);
		currentPlayer = &player1;
		break;
	default:
		currentPlayer = NULL;
	}
}

Game::~Game() {

	delete player1;
	delete player2;
}

/**
 * \fn		getCurrentPlayer
 * \brief	give back a reference to the current player
 *
 * \return 	reference to current player
 */
Player* Game::getCurrentPlayer() {
	return *currentPlayer;
}


/**
 * \fn		newGameRound
 * \brief	draw gamefield new request
 */
void Game::newGameRound() {

	if(field != NULL) {
		delete field;
	}

	field = new GameField();

	this->roundCtr++;
}


/**
 * \fn		stonePlace
 * \brief	set a stone to column
 *
 * \param[in]	column	column number (0-6)
 */
void Game::stonePlace(int column) {
	field->stonePlace(column);
}


/**
 * \fn		getCopyOfGameField
 * \brief	returns a game-field clone
 */
GameField Game::getCopyOfGameField(void) {
	return *field;
}

/**
 * @}
 */
