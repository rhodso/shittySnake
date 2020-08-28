#include "gameobject.h"

//Constructor/Deconstructor
gameObject::gameObject(){}
gameObject::~gameObject(){}

//Getters and setters
int gameObject::getX(){ return x; }
int gameObject::getY(){ return y; }

void gameObject::setX( int _x){ x = _x; }
void gameObject::setY( int _y){ y = _y; }

//Methods to be inherited
void gameObject::draw(){}
void gameObject::move(){}
