#include "Tasker.h"
#include "Settings.h"
using namespace std;

Tasker::Tasker()
{
	initialise();
}

// Get settings from the settings file, use them to create the various hardware controllers.
void Tasker::initialise()
{
	settings = Settings();
	std::string comport_sprayer_button = settings.getComPortSprayerButton();
	std::string comport_pantilt = settings.getComPortPanTilt();
	std::string address_base = settings.getAddrRVBase();

	rvBaseInterface = RvBaseInterface(address_base);
	sprayer = Sprayer(comport_sprayer_button, comport_pantilt);
}

//call this once, it gets updated in thatm instant, only once.
void Tasker::update()
{
	//do task 1: communicate with the robot base with the RESTFUL API
	RvBaseInterface::StatusEnum base_status = rvBaseInterface.getStatus();
	if (base_status == RvBaseInterface::StatusEnum::NOT_INITIALISED) {
		//error... log it.
	} else if (base_status == RvBaseInterface::StatusEnum::WAITING_FOR_US) {
		//get the spraying pattern to use at current location.
		int spray_pattern_from_robot_base = rvBaseInterface.getRobotBaseSprayPattern();

		if (sprayer.isSpraying()) {
			//do nothing, just wait
		} else if (!sprayer.isSpraying()) {
			sprayer.setSprayArea(1,1,5,5);
			sprayer.startSprayingJob();
		} 

		if (sprayer.isJobComplete()) {
			//yay! we can notify the base to go to next waypoint liao.
			rvBaseInterface.reportCompletionToBase();
		}
	}

	//do task 2: using the result of the above first task, determine the spraying state and pan-tilt movement of the device.
	sprayer.update(); //updateSpray(): this function updates the (1 spray-on or off) and (2 move the pan-tilt to the pre-defined angles.)

}
