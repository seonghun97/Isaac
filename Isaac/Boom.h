#pragma once
#include<iostream>
#include<vector>

class Boom
{

private:
	int x, y;  //ÆøÅºÁÂÇ¥
	int BoomArea;   //ÆøÅº¹üÀ§
	bool isVisible;  //ÆøÅºÀÌ ±ô¹ÚÀÌ´Â »óÅÂ
	float blinkTimer; //Å¸ÀÌ¸Ó
	std::vector<Boom>& boom;


public:
	Boom(int x, int y, int BoomArea, float blinkTimer, std::vector<Boom>& boom);

	void updateBooms();
	void DrawBoom()const;
};

