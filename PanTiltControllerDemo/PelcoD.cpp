#include "PelcoD.h"

//obtain a pelco D packet as a char array, 7 bytes long.
void PelcoD::getCommandBytes(PelcoDCommand cmd, PelcoDSpeed speed, char* message) {
	unsigned char _sync_byte = 0xFF;
	unsigned char _address = 0x00;
	unsigned char _cmd1 = 0x00; //
	unsigned char _cmd2 = 0x00; //bit4:down. bit3:up. bit2:left. bit1:right.
	unsigned char _data1 = 0xFF; //pan speed
	unsigned char _data2 = 0xFF; //tilt speed 00-> 3F. FF for 'turbo'
	unsigned char _chksum = 0xFF;

	if (cmd == PelcoDCommand::Up)
	{
		_cmd2 = 0x08; //up: cmd2, bit3 is true
	}
	if (cmd == PelcoDCommand::Down)
	{
		_cmd2 = 0x10; //down: cmd2, bit4 is true
	}
	if (cmd == PelcoDCommand::Left)
	{
		_cmd2 = 0x4; //left: cmd2, bit2 is true
	}
	if (cmd == PelcoDCommand::Right)
	{
		_cmd2 = 0x2; //right: cmd2, bit1 is true
	}

	if (speed == PelcoDSpeed::Slow)
	{
		_data2 = _data1 = 0x10; 
	}
	if (speed == PelcoDSpeed::Fast)
	{
		_data2 = _data1 = 0x3F;
	}

	_chksum = (_sync_byte + _address + _cmd1 + _cmd2 + _data1 + _data2) % 256;
	//char* message = new char[7]; //7 bytes long
	message[0] = _sync_byte;
	message[1] = _address;
	message[2] = _cmd1;
	message[3] = _cmd2;
	message[4] = _data1;
	message[5] = _data2;
	message[6] = _chksum;

	return;
	
}