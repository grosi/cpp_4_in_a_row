/*
 * Hardware.h
 *
 *  Created on: Apr 3, 2014
 *      Author: loffp1
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_

#include <stdint.h>


class Hardware {
private:
	static Hardware* singleInstance;
	uint8_t portValue;
public:
	static Hardware* getInstance(void);
public:
	uint8_t getPortValue(void);
	void setLedState(uint8_t ledState);
private:
	Hardware();
	virtual ~Hardware();
};

#endif /* HARDWARE_H_ */
