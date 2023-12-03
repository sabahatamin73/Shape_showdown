#include "cube.hpp"
#include <iostream>
#include "DrawObjects.hpp"
using namespace std;

//coordinates taken through spritecow.com, cube changes its firm while falling downwards, 
//this is managed through the frame variable
void Cube::change(){
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

    moverRect.y+=3; //coordinates taken through spritecow.com, initial form of the cube
    
  
}

//coordinates taken through spritecow.com
Cube::Cube(int x, int y){
     srcRect = {86, 459, 218, 195};
    moverRect = {x, y, 50, 50};
}
