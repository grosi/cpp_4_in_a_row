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

class Remote : Player {
public:
	Remote();
	virtual ~Remote();

	void eventCommStonePlace();
};

#endif /* REMOTE_HPP_ */

/**
 * @}
 */
