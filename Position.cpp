//
//  Position.cpp
//  MachineVission
//
//  Created by Yekalo Abraha on 4/9/16.
//  Copyright © 2016 Yikealo Abraha. All rights reserved.
//

#include "Position.h"

Position::Position(float x,float y, float z)
{
	//asdd
    setX(x);
    setY(y);
    setZ(z);
}
Position::~Position()
{
    
}





void Position::setX(float inx)
{
    x=inx;
}






void Position::setY(float iny)
{
    y=iny;
}






void Position::setZ(float inz)
{
    Position::z = inz;
}





float Position::getX(float x)
{
    return x;
}






float Position::getY(float y)
{
    return y;
}







float Position::getZ(float Z)
{
    return z;
}
