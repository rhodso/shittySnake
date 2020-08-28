#ifndef FOOD_H
#define FOOD_H

#include "gameobject.h"
#include "grid.h"
#include "ofMain.h"

class food : public gameObject
{
public:
    //Constructor
    food();

    //Inherited draw function
    void draw() override;

    //Spawn function for getting new food
    void spawn();

};

#endif // FOOD_H
