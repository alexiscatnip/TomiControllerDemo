#include "Settings.h"

void Settings::openFile(std::string filename)
{
    myfile.open(filename);
    if (myfile.is_open())
    {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    }
}

std::string Settings::getComPortSprayerButton () {
    return ReadNthLine(0);
}

std::string Settings::getComPortPanTilt() {
    return ReadNthLine(1);
}
std::string Settings::getAddrRVBase() {
    return ReadNthLine(2);
}

std::string Settings::ReadNthLine(int N) {
    return ReadNthLine(_filename, N)

}

std::string Settings::ReadNthLine(const std::string& filename, int N)
{

    if (!myfile) {
        std::cout << "Failed to open file" << std::endl;
        return "UNINSNITALISED FILE.";
    };

    std::ifstream in(filename.c_str());

    std::string s;
    //for performance
    s.reserve(20);

    //skip N lines
    for (int i = 0; i < N; ++i)
        std::getline(in, s);

    std::getline(in, s);
    return s;
}
