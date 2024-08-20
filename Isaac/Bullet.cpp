

#include "Bullet.h"

Bullet::Bullet(int startX, int startY, int dirX, int dirY)
    : x(startX), y(startY), dx(dirX), dy(dirY), active(true) {}

void Bullet::move() 
{
    if (!active) return;
    
    gotoxy(x, y);
    std::cout << " ";

    
    x += dx;
    y += dy;

    if (x >= 1 && x < 109 && y >= 1 && y < 52) 
    {
        gotoxy(x, y);
        std::cout << "0";
    }
    else 
    {
        active = false;
    }
}

bool Bullet::isActive() const 
{
    return active;
}

void Bullet::gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
