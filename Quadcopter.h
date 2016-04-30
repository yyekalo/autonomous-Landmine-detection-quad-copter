#ifndef POSITION
#define POSITION
#include "Position.h"
#endif
#ifndef TRACKER
#define TRACKER
#include "Tracker.h"
#endif // !TRACKER




class Quadcopter
{


public:
	Quadcopter();
	void moveFoward();
	void moveBackward();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	Position getPosition();
	float getHeading();


private:

	Position* quadPos;
	Tracker* quadTracker;

};