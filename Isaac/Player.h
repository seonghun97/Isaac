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
    int Hp;  //  ü��
    int Damage;  // �ִ� ������
    int Range;  // ��Ÿ�
    int AtkSpeed;  // ���� �ӵ�
    int PlayerSpeed;  // �̵� �ӵ�
    int Px;  // X ��ǥ
    int Py;  // Y ��ǥ
    int dx, dy; //�Ѿ���ǥ
    std::vector<Bullet> bullets;  //�Ѿ˼�
    bool invincible; // ���� ���� ����
    std::chrono::time_point<std::chrono::steady_clock> invincibleEndTime;


public:
    void TextColor(int font, int backGround) const;
    // �÷��̾��� ��Ʈ ��Ʈ�� �׸��� �޼����

    void DrawPlayerF() const;
    void DrawPlayerB() const;
    void DrawPlayerSideLeft() const;
    void DrawPlayerSideRight() const;
    void DrawPlayerSideLeftWalk() const;
    void DrawPlayerSideRightWalk() const;

    bool CollidingWithMonster(const Monster& monster) const; // ���Ϳ��� �浹 ����

    Player(std::string name, int Hp, int Damage, int Range, int AtkSpeed, int PlayerSpeed, int Px, int Py);

    void UpdateBullets(Monster& monster);
    void TakeDamage(int damage);
    void PlayerMove(char direction);
    void DrawHearts() const;
    void Attack();
    void gotoxy(int x, int y);
    void UpdateInvincibility(); // ���� ���� ������Ʈ �Լ�

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
