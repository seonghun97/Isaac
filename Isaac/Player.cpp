#include "Player.h" 
#include "Bullet.h"
#include "monster.h"
Player::Player(std::string name, int Hp, int Damage, int Range, int AtkSpeed, int PlayerSpeed, int Px, int Py)
    : name(name), Hp(Hp), Damage(Damage), Range(Range), AtkSpeed(AtkSpeed), PlayerSpeed(PlayerSpeed), Px(Px), Py(Py), dx(0) ,dy(1)
{
}
void Player::UpdateBullets(Monster& monster)
{
    for (auto it = bullets.begin(); it != bullets.end();)
    {
        it->move();

        if (monster.isHit(*it))
        {
            monster.TakeDamage(this->Damage);
            it = bullets.erase(it);
            continue;
        }
        else if (!it->isActive())
        {
            it = bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }
}



void Player::TakeDamage(int damage) 
{
    if (!invincible) 
    {
        Hp -= damage;
        if (Hp <= 0)
        {
            std::cout << name << " die  패배"  << std::endl;
            Hp = 0;
        }
        else 
        {
            // 무적 상태 활성화
            invincible = true;
            invincibleEndTime = std::chrono::steady_clock::now() + std::chrono::seconds(2); // 1초 무적
        }
        DrawHearts();
    }
}
void Player::DrawHearts() const 
{
    COORD coord;
    coord.X = 0;
    coord.Y = 53;

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
void Player::gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Player::Attack()
{
        Bullet newBullet((Px + 5) + dx, (Py + 2) + dy, dx, dy);
        bullets.push_back(newBullet);
     
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
        "   0000   ",
        "  0    0  ",
        " 0 1  1 0 ",
        "  0    0  ",
        "   0000   ",
        "  0 00 0  ",
        "   0  0   ",
        "   0  0   ",
    };

    for (int i = 0; i < height; ++i)
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char& c : Player[i]) 
        {
            if (c == '0') 
            {
                TextColor(8, 8); 
                std::cout << "■";
            }
            else if (c == '1') 
            {
                TextColor(15, 15);
                std::cout << "■";
            }
            else
            {
                TextColor(15, 0);
                std::cout << " ";
            }
        }
    }

    TextColor(15, 0); 
}

void Player::DrawPlayerB() const
{
    const int height = 8;

    std::string Playerb[height] = 
    {
        "   0000   ",
        "  0    0  ",
        " 0      0 ",
        "  0    0  ",
        "   0000   ",
        "  0 00 0  ",
        "   0  0   ",
        "   0  0   ",
    };

    for (int i = 0; i < height; ++i)
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char& c : Playerb[i]) 
        {
            if (c == '0')
            {
                TextColor(8, 8); 
                std::cout << "■";
            }
            else
            {
                TextColor(15, 0);
                std::cout << " ";
            }
        }
    }

    TextColor(15, 0);  
}

void Player::DrawPlayerSideLeft() const 
{
    const int height = 8;

    std::string Players[height] =
    {
        "   0000   ",
        "  0    0  ",
        " 0 1    0 ",
        "  0    0  ",
        "   0000   ",
        "    00    ",
        "    00    ",
        "    00    ",
    };

    for (int i = 0; i < height; ++i)
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char& c : Players[i])
        {
            if (c == '0')
            {
                TextColor(8, 8); 
                std::cout << "■";
            }
            else if (c == '1') 
            {
                TextColor(15, 15);
                std::cout << "■";
            }
            else
            {
                TextColor(15, 0);
                std::cout << " ";
            }
        }
    }

    TextColor(15, 0);
}

void Player::DrawPlayerSideRight() const
{
    const int height = 8;

    std::string Players[height] =
    {
        "   0000   ",
        "  0    0  ",
        " 0    1 0 ",
        "  0    0  ",
        "   0000   ",
        "    00    ",
        "    00    ",
        "    00    ",
    };             

    for (int i = 0; i < height; ++i)
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char& c : Players[i]) 
        {
            if (c == '0')
            {
                TextColor(8, 8);  
                std::cout << "■";
            }
            else if (c == '1')
            {
                TextColor(15, 15);
                std::cout << "■";
            }
            else 
            {
                TextColor(15, 0); 
                std::cout << " ";
            }
        }
    }

    TextColor(15, 0);  
}

