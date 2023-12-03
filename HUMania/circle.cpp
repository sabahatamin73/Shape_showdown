#include "circle.hpp"
#include <iostream>
#include "DrawObjects.hpp"
using namespace std;

//coordinates taken through spritecow.com, circle changes its firm while falling downwards, 
//this is managed through the frame variable
void Circle::change(){
    if (frame == 0)
    {
        srcRect = {1130, 60, 123, 122};
        frame += 1;
    }
    else if (frame == 1)
    {
        srcRect = {1380, 60, 123, 122};
        frame += 1;
    }
    else if(frame == 2)
    {
        srcRect = {1650, 60, 123, 122};
        frame -= 2;
    }
    else
    {
        frame = 0;
    }
    //moves vertically downwards, increasing this would increase the speed with which it falls down
    moverRect.y+=3; 
}

//coordinates taken through spritecow.com, initial form of the circle
Circle::Circle(int x, int y){
    srcRect = {1650, 60, 123, 122};
    moverRect = {x, y, 50, 50};
}