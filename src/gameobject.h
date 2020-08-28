#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


class gameObject
{
public:
    //Constructor and deconstructor
    gameObject();
    ~gameObject();

    //Getters and setters
    int getX();
    int getY();

    void setX( int _x );
    void setY( int _y );

    //Methods to be inherited
    virtual void draw();
    virtual void move();

protected:
    //Represents X/Y on the grid
    int x;
    int y;
};

#endif // GAMEOBJECT_H
