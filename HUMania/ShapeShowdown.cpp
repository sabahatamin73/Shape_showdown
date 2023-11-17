// #include <iostream>
#include "ShapeShowdown.hpp"
#include "Shapes.hpp"
#include "cube.hpp"
#include "triangle.hpp"
#include "circle.hpp"

using namespace std;

class ShapesMain
{
public:   
    ShapesMain() {}

    Shapes* getObject()
    {
        int randomNumberx;
        int prob = (rand() % 100) + 1 ;
        int maxAttempts = 20; // maximum attempts to generate non-overlapping coordinates
        
        int fixedY = 0; // Set the initial y-coordinate for falling objects

        do {
            randomNumberx = 25 + (rand() % 1250);
        } while (checkOverlap(randomNumberx, fixedY) && maxAttempts-- > 0);
        
        if (maxAttempts <= 0) {
            // Couldn't find non-overlapping coordinates after maxAttempts, handle appropriately
            return nullptr;
        }

        if (prob < 33)
        {
            Shapes * u = new Circle(randomNumberx, fixedY);
            return u;
        }
        else if (prob >= 33 && prob <= 66)
        {
            Shapes* u = new  Cube(randomNumberx, fixedY);
            return u;
        }
        else if (prob >= 67 && prob <= 101) 
        {
            Shapes * u = new Triangle(randomNumberx, fixedY);
            return u;
        }  
    }

private:
    bool checkOverlap(int x, int y)
    {
        for (Shapes* existingObject : Shape)
        {
            int existingX = existingObject->get_x();
            int existingY = existingObject->get_y();

            int objectSize = 150; 
            if (abs(x - existingX) < objectSize && abs(y - existingY) < objectSize)
            {
                return true;
            }
        }
        return false;
    }

    vector<Shapes*> Shape;
};

void ShapesShowdown::drawObjects()
{
    for(Shapes* u: Shape) 
    {  
        u->draw();            
        u->change();
    }
    sh->draw();
    for(Shapes* u: Shape) //looping through animals list
    {   
        for(Bullet*& b: list_bullets) //looping through bullets list
        { 
            if(SDL_HasIntersection (u->getMover(),b->get_mover())) //collision of bullet and animal
            {
                                              
                explosive = new Explosion(b->get_x(),b->get_y()); //explosion object is created
                explosive -> exploding = true;  
                explosive->draw();
                delete u;
                Shape.remove(u);                
                delete b;
                list_bullets.remove(b);
                
            }
        }
    }

    for (Shapes* & u: Shape)
    {
        if (SDL_HasIntersection (u->getMover(),sh->get_mover()))
        {
            explosive = new Explosion(u->get_x(),u->get_y());
            explosive->exploding=true; //this sets the trigger for explosion animation
            delete u;
            Shape.remove(u);                
        }
    }
    // int bullet_x=sh->get_x();
    // int bulllet_y=sh->get_y();
    
    for(Bullet*& b: list_bullets)
    {   
        b->draw();   
    }
    // if (explosive->exploding==true && explosive->complete==false) //this will enable complete explosion animation
    // {
    //     explosive->draw();            
    //     explosive->drop();
    // }
    
    // sh->draw();
}

void ShapesShowdown::createObject()
{
    ShapesMain obj;   
    Shapes* newObject = obj.getObject();
    
    if (newObject != nullptr)
    {
        Shape.push_back(newObject);
    }
}

void ShapesShowdown::deleteObject()
{
    for(Shapes* u: Shape){
        delete u;
    }
    Shape.clear(); 
}

ShapesShowdown::ShapesShowdown()
{
    sh = new Shooter(730,500);
}

void ShapesShowdown::shoot()
{
    Bullet * bul = new Bullet(sh->get_x(),sh->get_y());
    list_bullets.push_back(bul);
}