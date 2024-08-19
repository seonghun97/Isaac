//#include "BulletPool.h"
//
//BulletPool::BulletPool(size_t size)
//{
//	pool.resize(size);
//	for (size_t i = 0; i < size; ++i)
//	{
//		available.push_back(&pool[i]);
//	}
//}
//
//Bullet* BulletPool::getBullet()
//{
//	if (available.empty())
//	{
//		return nullptr;
//	}
//	Bullet* bullet = available.back();
//	available.pop_back();
//	return bullet;
//}
//
//void BulletPool::returnBullet(Bullet* bullet)
//{
//	bullet->active = false;
//	available.push_back(bullet);
//}
//
//std::vector<Bullet>& BulletPool::getPool()
//{
//	return pool;
//}
