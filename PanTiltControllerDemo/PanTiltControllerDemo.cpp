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
		int id;

		while (panTiltController.queryStatus() == 1)
		{
			cout << "please enter the serial port name and camera id. EG: [COM5] [1] : " << endl;
			cin >> portname >> id;
			panTiltController.initialiseRS485(portname); //try!
			if (panTiltController.queryStatus() == 1) {
				cout << "unable to connect...." << endl;
			}
		}
		cout << "Connection success!"<< endl;
		panTiltController.setCameraAddress(id);

		std::string command = "";
		//std::string direction = "";
		int speed = 10;
		
		while (true)
		{
			cout << "enter command to move pantilt: [command] [speed/presetNum]" << endl;
			cout << "[command: up-down-left-right- setpreset - gotopreset] " << endl;
			cout << "[speed: 1..30      presetNum: 1..255 ]" << endl;

			cin >> command >> speed;
			std::transform(command.begin(), command.end(), command.begin(), ::tolower);
			if (command == "up")
			{
				panTiltController.move("up", speed);
			}
			else if (command == "down")
			{
				panTiltController.move("down", speed);
			}
			else if (command == "left")
			{
				panTiltController.move("left", speed);
			}
			else if (command == "right")
			{
				panTiltController.move("right", speed);
			}
			else if (command == "setpreset")
			{
				panTiltController.setPreset(speed);
			}
			else if (command == "gotopreset")
			{
				panTiltController.goToPreset(speed);
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
