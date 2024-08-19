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
    std::cout << " "; // ���� ��ġ�� �Ѿ� �����
    x += dx;
    y += dy;

    if (x >= 0 && x < 120 && y >= 0 && y < 60) 
    { // ȭ�� ���� �������� �ʾҴٸ� ���
        gotoxy(x, y);
       std:: cout << "-";
    }
    else 
    {
        active = false; // ȭ�� ������ ������ �Ѿ� ��Ȱ��ȭ
    }
}

bool Bullet::isOutOfBounds() const 
{
    return !active; // �Ѿ��� ��Ȱ��ȭ �����̸� true
}