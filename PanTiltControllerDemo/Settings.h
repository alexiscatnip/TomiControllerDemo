#pragma once

#include <iostream>
#include <fstream>
#include <string>
//using namespace std;

class Settings
{
private: 
    std::string _filename = "settings.txt";
    std::fstream myfile;

public:
    std::string getComPortSprayerButton();
    std::string getComPortPanTilt();
    std::string getAddrRVBase();

    std::string ReadNthLine(const std::string& filename, int N);
    std::string ReadNthLine(int N);

    Settings(std::string filename) {
        _filename = filename;
        openFile(_filename);
    };
    Settings() {
        openFile(_filename);
    };
    void openFile(std::string filename)
};

