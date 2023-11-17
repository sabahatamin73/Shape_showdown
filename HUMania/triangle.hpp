#pragma once
#include<SDL.h>
#include "DrawObjects.hpp"
#include "Shapes.hpp"
#include <iostream>

using namespace std;

// class for Bat implementation inherited from class Animal
class Triangle : public Shapes
{
    int frame = 0;//checks state of bee

public:
    
    // void drop();// function to drop bat
    // Triangle(); 
    // void draw() override;
    void change() override;
    // you may add other overloaded constructors here... 
    Triangle(int x, int y);// Constructor that takes x & y coordinates as parameters to draw object on screen
    ~Triangle()
    {
        cout<<"Triangle destroyed"<<endl;
    }
};