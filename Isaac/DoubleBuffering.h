#include<iostream>
#include<windows.h>
#include<vector>
#pragma once

const int width = 120;
const int height = 60;

class DoubleBuffering
{
public:
	DoubleBuffering(int width, int height);
	~DoubleBuffering();
	
	void clearBuffer();
	void swapBuffer();
	void displayBuffer();

private:
	std::vector<std::vector<char>> buffer1;
	std::vector<std::vector<char>> buffer2;
	std::vector<std::vector<char>>* currentBuffer;
	std::vector<std::vector<char>>* backBuffer;
	
	void hideCursor();
};



