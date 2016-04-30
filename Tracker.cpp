//
//   Tracker.cpp
//  MachineVission
//
//  Created by Yekalo Berhane on 4/9/16.
//  Copyright © 2016 Yikealo Abraha. All rights reserved.
//

#include "Tracker.h"

 Tracker:: Tracker()
{
    
}






 Tracker::~ Tracker()
{

}






Vector getCoordinate()
{
    //TODO: make this cmaerheigh a calculated value
    int cmaeraheight;
    Mat bgr_image=imread("/Users/yekaloberhane/Documents/School/AutoCartProject/Software/MachineVission/MachineVission/img_20160322_151534823-2.jpg");
    double angle=getActualAngle(bgr_image,Get_coordinate(bgr_image));
    double BetaAngle=getDeviationAngle(Get_coordinate(bgr_image), bgr_image,DistanceBetweenPoints ,  Tracker);
    double Raduis= cmaeraheight*tan(BetaAngle);
    
    Vector possition = Vector(cos(angle)*Raduis,sin(angle)*Raduis,cmaeraheight);
}







float  GetHeading()
{
    
}






Point Get_coordinate(Mat bgr_image,bool Front)
{
    
    cv::Mat orig_image = bgr_image.clone();
    
    cv::medianBlur(bgr_image, bgr_image, 3);
    
    // Convert input image to HSV
    cv::Mat hsv_image;
    cv::cvtColor(bgr_image, hsv_image, cv::COLOR_RGB2HSV);
    
    
    // Threshold the HSV image, keep only the red pixels
    cv::Mat lower_red_hue_range;
    cv::Mat upper_red_hue_range;
    if (Front)
    {
        cv::inRange(hsv_image, cv::Scalar(0, 100, 100), cv::Scalar(10, 255, 255), lower_red_hue_range);
        cv::inRange(hsv_image, cv::Scalar(160, 100, 100), cv::Scalar(179, 255, 255), upper_red_hue_range);
    }
    else{
        //TODO:change this to the appropriate value later
        cv::inRange(hsv_image, cv::Scalar(0, 100, 100), cv::Scalar(10, 255, 255), lower_red_hue_range);
        cv::inRange(hsv_image, cv::Scalar(160, 100, 100), cv::Scalar(179, 255, 255), upper_red_hue_range);
    }
    
    // Combine the above two images
    cv::Mat red_hue_image;
    cv::addWeighted(lower_red_hue_range, 1.0, upper_red_hue_range, 1.0, 0.0, red_hue_image);
    
    cv::GaussianBlur(red_hue_image, red_hue_image, cv::Size(9, 9), 2, 2);
    
    // Use the Hough transform to detect circles in the combined threshold image
    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(red_hue_image, circles, CV_HOUGH_GRADIENT, 1, red_hue_image.rows/8, 100, 20, 0, 0);
    
    // Loop over all detected circles and outline them on the original image
    if(circles.size() == 0) return Point(0,0);
    
    cv::Point centers=Point(std::round(circles[0][0]), std::round(circles[0][1]));
    orig_image.release();
    lower_red_hue_range.release();
    hsv_image.release();
    upper_red_hue_range.release();
    red_hue_image.release();
    
    return centers;
    
}





//This function returns the distance between two points
double getDistance(Point pointA,Point pointB)
{
    return sqrt(pow((pointA.x-pointB.x),2)+pow((pointA.y-pointB.y), 2));
}




//This function returns the dgree of deviation from the center
double getDeviationAngle(Point pointa,Mat originalImage,double actualDistance,double height)
{
    double Kconstancte= actualDistance/getDistance(Get_coordinate(originalImage), Get_coordinate(originalImage,false));
    
    return atan(Kconstancte*getDistance(Point(originalImage.size().height/2,originalImage.size().width), pointa));
    
}






//This funaction calculates the actual distance from camera height and beta angle
double GetRadius(double angle,double cameraHeight)
{
    return cameraHeight*tan(angle);
}






//This function returns the actual angle relative to the positive y axis
//TODO: check this function if is actually functing the way you want it
double getActualAngle(Mat orginalImage,Point pointA)
{
    //TODO: have an if statments that check
    return atan((pointA.y-orginalImage.size().height/2)/pointA.x-orginalImage.size().width/2);
}


