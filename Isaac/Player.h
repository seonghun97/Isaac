#include<iostream>
#pragma once
class Player
{
private:
	std::string name;
	int MaxHp; //�ִ�ü���� 6 �������� Ȱ���ϸ� ��������ų������
	int Hp; // ����ü�� ����ü���� �ִ�ü���� �ѱ������ �ҿ���Ʈ �������� �������ȸ���
	int Damage; //�ִµ����� �⺻�������� 2 �̰� ���ݷ��̿ö󰡴� �����۸����� 3������
	int Range; //��Ÿ�
	int AtkSpeed; //���ݼӵ�
	int PlayerSpeed; //�̵��ӵ�

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

