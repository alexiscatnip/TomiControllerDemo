#include "PelcoD.h"

//TODO: add functions that can decipher the serial messages from the pantilt.
//(although it is not so important RN)

//All functions here return the pelco D packet as a char array, 7 bytes long, in the 'message' array.
void PelcoD::generateMoveUpCommand(int address, int speed, char* message) {
	unsigned char _sync_byte = 0xFF;
	unsigned char _address = address;
	unsigned char _cmd1 = 0x00; //
	unsigned char _cmd2 = 0x08; //bit4:down. bit3:up. bit2:left. bit1:right.
	unsigned char _data1 = speed; //pan speed
	unsigned char _data2 = speed; //tilt speed 00-> 3F (dec 63). FF for 'turbo' 
	unsigned char _chksum = (_sync_byte + _address + _cmd1 + _cmd2 + _data1 + _data2) % 256;
	
	message[0] = _sync_byte;
	message[1] = _address;
	message[2] = _cmd1;
	message[3] = _cmd2;
	message[4] = _data1;
	message[5] = _data2;
	message[6] = _chksum;

	return;
}

void PelcoD::generateMoveDownCommand(int address, int speed, char* message) {
	unsigned char _sync_byte = 0xFF;
	unsigned char _address = address;
	unsigned char _cmd1 = 0x00; //
	unsigned char _cmd2 = 0x10; //bit4:down. bit3:up. bit2:left. bit1:right.
	unsigned char _data1 = speed; //pan speed
	unsigned char _data2 = speed; //tilt speed 00-> 3F (dec 63). FF for 'turbo' 
	unsigned char _chksum = (_sync_byte + _address + _cmd1 + _cmd2 + _data1 + _data2) % 256;
	
	message[0] = _sync_byte;
	message[1] = _address;
	message[2] = _cmd1;
	message[3] = _cmd2;
	message[4] = _data1;
	message[5] = _data2;
	message[6] = _chksum;

	return;
}

void PelcoD::generateMoveLeftCommand(int address, int speed, char* message) {
	unsigned char _sync_byte = 0xFF;
	unsigned char _address = address;
	unsigned char _cmd1 = 0x00; //
	unsigned char _cmd2 = 0x04; //bit4:down. bit3:up. bit2:left. bit1:right.
	unsigned char _data1 = speed; //pan speed
	unsigned char _data2 = speed; //tilt speed 00-> 3F (dec 63). FF for 'turbo' 
	unsigned char _chksum = (_sync_byte + _address + _cmd1 + _cmd2 + _data1 + _data2) % 256;
	
	message[0] = _sync_byte;
	message[1] = _address;
	message[2] = _cmd1;
	message[3] = _cmd2;
	message[4] = _data1;
	message[5] = _data2;
	message[6] = _chksum;

	return;
}

void PelcoD::generateMoveRightCommand(int address, int speed, char* message) {
	unsigned char _sync_byte = 0xFF;
	unsigned char _address = address;
	unsigned char _cmd1 = 0x00; //
	unsigned char _cmd2 = 0x02; //bit4:down. bit3:up. bit2:left. bit1:right.
	unsigned char _data1 = speed; //pan speed
	unsigned char _data2 = speed; //tilt speed 00-> 3F (dec 63). FF for 'turbo' 
	unsigned char _chksum = (_sync_byte + _address + _cmd1 + _cmd2 + _data1 + _data2) % 256;
	
	message[0] = _sync_byte;
	message[1] = _address;
	message[2] = _cmd1;
	message[3] = _cmd2;
	message[4] = _data1;
	message[5] = _data2;
	message[6] = _chksum;

	return;
}

//obtain a pelco D packet as a char array, 7 bytes long.
//presetNum 1..255
void PelcoD::generateSetPresetCommand(int address, int presetNum, char* message) {
	unsigned char _sync_byte = 0xFF;
	unsigned char _address = address;
	unsigned char _cmd1 = 0x00; //
	unsigned char _cmd2 = 0x03; //0x03
	unsigned char _data1 = 0x00; //00
	unsigned char _data2 = presetNum; //presetid 
	unsigned char _chksum = (_sync_byte + _address + _cmd1 + _cmd2 + _data1 + _data2) % 256;

	message[0] = _sync_byte;
	message[1] = _address;
	message[2] = _cmd1;
	message[3] = _cmd2;
	message[4] = _data1;
	message[5] = _data2;
	message[6] = _chksum;

	return;
}


//obtain a pelco D packet as a char array, 7 bytes long.
//presetNum 1..255
void PelcoD::generateGoToPresetCommand(int address, int presetNum, char* message) {
	unsigned char _sync_byte = 0xFF;
	unsigned char _address = address;
	unsigned char _cmd1 = 0x00; //
	unsigned char _cmd2 = 0x07; //0x07
	unsigned char _data1 = 0x00; //00
	unsigned char _data2 = presetNum; //presetid 
	unsigned char _chksum = (_sync_byte + _address + _cmd1 + _cmd2 + _data1 + _data2) % 256;

	message[0] = _sync_byte;
	message[1] = _address;
	message[2] = _cmd1;
	message[3] = _cmd2;
	message[4] = _data1;
	message[5] = _data2;
	message[6] = _chksum;

	return;
}


