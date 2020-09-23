#pragma once
#include <iostream>

#define PELCOD_MSG_SIZE 7;

class PelcoD
{
private:
public:
	//this functions helps you make a pelco-d command that moves the camera upwards.
	//you need to supply a char array 'message'
	static void generateMoveUpCommand(int address, int speed, char* message);
	static void generateMoveDownCommand(int address, int speed, char* message);
	static void generateMoveLeftCommand(int address, int speed, char* message);
	static void generateMoveRightCommand(int address, int speed, char* message);
	//this functions helps you make a pelco-d command that sets a preset position .
	//you need to supply a char array 'message'
	static void generateSetPresetCommand(int address, int presetNum, char* message);
	//this functions helps you make a pelco-d command that moves the camera to a preset position.
	//you need to supply a char array 'message'
	static void generateGoToPresetCommand(int address, int presetNum, char* message);
};

