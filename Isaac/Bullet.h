#pragma once
#include <iostream>
#include <windows.h>
class Bullet {
public:
    int x, y;
    int dx, dy;
    bool active; // 총알이 활성화된 상태인지 확인하는 플래그

    Bullet(); // 기본 생성자
    void init(int startX, int startY, int dirX, int dirY); // 총알 초기화
    void move(); // 총알 이동
    bool isOutOfBounds() const; // 총알이 화면 밖으로 나갔는지 확인
};
