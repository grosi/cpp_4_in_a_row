/**
 * \file        Game.hpp
 * \brief       game-control class
 * \date        2014-03-29
 * \version     0.0.1
 *
 * \addtogroup  game
 * @{
 */

#ifndef GAME_HPP_
#define GAME_HPP_

/**
 * \typedef	playerLineUp_t
 * \brief	All possible player line ups. It starts with the first player and ends with the second.
 */
typedef enum {
	PLAYER_SELF_REMOTE,
	PLAYER_REMOTE_SELF,
	PLAYER_SELF_BOT,
	PLAYER_BOT_SELF
}playerLineUp_t;

class Game {
private:
	App4GewinnT4 app;

	Player** current_player;
	Player* player_1;
	Player* player_2;
	int roundCtr;

public:
	Game(playerLineUp_t line_up);
	virtual ~Game();

	Player* getCurrentPlayer(void);
	void stonePlace(int, int);
	void newGameRound(void);
	GameField getCopyOfGameField(void);
	void drawCursor(int);
	void drawResultScreen(Player**, Stone winner_row[4]);




};

#endif /* GAME_HPP_ */
