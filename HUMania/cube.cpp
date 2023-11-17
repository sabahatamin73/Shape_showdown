#include "cube.hpp"
#include <iostream>
#include "DrawObjects.hpp"
using namespace std;

void Cube::change(){
    cout<<"flown"<<endl;
    if (frame == 0)
    {
        srcRect = {86, 459, 218, 195};
        frame += 1;
    }
    else if (frame == 1)
    {
        srcRect = {358, 450, 218, 195};
        frame += 1;
    }
    else if(frame == 2)
    {
        srcRect = {618, 440, 218, 195};
        frame -= 2;
    }
    else
    {
        frame = 0;
    }

    moverRect.y+=3; //moves the shape 3 pixels Down
    
  
}
Cube::Cube(int x, int y){
     srcRect = {86, 459, 218, 195};
    moverRect = {x, y, 50, 50};
}
