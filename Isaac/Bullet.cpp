#include "Bullet.h"

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Bullet::Bullet() : x(0), y(0), dx(0), dy(0), active(false) {}

void Bullet::init(int startX, int startY, int dirX, int dirY)
{
    x = startX;
    y = startY;
    dx = dirX;
    dy = dirY;
    active = true;
}

void Bullet::move() 
{
    if (!active) return;

    gotoxy(x, y);
    std::cout << " "; // 이전 위치의 총알 지우기
    x += dx;
    y += dy;

    if (x >= 0 && x < 120 && y >= 0 && y < 60) 
    { // 화면 끝에 도달하지 않았다면 출력
        gotoxy(x, y);
       std:: cout << "-";
    }
    else 
    {
        active = false; // 화면 밖으로 나가면 총알 비활성화
    }
}

bool Bullet::isOutOfBounds() const 
{
    return !active; // 총알이 비활성화 상태이면 true
}