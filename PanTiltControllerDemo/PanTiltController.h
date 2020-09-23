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
	SerialPort* panTiltSerialPort;
	std::string port_name = "COM5"; //lul?
	enum class StatusEnum{READY, NOT_INITIALISED};
	StatusEnum status = StatusEnum::NOT_INITIALISED;
public:
	PanTiltController();
	bool initialiseRS485(std::string port_name);
	bool queryStatus();
	void move(std::string direction, std::string speed);
};

