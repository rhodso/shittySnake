#include "snakebit.h"
#include "grid.h"
#include "debugger.h"

//Constructors and destructors
snakeBit::snakeBit(){ tail = nullptr; }
snakeBit::snakeBit(int _x, int _y){
    x = _x;
    x = _y;
    tail = nullptr;
}
snakeBit::~snakeBit(){
    //Make sure we call the deconstructors in reverse order so there's no memory leaks
    if(tail != nullptr){
        tail->~snakeBit();
    }
    delete tail;
}

snakeBit* snakeBit::getTail(){ return tail; }

void snakeBit::draw(){
    //Draw this bit
    grid::setTileColour(x,y,ofColor::green);

    //Draw tail recursivley
    if(tail != nullptr){
        tail->draw();
    }
}

void snakeBit::move(int _x, int _y){
    //Store our current values
    int pX = x;
    int pY = y;

    //Move to new value
    x = _x;
    y = _y;

    //Move tail
    if(tail != nullptr){
        tail->move(pX, pY);
    }
}

//Grow the tail
void snakeBit::grow(){
    if(tail != nullptr){
        //If this isn't the end then keep going until it is
        tail->grow();
    } else{
        //Create a new tail here and it'll appear next time the snake moves
        tail = new snakeBit(x, y);
        std::string msg = "Created tail at (X/Y) "; msg += std::to_string(x); msg += "/"; msg += std::to_string(y);
        debugger::log(msg);
    }
}

