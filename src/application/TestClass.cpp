/*
 * TestClass.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: Simon
 */

#include "TestClass.hpp"

extern "C" {
#include "carme.h"
#include "carme_io1.h"
}

TestClass::TestClass(): k(0)
{
	CARME_Init();
	CARME_IO1_Init();
	CARME_IO1_LED_Set(0xAA,0xFF);
}

TestClass::~TestClass()
{
	// TODO Auto-generated destructor stub
}


void TestClass::dummy(int new_dummy)
{
	k = new_dummy;
}

