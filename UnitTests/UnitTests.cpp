#include "pch.h"
#include "CppUnitTest.h"
#include "../PanTiltControllerDemo//PelcoD.h"
#include "../PanTiltControllerDemo//PelcoD.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(Test_GetCommandBytes_Up)
		{
			char* message = new char[7]; //7 byte buffer
			PelcoD::getCommandBytes(PelcoD::PelcoDCommand::Up, PelcoD::PelcoDSpeed::Slow, message);

			Assert::AreEqual(message[0], static_cast < char>(0xFF)); //sync
			//Assert::AreEqual(message[1], static_cast < char>(0x00));
			Assert::AreEqual(message[2], static_cast < char>(0x00));
			Assert::AreEqual(message[3], static_cast < char>(0x08));
			Assert::AreEqual(message[4], static_cast < char>(0x10));
			Assert::AreEqual(message[5], static_cast < char>(0x10));
			Assert::AreEqual(message[6], static_cast < char>(39));

			delete[] message;
		}
	};
}
