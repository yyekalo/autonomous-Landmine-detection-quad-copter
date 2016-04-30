//
//  Vector.cpp
//  MachineVission
//
//  Created by Yekalo Abraha on 4/9/16.
//  Copyright © 2016 Yikealo Abraha. All rights reserved.
//

#include "Vector.h"

Vector::Vector(float x,float y, float z)
{
    setX(x);
    setY(y);
    setZ(z);
}
Vector::~Vector()
{
    
}





void Vector::setX(float inx)
{
    x=inx;
}






void Vector::setY(float iny)
{
    y=iny;
}






void Vector::setZ(float inz)
{
    Vector::z = inz;
}





float Vector::getX(float x)
{
    return x;
}






float Vector::getY(float y)
{
    return y;
}







float Vector::getZ(float Z)
{
    return z;
}
