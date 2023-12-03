#include<SDL.h>
#include "DrawObjects.hpp"
#include <iostream>

using namespace std;
// class for shooter implementation
class Shooter{
    SDL_Rect srcRect, moverRect;
    public:
    void draw();
    int life = 5;
    int get_life();
    void set_life(int l);
    void movement(int move);
    bool operator>(int i);
    bool operator<(int i);
    bool operator==(int i);
    operator int()
    {
        cout<<"here"<<endl;
        return life;
    }  
    bool CharacterDestroyed();
    Shooter(int, int);
    int get_x();
    int get_y();
    void set_coordinates();
    SDL_Rect* get_mover();
   ~Shooter(){}
};

