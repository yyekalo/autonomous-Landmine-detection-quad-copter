//
//  main.cpp
//  test
//
//  Created by Josh on 3/21/16.
//  Copyright © 2016 Josh. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

void moveForward();
void moveLeft();
void moveRight();
void moveBackward();

void moveUp();
void moveDown();

//lidar system code function implemented in here
bool objectLeft();
bool objectRight();
bool objectForward();
bool objectBackward();

void move();

float rotate();


int main(int argc, const char * argv[])
{
   
    std::cout << "OpenCV Version " << CV_VERSION << std::endl << std::endl;
    
    int width = 10;
    int height = 10;
    
    bool array[width][height];
    bool obstacleArray[width][height];
   
    //initialize mapping array as all false
    //if true, that means cell has been covered
    for ( int i = 0; i < width+1; i++ )
        for ( int j = 0; j < height+1; j++ )
        {
            array[i][j] = false;
            
            /*
            //print initialized array to check all elements are false
             
            std::cout << "array[" << i << "][" << j << "]: ";
            std::cout << array[i][j]<< std::endl;
            */
        }
    
    //initialize obstacle array as all false
    //if true, that means there is obstacle in the cell
    for (int y = 0; y < width+1; y++)
    {
        for(int z = 0; z < height+1; z++)
        {
            obstacleArray[y][z] = false;
        }
    }

    //NAVIGATION ALGORITHM
    
    int b = 0;
    int a = 0;
    
    //loops until drone goes from bottom (a=0) to top of grid (a=9), stops when a is 10
    while(a < height)
    {
        //starts on row and if b is not at right boundary, keep going right
        if (b < width-1)
        {
            //keeps moving right until it means an object or meets boundary
            while(!objectRight() || b != width-1)
            {
                moveRight();
                array[a][b] = true;
                b++;
            }
            
            //if meets an object, drone moves forward
            if (objectRight()&&!objectForward())
            {
                moveForward();
                a++;
                array[a][b]=true;
                continue;
            }
            //if statement not finished until b meets boundary, so it will keep going right
        }
        
        //if drone at last cell before boundary, and there is no object forward, and left cell has been covered, move up
        if (b == width - 1 && !objectForward() && array[a][b-1]== true)
        {
            
             moveForward();
             a++;
             array[a][b] = true;
            
        }

        //if drone is at right boundary and the left cell has not been covered, move left
        if (b == width - 1 && array[a][b-1]==false)
        {
            //loops so it will go left no matter what because moving forward a row means change of direction
            //keeps looping until b=0 or meets the very left boundary

            while(!objectLeft() || b != 0)
            {
                moveLeft();
                array[a][b] = true;
                b--;
            }
            //if there is an object to the left and no object forward, then go up
            if (objectLeft()&&!objectForward())
            {
                moveForward();
                a++;
                array[a][b]=true;
                continue;
                
            }
        }
        
        if (b==0 && !objectForward() && array[a][b+1]==true)
        {
            moveForward();
            a++;
            array[a][b] = true;
            
        }
    }
    
    /*
    for (int i = 0; i < width+1; i++)
        for (int j = 0; j < height+1; j++)
        {
            if (array[i][j] == false)
            {
                move();
            }
            
            
        }
     */
    /*
     //print new array after entire navigation
     
     for ( int i = 0; i < width+1; i++ )
        for ( int j = 0; j < height+1; j++ )
        {
            array[i][j] = false;
            
            std::cout << "array[" << i << "][" << j << "]: ";
            std::cout << array[i][j]<< std::endl;
        }
     */
    
    return 0;
}

void moveForward()
{
    //RGB->HSV function (returns coordinate system)
}

void moveLeft()
{
    //RGB->HSV function (returns coordinate system)
}

void moveRight()
{
    //RGB->HSV function (returns coordinate system)
}

void moveBackward()
{
    //RGB->HSV function (returns coordinate system)
}

bool objectLeft()
{
    //lidar system input
    return true;
}

bool objectRight()
{
    //lidar system input
    return true;
}

bool objectForward()
{
    //lidar system input
    return true;
}

bool objectBackward()
{
    //lidar system input
    return true;
}
