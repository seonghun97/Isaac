#pragma once
#include<iostream>
#include<vector>

class Boom
{

private:
	int x, y;  //��ź��ǥ
	int BoomArea;   //��ź����
	bool isVisible;  //��ź�� �����̴� ����
	float blinkTimer; //Ÿ�̸�
	std::vector<Boom>& boom;


public:
	Boom(int x, int y, int BoomArea, float blinkTimer, std::vector<Boom>& boom);

	void updateBooms();
	void DrawBoom()const;
};

