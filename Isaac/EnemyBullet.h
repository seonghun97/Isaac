#pragma once
#include<iostream>
#include<windows.h>

class EnemyBullet
{
public:
	int ex;
	int ey;
	int edx;
	int edy;
	bool e_active;

	EnemyBullet(int startX, int startY, int dirX, int dirY);

	void move();

	bool isActive() const;
private:
	void gotoxy(int x, int y);



};

