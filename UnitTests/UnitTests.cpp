#include "pch.h"
#include "CppUnitTest.h"
#include "../PanTiltControllerDemo//PelcoD.h"
#include "../PanTiltControllerDemo//PelcoD.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	//Test that command message generation is ok.
	TEST_CLASS(PelcoD_Tests)
	{
	public:
		
		TEST_METHOD(Test_GetCommandBytes_Up)
		{
			char* message = new char[7]; //7 byte buffer
			PelcoD::generateMoveUpCommand(44, 30, message);

			Assert::AreEqual(message[0], static_cast < char>(0xFF)); //sync
			Assert::AreEqual(message[1], static_cast < char>(44)); //addr
			Assert::AreEqual(message[2], static_cast < char>(0x00));
			Assert::AreEqual(message[3], static_cast < char>(0x08));//bit4:down. bit3:up. bit2:left. bit1:right.
			Assert::AreEqual(message[4], static_cast < char>(30));//speed
			Assert::AreEqual(message[5], static_cast < char>(30));//speed
			Assert::AreEqual(message[6], static_cast < char>(111));

			delete[] message;
		}


		TEST_METHOD(Test_GetCommandBytes_SetPreset)
		{
			char* message = new char[7]; //7 byte buffer
			int _addr = 33;
			int presetNum = 30;
			PelcoD::generateSetPresetCommand(_addr, presetNum, message);

			Assert::AreEqual(message[0], static_cast <char>(0xFF)); //sync
			Assert::AreEqual(message[1], static_cast <char>(_addr)); //addr
			Assert::AreEqual(message[2], static_cast <char>(0x00));
			Assert::AreEqual(message[3], static_cast <char>(0x03)); //03
			Assert::AreEqual(message[4], static_cast <char>(00));//00
			Assert::AreEqual(message[5], static_cast <char>(30));//preset id
			Assert::AreEqual(message[6], static_cast <char>(65));

			delete[] message;
		}
		TEST_METHOD(Test_GetCommandBytes_GoToPreset)
		{
			char* message = new char[7]; //7 byte buffer
			int _addr = 33;
			int presetNum = 30;
			PelcoD::generateGoToPresetCommand(_addr, presetNum, message);

			Assert::AreEqual(message[0], static_cast <char>(0xFF)); //sync
			Assert::AreEqual(message[1], static_cast <char>(_addr)); //addr
			Assert::AreEqual(message[2], static_cast <char>(0x00));
			Assert::AreEqual(message[3], static_cast <char>(0x07)); //07
			Assert::AreEqual(message[4], static_cast <char>(00));//00
			Assert::AreEqual(message[5], static_cast <char>(30));//preset id
			Assert::AreEqual(message[6], static_cast <char>(69));

			delete[] message;
		}
	};
	//Test that we can connect and get info from a restful server.
	TEST_CLASS(AnotherTests)
	{
	public:

		TEST_METHOD(Test_Rest_Get)
		{
			char* message = new char[7]; //7 byte buffer
			PelcoD::generateMoveUpCommand(44, 30, message);

			Assert::AreEqual(message[0], static_cast <char>(0xFF)); //sync
			Assert::AreEqual(message[1], static_cast <char>(44)); //addr
			Assert::AreEqual(message[2], static_cast <char>(0x00));
			Assert::AreEqual(message[3], static_cast <char>(0x08));//bit4:down. bit3:up. bit2:left. bit1:right.
			Assert::AreEqual(message[4], static_cast <char>(30));//speed
			Assert::AreEqual(message[5], static_cast <char>(30));//speed
			Assert::AreEqual(message[6], static_cast <char>(111));

			delete[] message;
		}


	};

}
