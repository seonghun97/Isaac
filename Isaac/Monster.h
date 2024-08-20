#pragma once
#include <iostream>
#include <string>
#include <windows.h>  
#include<conio.h>
#include<vector>
#include "Bullet.h"

class Monster
{
private:
	std::string Mname;
	int hp;
	int Damage;
	int Mx, My;
	int Mdx, Mdy;
    
	std::vector<Bullet> bullet;


public:
	Monster(std::string Mname, int hp, int Damage);

	void drawMonster(int monsterX, int monsterY);
	void TakeDamage(int Damage);
	void Attack();
    //void moveTowardsPlayer(int playerX, int playerY);
    bool isHit(const Bullet& bullet) const;
	
    std::string GetName() const
    {
        return Mname;
    }
    int GetHp() const
    {
        return hp;
    }
    int GetDamage() const
    {
        return Damage;
    }
    int GetMx() const
    {
        return Mx;
    }
    int GetMy() const
    {
        return My;
    }
    int GetMdx() const
    {
        return Mdx;
    }
    int GetMdy() const
    {
        return Mdy;
    }
 
};

