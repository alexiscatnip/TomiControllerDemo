#include "Tasker.h"


using namespace std;

Tasker::Tasker()
{
	sprayer = Sprayer();
	rvBaseInterface = RvBaseInterface();
}

void Tasker::startTask()
{
	while (true) {
		//do task 1: communicate with the robot base with the RESFUL API
		bool base_status = rvBaseInterface.getStatus();
		if (base_status == "moving") {
			//do nothing.
		} else if (base_status == "stopped, waiting for us to spray spray") {
			//get the spraying pattern to use.
			int spray_pattern_from_robot_base = getRobotBaseSprayPattern();

			if (sprayer.isSpraying()) {
				//do nothing, just wait
			} else (! sprayer.isSpraying()) {
				sprayer.startSpraying();
			}
		}

		//do task 2: using the result of the above first task, determine the spraying state and pan-tilt movement of the device.
		sprayer.update(); //updateSpray(): this function updates the (1 spray-on or off) and (2 move the pan-tilt to the pre-defined angles.)


	}
}
