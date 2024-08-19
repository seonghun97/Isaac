#include "DoubleBuffering.h"

DoubleBuffering::DoubleBuffering(int width, int height)
	
	:buffer1(height, std::vector<char>(width,' ')),
	buffer2(height, std::vector<char>(width, ' ')),
	currentBuffer(&buffer1),
	backBuffer(&buffer2)
{
	hideCursor();
}
DoubleBuffering::~DoubleBuffering()
{

}

void DoubleBuffering::clearBuffer()
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			(*currentBuffer)[y][x] = ' ';
		}
	}
}


void DoubleBuffering::swapBuffer()
{
	std::swap(currentBuffer, backBuffer);
}


void DoubleBuffering::displayBuffer()
{
	std::cout << "x18[H";
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			std::cout << (*backBuffer)[y][x];
		}
		std::cout << std::endl;

	}

}

void DoubleBuffering::hideCursor()
{
	CONSOLE_CURSOR_INFO cursorinfo;
	cursorinfo.dwSize = 1;
	cursorinfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorinfo);
}