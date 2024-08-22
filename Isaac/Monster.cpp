#pragma once

#include "monster.h"


// 콘솔 텍스트 색상 설정 함수
void TextColor(int foreground, int background) {
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

Monster::Monster(std::string Mname, int hp, int Damage, int movecounter)
    :Mname(Mname), hp(hp), Damage(Damage),Mx(48),My(3),Mdx(0),Mdy(0),movecounter(0)
{
}

void Monster::drawMonster(int monsterX, int monsterY) {
    const int height = 15;
    const int width = 17;

    std::string isaac[height] = {
        "      000000     ",
        "     01111110    ",
        "    0111111110   ",
        "   011111111110  ",
        "   013011113010  ",
        "   010011110010  ",
        "   012200002210  ",
        "    0210000120   ",
        "     01111110    ",
        "    0100000010   ",
        "    0001111000   ",
        "      011110     ",
        "      011110     ",
        "      010010     ",
        "      11  11     "
    };

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < height; ++i) {
        COORD coord;
        coord.X = monsterX;
        coord.Y = monsterY + i;
        SetConsoleCursorPosition(hConsole, coord);

        for (char c : isaac[i]) {
            if (c == '0') {
                TextColor(8, 8);  // 회색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '1') {
                TextColor(15, 15);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '2') {
                TextColor(11, 11);  // 연파랑 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '3') {
                TextColor(15, 15);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else {
                TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
                std::cout << " ";
            }
        }
    }

    // 마지막에 콘솔 색상 리셋
    TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
}

void Monster::deathMonster() {
    const int height = 15;
    const int width = 17;

    std::string isaac[height] = {
        "      000000     ",
        "     01111110    ",
        "    0111111110   ",
        "   011111111110  ",
        "   013011113010  ",
        "   010011110010  ",
        "111012200002210111  ",
        " 1110210000120111   ",
        "  11101111110111    ",
        "    0100000010   ",
        "    0001111000   ",
        "      011110     ",
        "      011110     ",
        "      010010     ",
        "      11  11     "
    };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < height; ++i) {
        COORD coord = { (SHORT)Mx, (SHORT)(My + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char c : isaac[i]) {
            if (c == '0') {
                TextColor(8, 8);  // 회색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '1') {
                TextColor(15, 15);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '2') {
                TextColor(11, 11);  // 연파랑 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '3') {
                TextColor(15, 15);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else {
                TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
                std::cout << " ";
            }
        }
    }

    // 마지막에 콘솔 색상 리셋
    TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
}
void Monster::Attack()
{
}

void Monster::monsterHpBar()
{
    
        COORD coord;
        coord.X = 80;
        coord.Y = 53;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "아이작의 HP : ";

        int hearts = hp / 5;

        for (int i = 0; i < 16; ++i)
        {
            if (i < hearts)
            {
                std::cout << "■";
            }
            else
            {
                std::cout << "□";
            }
        }
    
}


bool Monster::isHit(const Bullet& bullet) const
{
    const int width = 17;  // 몬스터의 너비
    const int height = 15;  // 몬스터의 높이

    int bulletX = bullet.GetX();
    int bulletY = bullet.GetY();

    
    return (bulletX >= Mx && bulletX < Mx + width && bulletY >= My && bulletY < My + height);
}




void Monster::TakeDamage(int Damage)
{
    hp -= Damage;
    
    if (hp <= 0)
    {
        std::cout << Mname << "이 죽었다!" << "플레이어 윈" << std::endl;
    }
}
void Monster::moveTowardsPlayer(int playerX, int playerY) 
{
    if (movecounter == 0)
    {


        for (int i = 0; i < 15; ++i)
        {
            COORD coord = { (SHORT)Mx, (SHORT)(My + i) };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            std::cout << "                ";
        }
        if (Mx < playerX)
        {
            Mx++;
        }
        else if (Mx > playerX) 
        {
            Mx--;
        }

        if (My < playerY) 
        {
            My++;
        }
        else if (My > playerY)
        {
            My--;
        }
        if (Mx > 88)
        {
            Mx = 88;
        }
        else if (Mx < 0) {
            Mx = 0;
        }

        if (My > 37) {
            My = 37;
        }
        else if (My < 0) {
            My = 0;
        }
    }
    movecounter = (movecounter + 1) % 16;
    
    }
        
    




