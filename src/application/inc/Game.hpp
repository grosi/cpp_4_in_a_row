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


class Game {
private:
	App4GewinnT4 app;

	Player** current_player;
	Player* player_1;
	Player* player_2;
	int roundCtr;

public:
	Game(Player* player_1, Player* player_2 );
	virtual ~Game();

	Player* getCurrentPlayer(void);
	void stonePlace(int, int);
	void newGameRound(void);
	GameField getCopyOfGameField(void);
	void drawCursor(int);
	void drawResultScreen(Player**, Stone winner_row[4]);




};

#endif /* GAME_HPP_ */
