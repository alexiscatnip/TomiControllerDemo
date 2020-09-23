#pragma once
#include <string>
#include <iostream>
#include "SerialPort.hpp"
#include "PelcoD.h"

// This class uses the pelcoD command library to create the packet. 
// It then uses the serial library to send the packet via UART.
// TODO: receive the packets and read them and run a callback as required by the function.

class PanTiltController
{
private:
	int cameraAddress = 1; //the address that the pelco camera is set to (dip switches)
	SerialPort* panTiltSerialPort;
	std::string port_name = "COM5"; //lul?
	enum class StatusEnum{READY, NOT_INITIALISED};
	StatusEnum status = StatusEnum::NOT_INITIALISED;
public:
	PanTiltController();
	bool setCameraAddress(int address);
	bool initialiseRS485(std::string port_name);
	bool queryStatus();

	void move(std::string direction, int speed);
	void goToPreset(int presetNumber);
	void setPreset(int presetNumber);
};

