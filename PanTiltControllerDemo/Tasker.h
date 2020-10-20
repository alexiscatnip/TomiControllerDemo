#pragma once

#include "Sprayer.h"
#include "RvBaseInterface.h"
#include "Settings.h"

class Tasker
{
public:
	Tasker();
	void initialise();
	void update();


private: 
	Settings settings;
	Sprayer sprayer;
	RvBaseInterface rvBaseInterface;
};

