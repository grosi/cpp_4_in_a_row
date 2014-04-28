/**
 * \file        GameField.hpp
 * \brief       class for the gamefield
 * \date        2014-03-29
 * \version     0.0.1
 *
 * \addtogroup  gamefield
 * @{
 */

#ifndef GAMEFIELD_HPP_
#define GAMEFIELD_HPP_

#include <stdint.h>

class GameField {
private:
	int placedStones;

public:
	GameField();
	virtual ~GameField();

	void stonePlace(int);
	uint8_t checkWinner();
	void clone();
	void drawGameField();
};

#endif /* GAMEFIELD_HPP_ */

/**
 * @}
 */
