/*
 * Communication.h
 *
 *  Created on: Apr 3, 2014
 *      Author: loffp1
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include <stdint.h>
class Communication {
private:
	static Communication* singleInstance;
	bool stateConnection;
	bool stateGame;
public:
	static Communication* getInstance(void);
private:
	void commTxGameReq(void);
	void commTxGameStart(void);
	void commTxGamePlace(void);
	void commTxGameEsc(void);
	bool getStateConnection(void);
	bool getStateGame(void);
private:
	Communication();
	virtual ~Communication();
};

#endif /* COMMUNICATION_H_ */
