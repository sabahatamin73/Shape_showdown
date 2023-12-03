#pragma once
#include<SDL.h>
#include "DrawObjects.hpp"
#include "Shapes.hpp"
#include <iostream>

using namespace std;
class Cube : public Shapes
{
    int frame = 0;

public:
    void change() override;
    Cube(int x, int y);
    ~Cube()
    {}
};