//
//  Vector.hpp
//  MachineVission
//
//  Created by Yekalo Berhane on 4/9/16.
//  Copyright © 2016 Yikealo Abraha. All rights reserved.
//

#ifndef Vector_h
#define Vector_h

#include <stdio.h>
#include <iostream>

class Position
{
public:
    Position(float x=0,float y=0, float z=0);
    ~Position();
    
    void setX(float x);
    void setY(float y);
    void setZ(float Z);
    float getX(float x);
    float getY(float y);
    float getZ(float Z);
private:
    float z;
    float x;
    float y;
};

#endif /* Vector_hpp */
