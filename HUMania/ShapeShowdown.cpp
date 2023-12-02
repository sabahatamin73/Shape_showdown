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
        int maxAttempts = 20; 
        
        int fixedY = 0; 

        do {
            randomNumberx = 25 + (rand() % 1250);
        } while (checkOverlap(randomNumberx, fixedY) && maxAttempts-- > 0);
        
        if (maxAttempts <= 0) {
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
    // if(t) {
    //  t->draw();
    // }
    drawScore();
    // t->draw(score);
    for(Shapes* u: Shape) 
    {  
        u->draw();            
        u->change();
    }

    std::cout << "bullllllllet list ==== " << list_bullets.size() << "\n";
    for(Bullet* b: list_bullets)
    {   
        b->draw();   
    }
    sh->draw();
    for(Shapes* u: Shape) 
    {   
        for(Bullet*& b: list_bullets) 
        { 
            if(SDL_HasIntersection (u->getMover(),b->get_mover())) 
            {
                                              
                explosive = new Explosion(b->get_x(),b->get_y()); 
                explosive -> exploding = true;  
                explosive->draw();
                int bomb_x= b->get_x();
                int bomb_y= b->get_y();
                int r = rand() % 99;
                if (r < 45)                 
                bomb_dropping(bomb_x , bomb_y);
                score=score+5;
                delete u;
                Shape.remove(u);                
                delete b;
                list_bullets.remove(b);
            }
        }
    }
    for (Bomb * & b : bomb)
    {
        if (SDL_HasIntersection (b->getMover(),sh->get_mover()))
        {
            explosive_1 = new Explosion_1(b->get_x(),sh->get_y());
            explosive_1->draw();
            int life = sh->get_life()-1;
            sh->set_life(life);
            delete b;
            bomb.remove(b);     //bombs, bullets, objects are deleted simulataneously
            
        }
    }
    l->draw(sh->get_life());
    for (Shapes * & u: Shape)
    {
        if (SDL_HasIntersection (u->getMover(),sh->get_mover()))
        {
            explosive_1 = new Explosion_1(u->get_x(),sh->get_y());
            explosive_1->draw();
            
            int life = sh->get_life()-1;
            sh->set_life(life); 
            delete u;
            Shape.remove(u);                
            
        }

    }
    for(Bomb*& b: bomb)
    {   
        b->draw();
        if (b->get_y()>=645) 
        {
            bomb.remove(b);
            delete b;
        }
    }
    for (Shapes  * & u: Shape)
    {
        if (u->get_y()>=645) 
        {              
            delete u;
            Shape.remove(u);                
            score-=5;
        }
    }
    if (*sh > 0)  //OPERATOR OVERLOADING: if shooter has life then it is drawn
    {
        sh->draw();
    }

    if (*sh==0 || score<0)  // OPERATOR OVERLOADING:if shooter health is zero or score is 0, game has to end
    {
        flag = true;
    }
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

void ShapesShowdown::bomb_dropping(int x, int y){
    Bomb * b = new Bomb(x , y);
    bomb.push_back(b);
}

void ShapesShowdown::deleteObject()
{
    for(Shapes* u: Shape){
        delete u;
    }
    Shape.clear(); 

    for(Bullet*& b: list_bullets)
    {
        delete b;
		list_bullets.remove(b);	    
    }
    list_bullets.clear();

    for(Bomb*& b: bomb)
    {
        delete b;
		bomb.remove(b);
	    
    }
    bomb.clear();
}

ShapesShowdown::ShapesShowdown()
{
    t = new Text();
    sh = new Shooter(730,545);
    l = new Life(50,50);

    bool flag=false; 
}

void ShapesShowdown::set_life()
{    
    sh->set_life(5);
}

void ShapesShowdown::shoot()
{
    Bullet * bul = new Bullet(sh->get_x(),sh->get_y());
    list_bullets.push_back(bul);
    std::cout << " in shooot bullllllllet list ==== " << list_bullets.size() << "\n";
}
void ShapesShowdown:: play_again(){
    flag = false;
    sh -> set_life(5);
    sh -> set_coordinates();
    score = 0;
}

bool ShapesShowdown::game_end()
{
    if (flag==true)
    {
        return true;
    }
    return false;
}

void ShapesShowdown:: set_score()
{
    score=0;
}

void ShapesShowdown:: drawScore()
{
    t->draw(score);
}