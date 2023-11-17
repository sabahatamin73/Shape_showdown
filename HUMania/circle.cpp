#include "circle.hpp"
#include <iostream>
#include "DrawObjects.hpp"
using namespace std;

void Circle::change(){
    cout<<"flown"<<endl;
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

    moverRect.y+=3; 
    
  
}

Circle::Circle(int x, int y){
    srcRect = {1650, 60, 123, 122};
    moverRect = {x, y, 50, 50};
}