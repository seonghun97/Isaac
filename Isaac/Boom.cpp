#include "Boom.h"
#include "monster.h"
#include "Player.h"



void gotoxy(int x, int y);
void TextColor(int font, int backGround);


Boom::Boom(int x, int y, int BoomArea, float blinkTimer, std::vector<Boom>& boom)
    :x(x),y(y),BoomArea(BoomArea),blinkTimer(blinkTimer),boom(boom)
{
}

void Boom::updateBooms()
{


}

void Boom::DrawBoom()const
{
    const int height = 3;

    std::string Boom[height] =
    {
        "0000",
        "0000",
        "0000",
    };
    for (int i = 0; i < height; ++i)
    {
        COORD coord = { (SHORT)x,(SHORT)(y + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for(char& c : Boom[i])
        {
            if (c == '0')
            {
                TextColor(6, 6);
                std::cout << "бс";
            }
        }

    }
    TextColor(15, 0);
}
