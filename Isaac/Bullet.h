
#pragma once
#include <iostream>
#include <windows.h>

class Bullet {
private:
    int x, y;
    int dx, dy;
    bool active;
    void gotoxy(int x, int y);
public:
    Bullet(int startX, int startY, int dirX, int dirY);

    void move();
    bool isActive() const;
    /*int getX();
    int getY();*/

    int GetX() const
    {
        return x;
    }
    int GetY() const
    {
        return y;
    }
    int GetDx() 
    {
        return dx;
    }
    int GetDy()
    {
        return dy;
    }
};
