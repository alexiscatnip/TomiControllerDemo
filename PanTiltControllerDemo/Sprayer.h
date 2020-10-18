#pragma once

#include "PanTiltController.h"
#include "SprayButton.h"
class Sprayer
{//what does sprayer do? It sprays like a hooman being!
public:
	Sprayer();
	void update();
	bool setSprayArea(int x1, int y1, int x2, int y2);
	bool startSprayingJob();
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

