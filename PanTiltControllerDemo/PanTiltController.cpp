#include "PanTiltController.h"
//
//This class exposes low level control of the pantilt:
//1) up down left right at various speeds
//2) go to preset location (x)
//3) set the current position as preest location (x)

PanTiltController::PanTiltController() //Constructor
{
	status = StatusEnum::NOT_INITIALISED;
};

//start the serial object with the port name (like 'COM5')
//Return:	0 success
//			1 failure
bool PanTiltController::initialiseRS485(std::string port_name)
{
	// copying the contents of the string to char array 
	//char *portName = 0; //nulPtr
	const char *portName = port_name.c_str();
	//strcpy(portName, port_name.c_str()); //std::string -> char * , because the library only accept const char*
	panTiltSerialPort = new SerialPort(portName);
	std::cout << "Is connected?: " << panTiltSerialPort->isConnected() << std::endl;

	if (panTiltSerialPort->isConnected())
	{
		status = StatusEnum::READY;
		return 0;
	}
	else
	{
		status = StatusEnum::NOT_INITIALISED;
		return 1;
	}

}//check if the device is ready to work.
//Return:	0 success (ready)
//			1 failure (not ready)
bool PanTiltController::queryStatus()
{
	if (status == StatusEnum::NOT_INITIALISED)
	{
		return 1;
	} else 
	{
		return 0;
	}
}


void PanTiltController::move(std::string direction, std::string speed)
{
	char* message = new char[8]; //7 byte buffer + 1 nul at the end!
	message[7] = '\0'; //Seriously, fuck cpp

	// this is pelco-d
	if (direction == "up")
		PelcoD::getCommandBytes(PelcoD::PelcoDCommand::Up, PelcoD::PelcoDSpeed::Slow, message);
	else if (direction == "down")
		PelcoD::getCommandBytes(PelcoD::PelcoDCommand::Down, PelcoD::PelcoDSpeed::Slow, message);
	else if (direction == "left")
		PelcoD::getCommandBytes(PelcoD::PelcoDCommand::Left, PelcoD::PelcoDSpeed::Slow, message);
	else if (direction == "right")
		PelcoD::getCommandBytes(PelcoD::PelcoDCommand::Right, PelcoD::PelcoDSpeed::Slow, message);
	else
		return;
	//std::cout << "wrote : " << _message <<std::endl;
	std::cout << std::hex << static_cast<void*>(message) << std::endl;
	panTiltSerialPort->writeSerialPort(message, 7);
	delete[] message;	
}

//
//void PanTiltController::goToPreset(int presetNumber)
//{
//	presetNumber
//}