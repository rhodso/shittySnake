#ifndef GAME_H
#define GAME_H

#include "food.h"

class game
{
public:
    game();

    //Getters and setters
    static food getFood();
    static void setEatFlag(bool _state);

    //Other methods
    static void end();
    static void drawFood();
    static void checkFood();

private:
    //Keeps track of the food and wheater it's been eaten
    inline static food f = food();
    inline static bool eatFlag = false;

};

#endif // GAME_H
