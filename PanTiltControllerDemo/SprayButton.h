#pragma once
#include <string>
#include <iostream>
#include "SerialPort.hpp"


// It then uses the serial library to send the packet via UART.
// TODO: receive the packets and read them and run a callback as required by the function.

class SprayButton
{
private:
	std::string port_name = "COM4"; //com port of the interface
	SerialPort * port_instance;

	//"on byte: " 01010011	
	//"off byte: " 10000010	
	byte on_byte = 0b01010011;
	byte off_byte = 0b10000010;
public:
	SprayButton();
	bool initialisePort(std::string port_name);

	void on();  //spraying on
	void off(); //spraying off
};

