#pragma once

#include <iostream>
#include <string>
#include <windows.h>  
#include<conio.h>
#include<vector>
#include "Bullet.h"

class Bullet;

class Player
{
private:
    std::string name;
    int Hp;  // 남은 체력
    int Damage;  // 주는 데미지
    int Range;  // 사거리
    int AtkSpeed;  // 공격 속도
    int PlayerSpeed;  // 이동 속도
    int Px;  // X 좌표
    int Py;  // Y 좌표
    int dx, dy;
    std::vector<Bullet> bullets;
    
public:
    void TextColor(int font, int backGround) const;

    // 플레이어의 도트 아트를 그리는 메서드들
    void DrawPlayerF() const;
    void DrawPlayerB() const;
    void DrawPlayerSideLeft() const;
    void DrawPlayerSideRight() const;
    void DrawPlayerSideLeftWalk() const;
    void DrawPlayerSideRightWalk() const;
    

    Player(std::string name, int Hp, int Damage, int Range, int AtkSpeed, int PlayerSpeed, int Px, int Py);

    void UpdateBullets();
    void TakeDamage(int damage);
    void PlayerMove(char direction);
    void DrawHearts() const;
    void Attack();
    void gotoxy(int x, int y);

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
    
};
