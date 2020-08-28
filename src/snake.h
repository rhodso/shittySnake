#ifndef SNAKE_H
#define SNAKE_H

#include "ofMain.h"
#include "gameobject.h"
#include "snakebit.h"

class snake : public gameObject
{
public:
    //Constructor and deconstructor
    snake();
    ~snake();

    //Getters and setters
    int getDirection();
    ofColor getBaseColour();
    void setDirection( int _direction );

    //Inherited methods
    void move() override;
    void draw() override;

    //Other methods
    void turn(bool left); //Since the snake can only turn left or right, and there's similar functionality, this is the best way
    void eat();

private:
    snakeBit* tail = nullptr;   //Pointer to the tale
    ofColor snakeBaseColour;    //Snake color, in case people want a yellow snake for some reason

    int direction; //Direction the snake is facing, see below
    /*
        0 = Up
        1 = Right
        2 = Down
        3 = Left

        To Turn:
        Turn left = --
        Turn right = ++
    */


};

#endif // SNAKE_H
