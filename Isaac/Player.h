#pragma once

#include <iostream>
#include <string>
#include <windows.h>  
#include<conio.h>
#include<vector>

class Player
{
private:
    std::string name;
    int Hp;  // ���� ü��
    int Damage;  // �ִ� ������
    int Range;  // ��Ÿ�
    int AtkSpeed;  // ���� �ӵ�
    int PlayerSpeed;  // �̵� �ӵ�
    int Px;  // X ��ǥ
    int Py;  // Y ��ǥ

public:
    void TextColor(int font, int backGround) const;

    // �÷��̾��� ��Ʈ ��Ʈ�� �׸��� �޼����
    void DrawPlayerF() const;
    void DrawPlayerB() const;
    void DrawPlayerSideLeft() const;
    void DrawPlayerSideRight() const;
    void DrawPlayerSideLeftWalk() const;
    void DrawPlayerSideRightWalk() const;

    Player(std::string name, int Hp, int Damage, int Range, int AtkSpeed, int PlayerSpeed, int Px, int Py);

    void TakeDamage(int damage);
    void PlayerMove(char direction);
    void Attack();
    void DisplayHealth() const;

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
