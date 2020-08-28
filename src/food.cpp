#include "food.h"
#include <random>
#include "debugger.h"

//Constructor
food::food(){}

//Inherited draw function
void food::draw(){
    //Draw the food at the given x/y in red
    grid::setTileColour(x, y, ofColor::red);
}

//Spawn new food
void food::spawn(){
    //Create temp vectors for storing stuff
    std::vector<tile*> validTiles;
    std::vector<std::vector<tile>> gs = grid::getGameSpace();

    //Find every tile that's currently black and add it to the validTiles vect
    for(int i = 0; i < grid::getGH(); i++){
        for(int j = 0; j < grid::getGW(); j++){
            if(gs[i][j].getColour() == ofColor::black){
                validTiles.push_back(&gs[i][j]);
            }
        }
    }

    //Pick a random one and get the grid X/Y for the food to spawn
    int idx = rand() % validTiles.size();
    x = validTiles[idx]->getGridX();
    y = validTiles[idx]->getGridY();

    //Log that we created food
    std::string msg = "Created new food at (X/Y) "; msg += std::to_string(x); msg += "/"; msg += std::to_string(y);
    debugger::log(msg);

    //Cleanup
    validTiles.clear();
    gs.clear();
}
