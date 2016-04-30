
#include "Quadcopter.h"


 Quadcopter::Quadcopter()
{
	quadTracker = new Tracker();
	quadPos = new Position();
}

float Quadcopter::getHeading()
{
	return quadTracker->getHeading();
}

 Position Quadcopter::getPosition()
{
	return *quadPos;
}


 void Quadcopter::moveFoward()
{

}

void Quadcopter::moveBackward()
{

}

 void Quadcopter::moveRight()
{

}

void Quadcopter::moveLeft()
{

}

void Quadcopter::moveUp()
{

}

void Quadcopter::moveDown()
{

}