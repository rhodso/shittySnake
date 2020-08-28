#include "game.h"
#include "debugger.h"
#include "grid.h"

//Construcor
game::game(){}

//Getters and setters
food game::getFood(){ return f; }
void game::setEatFlag(bool _state){ eatFlag = _state; }

//Other methods
void game::end(){
    debugger::log("Snake is kill. This is so sad");

    //I can't think of anything better, so just kill the app when the snake dies
    ofExit(0);
}
void game::drawFood(){ f.draw(); }
void game::checkFood(){
    //Unset the flag and spawn food
    if(eatFlag){
        eatFlag = false;
        f.spawn();
    }
}

