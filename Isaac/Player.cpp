#include "Player.h"

Player::Player(std::string name, int Hp, int Damage, int Range, int AtkSpeed, int PlayerSpeed, int Px, int Py)
    : name(name), Hp(Hp), Damage(Damage), Range(Range), AtkSpeed(AtkSpeed), PlayerSpeed(PlayerSpeed), Px(Px), Py(Py)
{
}

void Player::TakeDamage(int damage) 
{
    Hp -= damage;
    if (Hp <= 0)
    {
        std::cout << name << " 사망" << std::endl;
        Hp = 0; 
    }
    DrawHearts(); 
}

void Player::DrawHearts() const 
{
    COORD coord;
    coord.X = 55;
    coord.Y = 62;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout <<"플레이어의 HP : " ;

    int hearts = Hp / 1;  

    for (int i = 0; i < 6; ++i) 
    {
        if (i < hearts)
        {
            std::cout << "♥ "; 
        }
        else
        {
            std::cout << "♡ ";
        }
    }
}

void Player::TextColor(int font, int backGround) const 
{
    int Color = font + backGround * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void Player::DrawPlayerF() const
{
    const int height = 8;

    std::string Player[height] = 
    {
        "    0000       ",
        "   0    0 ",
        "  0 1  1 0 ",
        "   0    0 ",
        "    0000          ",
        "   0 00 0         ",
        "    0  0    ",
        "    0  0       ",
    };

    for (int i = 0; i < height; ++i)
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char& c : Player[i]) 
        {
            if (c == '0') 
            {
                TextColor(8, 8);  // 회색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '1') 
            {
                TextColor(15, 15);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else
            {
                TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
                std::cout << " ";
            }
        }
    }

    TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
}

void Player::DrawPlayerB() const
{
    const int height = 8;

    std::string Playerb[height] = 
    {
        "    0000       ",
        "   0    0 ",
        "  0      0 ",
        "   0    0 ",
        "    0000          ",
        "   0 00 0         ",
        "    0  0    ",
        "    0  0       ",
    };

    for (int i = 0; i < height; ++i)
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char& c : Playerb[i]) 
        {
            if (c == '0')
            {
                TextColor(8, 8);  // 회색 전경, 검은색 배경
                std::cout << "■";
            }
            else
            {
                TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
                std::cout << " ";
            }
        }
    }

    TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
}

void Player::DrawPlayerSideLeft() const 
{
    const int height = 8;

    std::string Players[height] =
    {
        "    0000       ",
        "   0    0 ",
        "  0 1    0 ",
        "   0    0 ",
        "    0000      ",
        "     00             ",
        "     00    ",
        "     00       ",
    };

    for (int i = 0; i < height; ++i)
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char& c : Players[i])
        {
            if (c == '0')
            {
                TextColor(8, 8);  // 회색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '1') 
            {
                TextColor(15, 15);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else
            {
                TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
                std::cout << " ";
            }
        }
    }

    TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
}

void Player::DrawPlayerSideRight() const
{
    const int height = 8;

    std::string Players[height] =
    {
        "    0000       ",
        "   0    0 ",
        "  0    1 0 ",
        "   0    0 ",
        "    0000      ",
        "     00             ",
        "     00    ",
        "     00       ",
    };

    for (int i = 0; i < height; ++i)
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char& c : Players[i]) 
        {
            if (c == '0')
            {
                TextColor(8, 8);  // 회색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '1')
            {
                TextColor(15, 15);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else 
            {
                TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
                std::cout << " ";
            }
        }
    }

    TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
}

void Player::DrawPlayerSideLeftWalk() const 
{
    const int height = 8;

    std::string Player[height] = 
    {
        "    0000       ",
        "   0    0 ",
        "  0 1    0 ",
        "   0    0 ",
        "    0000      ",
        "     00             ",
        "    0 0    ",
        "   0  0       ",
    };

    for (int i = 0; i < height; ++i)
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char& c : Player[i])
        {
            if (c == '0') 
            {
                TextColor(8, 8);  // 회색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '1') 
            {
                TextColor(15, 15);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else 
            {
                TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
                std::cout << " ";
            }
        }
    }

    TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
}

void Player::DrawPlayerSideRightWalk() const 
{
    const int height = 8;

    std::string Player[height] =
    {
        "    0000       ",
        "   0    0 ",
        "  0    1 0 ",
        "   0    0 ",
        "    0000      ",
        "     00             ",
        "     0 0   ",
        "     0  0       ",
    };

    for (int i = 0; i < height; ++i) 
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char& c : Player[i]) 
        {
            if (c == '0')
            {
                TextColor(8, 8);  // 회색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '1')
            {
                TextColor(15, 15);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else 
            {
                TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
                std::cout << " ";
            }
        }
    }

    TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
}

void Player::PlayerMove(char direction) 
{
    for (int i = 0; i < 8; ++i)
    {
        COORD coord = { Px, Py + i };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "                "; 
    }

    switch (direction)
    {
    case 'w':
        if (Py > 1) Py--;
        DrawPlayerB();
        break;
    case 's':
        if (Py < 58) Py++;
        DrawPlayerF();
        break;
    case 'a':
        if (Px > 1) Px--;
        DrawPlayerSideLeftWalk();
        break;
    case 'd':
        if (Px < 118) Px++;
        DrawPlayerSideRightWalk();
        break;
    default:
        break;
    }
}
