//#include "Bullet.h"
//
//void gotoxy(int x, int y);
//
//Bullet::Bullet() : x(0), y(0), dx(0), dy(0), active(false) {}
//
//void Bullet::init(int startX, int startY, int dirX, int dirY)
//{
//    x = startX;
//    y = startY;
//    dx = dirX;
//    dy = dirY;
//    active = true;
//}
//
//void Bullet::move()
//{
//    if (!active) return;
//
//    // 현재 위치의 총알을 지우기
//    gotoxy(x, y);
//    std::cout << " ";
//
//    // 총알 위치 업데이트
//    x += dx;
//    y += dy;
//
//    // 새 위치에 총알을 그리기
//    if (x >= 0 && x < 120 && y >= 0 && y < 60)
//    {
//        gotoxy(x, y);
//        std::cout << "-";
//    }
//    else
//    {
//        active = false; // 화면 밖으로 나가면 총알 비활성화
//    }
//}
//
//bool Bullet::isOutOfBounds() const
//{
//    return !active; // 총알이 비활성화 상태이면 true
//}

#include "Bullet.h"

Bullet::Bullet(int startX, int startY, int dirX, int dirY)
    : x(startX), y(startY), dx(dirX), dy(dirY), active(true) {}

void Bullet::move() {
    if (!active) return;

    
    gotoxy(x, y);
    std::cout << " ";

    
    x += dx;
    y += dy;

    
    if (x >= 0 && x < 120 && y >= 0 && y < 60) {
        gotoxy(x, y);
        std::cout << "*";
    }
    else {
        active = false;
    }
}

bool Bullet::isActive() const {
    return active;
}

void Bullet::gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