void Player::DrawPlayerSideLeftWalk() const 
{
    const int height = 8;

    std::string Player[height] = 
    {              
        "   0000   ",
        "  0    0  ",
        " 0 1    0 ",
        "  0    0  ",
        "   0000   ",
        "    00    ",
        "   0 0    ",
        "  0  0    ",
    };

    for (int i = 0; i < height; ++i)
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char& c : Player[i])
        {
            if (c == '0') 
            {
                TextColor(8, 8);  
                std::cout << "■";
            }
            else if (c == '1') 
            {
                TextColor(15, 15);
                std::cout << "■";
            }
            else 
            {
                TextColor(15, 0); 
                std::cout << " ";
            }
        }
    }

    TextColor(15, 0); 
}

void Player::DrawPlayerSideRightWalk() const 
{
    const int height = 8;

    std::string Player[height] =
    {
        "   0000   ",
        "  0    0  ",
        " 0    1 0 ",
        "  0    0  ",
        "   0000   ",
        "    00    ",
        "    0 0   ",
        "    0  0  ",
    };

    for (int i = 0; i < height; ++i) 
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char& c : Player[i]) 
        {
            if (c == '0')
            {
                TextColor(8, 8); 
                std::cout << "■";
            }
            else if (c == '1')
            {
                TextColor(15, 15);
                std::cout << "■";
            }
            else 
            {
                TextColor(15, 0);
                std::cout << " ";
            }
        }
    }

    TextColor(15, 0);
}

void Player::DrawPlayerDeath() const
{
    const int height = 8;

    std::string Player[height] =
    {
        "  ",
        "  ",
        "  ",
        "    ",
        "   ",
        "    ",
        "   ",
        "   ",
    };

    for (int i = 0; i < height; ++i)
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char& c : Player[i])
        {
            if (c == '0')
            {
                TextColor(8, 8);
                std::cout << "■";
            }
            else if (c == '1')
            {
                TextColor(15, 15);
                std::cout << "■";
            }
            else
            {
                TextColor(15, 0);
                std::cout << " ";
            }
        }
    }

    TextColor(15, 0);

}

bool Player::CollidingWithMonster(const Monster& monster) const 
{
    
    int playerLeft = Px+1;
    int playerRight = Px + 5; 
    int playerTop = Py+1;
    int playerBottom = Py + 4; 

    int monsterLeft = monster.GetMx();
    int monsterRight = monster.GetMx() + 17; 
    int monsterTop = monster.GetMy();
    int monsterBottom = monster.GetMy() + 15;

    bool isColliding = playerRight >= monsterLeft &&
        playerLeft <= monsterRight &&
        playerBottom >= monsterTop &&
        playerTop <= monsterBottom;

    return isColliding;
}

void Player::UpdateInvincibility()
{
    if (invincible)
    {
        auto now = std::chrono::steady_clock::now();
        if (now >= invincibleEndTime)
        {
            invincible = false; // 무적 상태 해제
        }
    }
}


void Player::PlayerMove(char direction) 
{
    
    for (int i = 0; i < 8; ++i)
    {
        COORD coord = { (SHORT)Px, (SHORT)(Py + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "                "; 
    }
    switch (direction)
    {
    case 'w':
        if (Py > 1) Py--;
        dx = 0; dy = -1; // 위쪽 방향
        DrawPlayerB();
        break;
    case 's':
        if (Py < 44) Py++;
        dx = 0; dy = 1; // 아래쪽 방향
        DrawPlayerF();
        break;
    case 'a':
        if (Px > 1) Px--;
        dx = -1; dy = 0; // 왼쪽 방향
        DrawPlayerSideLeftWalk();
        break;
    case 'd':
        if (Px < 93) Px++;
        dx = 1; dy = 0; // 오른쪽 방향
        DrawPlayerSideRightWalk();
        break;
    default:
        break;
    }
}

