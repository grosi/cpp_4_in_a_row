/**
 * \file        Self.hpp
 * \brief       class for the human player
 * \date        2014-03-29
 * \version     0.0.1
 *
 * \addtogroup  self
 * @{
 */

#ifndef SELF_HPP_
#define SELF_HPP_

class Game;

#include "Player.hpp"


class Self : public Player {
private:
	int cursorPosition;

public:
	Self(Game*);
	virtual ~Self();

	void evenHwBtnEnt();
	void eventHwPot();
	int eventSelfStonePlace();
	void drawStone();

};

#endif /* SELF_HPP_ */

/**
 * @}
 */
