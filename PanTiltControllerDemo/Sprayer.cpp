#include "Sprayer.h"

Sprayer::Sprayer()
{
	//sprayer owns the spraygun and the pan-tilt.
	_pantiltcontroller_instance = PanTiltController();
	_spray_button_instance = SprayButton();


}

//You run this function to update the sprayer to perform the next task, if its ready to.
//most of the spraying logic lives here.
void Sprayer::update()
{
	if (is_spraying) {
		//if the time is up for this 'spot', go to the next spot
		if (isTimeUp() == true) {
			moveToNextSpot();
		}
		else {
			//do nothing.
		}
	}
	else { //we are either 1) JUST done with spraying this checkpoint, or 2) there is no job now?

	}

}


//Return: True-success
//        False-failure
//What it looks like:
//	^ 
//	|
//	|	|-------------B(x2,y2)
//	|   |             |
//	|   | spray here  |
//	|   A -------------
//	| (x1, y1)
//	|
//	------------------------> x
bool Sprayer::setSprayArea(int x1, int y1,int x2,int y2) {
	if ((x1 >= max_grid_size_x) or (x2 >= max_grid_size_x)) {
		//wtf?
	}	
	else if ((y1 >= max_grid_size_y) or (y2 >= max_grid_size_y)) {
		//wtf?
	}
	else {
		//phew! all good.
		_x1 = x1;
		_y1 = y1;
		_x2 = x2;
		_y2 = y2;

	}

		

}

bool Sprayer::isTimeUp()
{
	//TODO
	return false;
}


bool Sprayer::moveToNextSpot() {
	//TODO

	current_spot_index+=1;

	return false;
}
