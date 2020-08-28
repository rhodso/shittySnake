#include "snake.h"
#include "game.h"
#include "grid.h"
#include "debugger.h"
#include "food.h"

//Constructor and Destructor
snake::snake(){
    snakeBaseColour = ofColor::green;
}
snake::~snake(){
    if(tail != nullptr){
        tail->~snakeBit();
    }
    delete tail;
}

//Getters and setters
int snake::getDirection(){ return direction; }
ofColor snake::getBaseColour(){ return snakeBaseColour; }
void snake::setDirection( int _direction){ direction = _direction; }

//Inherited methods
void snake::move(){
    //First, store our current coords
    //It's a suprise tool that'll help up later
    int pX = x;
    int pY = y;

    //Need to do some collison checking with our own body.
    snakeBit* tmp = tail;
    //Loop through each tail segment and check if the head overlaps
    while(tmp != nullptr){
        if(tmp->getX() == x && tmp->getY() == y){
            game::end();
        } else {
            tmp = tmp->getTail();
        }
    }

    //Find the square we're going to move into, check it's not an edge
    switch(direction){
        case 0: //Up
            if(x == 0){ game::end(); }
            else{ x--; }
            break;
        case 1: //Right
            if(y == grid::getGW()){ game::end(); }
            else{ y++; }
            break;
        case 2: //Down
            if(x == grid::getGH()){ game::end(); }
            else{ x++; }
            break;
        case 3: //Left
            if(y == 0){ game::end(); }
            else{ y--; }
            break;
    }

    //Now that we're certian that we're not dead,
    //We can check for food and then we can move the rest of the snake.
    //Snake body doesn't need all this fancy collision stuff
    //Since it only follows the head

    //See if we've eaten some food
    if(game::getFood().getX() == x && game::getFood().getY() == y){
        this->eat();
    }

    //Move the tail along
    if(tail != nullptr){
        tail->move(pX, pY);
    }

}
void snake::draw(){
    //Draw head
    grid::setTileColour(x,y,ofColor::green);

    //Draw tail recursivley
    if(tail != nullptr){
        tail->draw();
    }
}

//Other methods
void snake::turn(bool left){
    //Update direction based on the arg
    if(left){
        direction--;
    } else {
        direction++;
    }

    //Direction is in range -1 to 4 inclusive
    //Need to make it exclusive
    if(direction < 0){
        direction = 3;
    } else if(direction > 3){
        direction = 0;
    }
}

void snake::eat(){
    //Tell the game we need to spawn more food
    game::setEatFlag(true);

    //Grow the tail
    if(tail != nullptr){
        tail->grow();
    } else{
        tail = new snakeBit(x, y);
    }
}
