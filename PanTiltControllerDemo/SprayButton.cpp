#include "SprayButton.h"
#include "Utils.h"
#include <thread>
#include <chrono>

//This class lets you turn on/off the spraygun with just a function.
//TODO change library to boost asio 

SprayButton::SprayButton() //Constructor
{
	//status = StatusEnum::NOT_INITIALISED;
	initialisePort(port_name);
};

//start the serial object with the port name (like 'COM5')
//Return:	0 success
//			1 failure
bool SprayButton::initialisePort(std::string port_name)
{
	const char *portName = port_name.c_str();
	//strcpy(portName, port_name.c_str()); //std::string -> char * , because the library only accept const char*
	port_instance = new SerialPort(portName);

	std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //sleep, 1s

	if (port_instance->isConnected())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


void SprayButton::on()
{
	char* message = new char[1];
	message[0] = on_byte;

	port_instance->writeSerialPort(message, 1);
	delete[] message;	
}


void SprayButton::off()
{
	char* message = new char[1];
	message[0] = off_byte;

	port_instance->writeSerialPort(message, 1);
	delete[] message;
}
