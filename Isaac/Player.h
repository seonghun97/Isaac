#pragma once

#include <iostream>
#include <string>
#include <windows.h>  
#include<conio.h>
#include<vector>
#include "Bullet.h"
#include "monster.h"
#include <chrono>


class Player
{
private:
    std::string name;
    int Hp;  //  체력
    int Damage;  // 주는 데미지
    int Range;  // 사거리
    int AtkSpeed;  // 공격 속도
    int PlayerSpeed;  // 이동 속도
    int Px;  // X 좌표
    int Py;  // Y 좌표
    int dx, dy; //총알좌표
    std::vector<Bullet> bullets;  //총알수
    bool invincible; // 무적 상태 여부
    std::chrono::time_point<std::chrono::steady_clock> invincibleEndTime;


public:
    void TextColor(int font, int backGround) const;
    // 플레이어의 도트 아트를 그리는 메서드들

    void DrawPlayerF() const;
    void DrawPlayerB() const;
    void DrawPlayerSideLeft() const;
    void DrawPlayerSideRight() const;
    void DrawPlayerSideLeftWalk() const;
    void DrawPlayerSideRightWalk() const;

    bool CollidingWithMonster(const Monster& monster) const; // 몬스터와의 충돌 감지

    Player(std::string name, int Hp, int Damage, int Range, int AtkSpeed, int PlayerSpeed, int Px, int Py);

    void UpdateBullets(Monster& monster);
    void TakeDamage(int damage);
    void PlayerMove(char direction);
    void DrawHearts() const;
    void Attack();
    void gotoxy(int x, int y);
    void UpdateInvincibility(); // 무적 상태 업데이트 함수

    std::string GetName() const
    {
        return name; 
    }
    int GetHp() const 
    { 
        return Hp;
    }
    int GetDamage() const
    {
        return Damage;
    }
    int GetRange() const 
    {
        return Range;
    }
    int GetAtkSpeed() const
    {
        return AtkSpeed; 
    }
    int GetPlayerSpeed() const 
    {

        return PlayerSpeed;
    }
    int GetPlayerCoorX() const
    {
        return Px;
    }
    int GetPlayerCoorY() const
    {
        return Py;
    }
    int GetDx() const
    {
        return dx;
    }
    int GetDy() const
    {
        return dy;
    }
    
};
