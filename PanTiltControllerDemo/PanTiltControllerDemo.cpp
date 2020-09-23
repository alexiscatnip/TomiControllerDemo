// PanTiltControllerDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Alexis: this class is the "GUI" frontend for the pantilt demo. there is only gui logic here. 

#include <iostream>
#include <string>
#include "PantiltController.h"
#include "PanTiltControllerDemo.h"
#include <algorithm> 
using namespace std;

int main()
{
	std::string device;

	cout << "===demo app===" << endl << endl;
	cout << "Please enter DEVICE to test: " << endl;
	cout << "- pelco" << endl;
	cout << "- restful" << endl;
	cout << "- fsm" << endl;

	cin >> device;
	if (device == "pelco") {
		PanTiltController panTiltController = PanTiltController(); //wonder if we need the new keyword?
		string portname;

		while (panTiltController.queryStatus() == 1)
		{
			cout << "please enter the serial port name (eg: COM5): " << endl;
			cin >> portname;
			panTiltController.initialiseRS485(portname); //try!
			if (panTiltController.queryStatus() == 1) {
				cout << "unable to connect...." << endl;
			}
		}
		cout << "Connection success!"<< endl;

		std::string command = "";
		std::string direction = "";
		std::string speed = "slow";
		
		while (true)
		{
			cout << "enter command to move pantilt: [command] [direction]" << endl;

			cin >> command >> direction /*>> speed*/;
			std::transform(command.begin(), command.end(), command.begin(), ::tolower);
			std::transform(direction.begin(), direction.end(), direction.begin(), ::tolower);
			if (direction == "up")
			{
				panTiltController.move("up", speed);
			}
			else if (direction == "down")
			{
				panTiltController.move("down", speed);
			}
			else if (direction == "left")
			{
				panTiltController.move("left", speed);
			}
			else if (direction == "right")
			{
				panTiltController.move("right", speed);
			}
		}
		
	}

	else {
		cout << "hey, i did not understand that. This command does not exist yet. " << endl;
	}
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
