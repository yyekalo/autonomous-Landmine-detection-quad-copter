//
//   Tracker.hpp
//  MachineVission
//
//  Created by Yekalo Berhane on 4/9/16.
//  Copyright © 2016 Yikealo Abraha. All rights reserved.
//

#ifndef  Tracker_h
#define  Tracker_h

#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include "Object.h"
#include <string>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv/highgui.h>
#include <iostream>
#include "Vector.h"


class Tracker
{
public:
     Tracker();
    ~ Tracker();
    
    Vector getCoordinate();
    float  GetHeading();
    
    
private:
    
    Vector position;
    Point Get_coordinate(Mat orginalImage,bool Front=true);
    double getDistance(Point pointA,Point pointB);
    double GetRadius(double angle,double cameraHeight);
    double getDeviationAngle(Point point,Mat orginalImage,double actualDistance,double height);
    double getActualAngle(Mat orginalImage,Point pointA);
    Vector frontCoordinate();
    Vector rightCoordinate();

    
    
};

#endif /*  Tracker_hpp */
