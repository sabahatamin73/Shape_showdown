#pragma once
#include<SDL.h>
#include "DrawObjects.hpp"
#include "Shapes.hpp"
#include <iostream>

using namespace std;
class Circle : public Shapes
{
    int frame = 0;

public:
    void change() override;
    Circle(int x, int y);
    ~Circle()
    {}
};