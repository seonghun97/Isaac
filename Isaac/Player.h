#include<iostream>
#pragma once
class Player
{
private:
	std::string name;
	int MaxHp; //최대체력은 6 아이템을 활용하면 더증가시킬수있음
	int Hp; // 남은체력 남은체력은 최대체력을 넘길수없음 소울하트 구현예정 지금은안만듬
	int Damage; //주는데미지 기본데미지는 2 이고 공격력이올라가는 아이템먹으면 3배증가
	int Range; //사거리
	int AtkSpeed; //공격속도
	int PlayerSpeed; //이동속도

public:
	Player(std::string name, int MaxHp, int Hp, int Damage, int Range, int AtkSpeed, int PlayerSpeed)
		:name(name), MaxHp(MaxHp), Hp(Hp), Damage(Damage), Range(Range), AtkSpeed(AtkSpeed), PlayerSpeed(PlayerSpeed) {}
	std::string GetName() const
	{
		return name;
	}
	int GetMaxHp()
	{
		return MaxHp;
	}
	int GetHp()
	{
		return Hp;
	}
	int GetDamage()
	{
		return Damage;
	}
	int GetRange()
	{
		return Range;
	}
	int GetAtkSpeed()
	{
		return AtkSpeed;
	}
	int GetPlayerSpeed()
	{
		return PlayerSpeed;
	}

public:

	void TakeDamage(){}
	void PlayerMove()
	{

	}




};

