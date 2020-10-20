#pragma once

#include "PanTiltController.h"
#include "SprayButton.h"
class Sprayer
{//what does sprayer do? It sprays like a hooman being!
public:
	Sprayer(std::string comport_sprayer_button, std::string comport_pantilt);
	
	void update();
	//sets the area to spray, where x1,y1 is the lower left corner, x2y2 is the upper right corner. these numbers represent the row and columns in the grid.
	bool setSprayArea(int x1, int y1, int x2, int y2);
	//tells the sprayer to start spraying immediately.
	bool startSprayingJob();
	//returns if we are spraying right now.
	bool isSpraying();
	//returns is the spray job complete?
	bool isJobComplete();
private:
	PanTiltController _pantiltcontroller_instance;
	SprayButton _spray_button_instance;
	int max_grid_size_x = 5; // how many cols
	int max_grid_size_y = 5; // how many rows

	//variables that we use to mark various stuff, such as the boundaries of spraying. Should be set before we start spraying.
	int _x1 = 0, _x2 = 0;
	int _y1 = 0, _y2 = 0;
	int current_spot_index = 0;

	//state variables.
	bool is_spraying = false;

	//internal functions.
	bool isTimeUp();
	bool moveToNextSpot();
};

