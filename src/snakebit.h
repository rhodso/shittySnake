#ifndef SNAKEBIT_H
#define SNAKEBIT_H

#include "gameobject.h"

class snakeBit : public gameObject
{
public:
    //Constructors and destructors
    snakeBit();
    snakeBit(int _x, int _y);
    ~snakeBit();

    //Get the tail, needed for SLL stuff
    snakeBit* getTail();

    //Inherrited methods
    void move(int _x, int _y); //This is an override, but we're changing the signature, so it isn't
    void draw() override;

    //Other methods
    void grow();

private:
    //Store a pointer to the next tail segment, but make it a null pointer for now
    snakeBit* tail = nullptr;
};

#endif // SNAKEBIT_H
