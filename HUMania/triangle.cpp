#include "triangle.hpp"
#include <iostream>
#include "DrawObjects.hpp"
using namespace std;

void Triangle::change(){
    cout<<"flown"<<endl;
    if (frame == 0)
    {
        srcRect = {72, 38, 158, 164};
        frame += 1;
    }
    else if (frame == 1)
    {
        srcRect = {353, 38, 158, 164};
        frame += 1;
    }
    else if(frame == 2)
    {
        srcRect = {611, 38, 158, 164};
        frame -= 2;
    }
    else
    {
        frame = 0;
    }

    moverRect.y+=3; 
    
  
}
Triangle::Triangle(int x, int y){
    srcRect = {72, 38, 158, 164};
    moverRect = {x, y, 50, 50};
}
