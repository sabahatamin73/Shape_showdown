#pragma once
#include<SDL.h>
#include "DrawObjects.hpp"
#include "Shapes.hpp"
#include <iostream>

using namespace std;
class Triangle : public Shapes
{
    int frame = 0;

public:
    void change() override;
    Triangle(int x, int y);
    ~Triangle()
    {}
};