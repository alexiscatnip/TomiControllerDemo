#include "PanTiltController.h"
//
//This class exposes low level control of the pantilt:
//1) up down left right at various speeds
//2) go to preset location (x)
//3) set the current position as preest location (x)
//TODO change library to boost asio 

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


bool PanTiltController::setCameraAddress(int address)
{
	cameraAddress = address;
	return 0;
}

void PanTiltController::move(std::string direction, int speed)
{
	char* message = new char[7]; //7 byte buffer (Note: in cpp, nul is the character 0x00, or '/0'. it is used to terminate the c string (c char array)). Unfortunately, we use 0x00 alot in the Serial communications. So if we debug-print this variable, we can often end up with a string that is shorter than expected. Strlen() gives us completely wrong length too.
	//message[7] = '\0'; //Seriously, fuck cpp

	// this is pelco-d
	if (direction == "up")
		PelcoD::generateMoveUpCommand(cameraAddress, speed, message);
	else if (direction == "down")
		PelcoD::generateMoveDownCommand(cameraAddress, speed, message);
	else if (direction == "left")
		PelcoD::generateMoveUpCommand(cameraAddress, speed, message);
	else if (direction == "right")
		PelcoD::generateMoveUpCommand(cameraAddress, speed, message);
	else
		return;
	//std::cout << std::hex << static_cast<void*>(message) << std::endl; //this i not helpful! and misleading!
	panTiltSerialPort->writeSerialPort(message, 7);
	delete[] message;	
}

//Send command to PT, move it to the preset X
void PanTiltController::goToPreset(int presetNumber)
{
	char* message = new char[7];
	PelcoD::generateGoToPresetCommand(cameraAddress, presetNumber, message);
	panTiltSerialPort->writeSerialPort(message, 7);
	delete[] message;
}

//Send command to PT, set current position to preset X
void PanTiltController::setPreset(int presetNumber)
{
	char* message = new char[7];
	PelcoD::generateSetPresetCommand(cameraAddress, presetNumber, message);
	panTiltSerialPort->writeSerialPort(message, 7);
	delete[] message;
}