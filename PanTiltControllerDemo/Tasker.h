#pragma once

#include "Sprayer.h"
#include "RvBaseInterface.h"

class Tasker
{
public:
	Tasker();
	void startTask();


private: 
	Sprayer sprayer;
	RvBaseInterface rvBaseInterface;
};

