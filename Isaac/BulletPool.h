#pragma once
#include<vector>
#include"Bullet.h"

class BulletPool
{
private:
	std::vector<Bullet> pool;
	std::vector<Bullet*> available;

public:
	BulletPool(size_t size);
	Bullet* getBullet();
	void returnBullet(Bullet* bullet);
	std::vector<Bullet>& getPool();

	
};

