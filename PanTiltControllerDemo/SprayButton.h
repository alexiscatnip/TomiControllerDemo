#pragma once
#include <string>
#include <iostream>
#include "SerialPort.hpp"

#define ON_BYTE_SEQ 0b01010011
#define off_BYTE_SEQ 0b10000010


// It then uses the serial library to send the packet via UART.
// TODO: receive the packets and read them and run a callback as required by the function.

class SprayButton
{
private:
	std::string _port_name = "COM4"; //com port of the interface
	SerialPort * _port_instance;

	//"on byte: " 01010011	
	//"off byte: " 10000010	
	//byte on_byte = 0b01010011;
	//byte off_byte = 0b10000010;
public:
	//Constructor. Parameter: port_name (EG: "COM5")
	SprayButton(std::string port_name);
	//Opens the port (name set by constructor).
	bool initialisePort();
	//Closes the port (TODO; currently assumed that port is closed by itself.).
	bool closePort();

	//turn spraying on
	void on();  
	//turn spraying off
	void off(); 
};

