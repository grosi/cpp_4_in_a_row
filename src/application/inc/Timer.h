/*
 * Timer.h
 *
 *  Created on: Apr 3, 2014
 *      Author: loffp1
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>

class Timer {
private:
	static uint32_t systemTick;
	static Timer* singleInstance;
public:
	static Timer* getInstance(void);
private:
	static void interruptHandler(void);
	void addActionListener(void);
	void removeActionListener(void);
	void timerRun(void);
	void timerObserveEvent(void);

private:
	Timer();
	virtual ~Timer();

};

#endif /* TIMER_H_ */
