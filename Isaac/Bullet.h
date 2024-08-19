//#pragma once
//#include <iostream>
//#include <windows.h>
//class Bullet {
//public:
//    int x, y;
//    int dx, dy;
//    bool active; // 총알이 활성화된 상태인지 확인하는 플래그
//
//    Bullet(); // 기본 생성자
//    void init(int startX, int startY, int dirX, int dirY); // 총알 초기화
//    void move(); // 총알 이동
//    bool isOutOfBounds() const; // 총알이 화면 밖으로 나갔는지 확인
//};
#pragma once
#include <iostream>
#include <windows.h>

class Bullet {
public:
    // 총알의 위치와 이동 방향을 나타내는 멤버 변수
    int x, y;
    int dx, dy;
    bool active;

    // 생성자: 총알의 초기 위치와 방향을 설정
    Bullet(int startX, int startY, int dirX, int dirY);

    // 총알을 이동시키는 메서드
    void move();

    // 총알이 활성화 상태인지 확인하는 메서드
    bool isActive() const;

private:
    // 콘솔 커서의 위치를 설정하는 메서드
    void gotoxy(int x, int y);
};
