#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Player.h"
#include "monster.h"

int menuDraw();
void init();
void titleDraw();
void infoDraw();
void gotoxy(int x, int y);
void gametitle();
void drawmap();
void cursor();
void gamestart();

// ���� Ÿ��Ʋ ȭ���� �����ϴ� �Լ�
void gametitle()
{
    init();
    while (true)
    {
        titleDraw();
        int menuCode = menuDraw();
        if (menuCode == 0)
        {
            gamestart();
        }
        else if (menuCode == 1)
        {
            infoDraw();
        }
        else if (menuCode == 2)
        {
            break;
        }
    }
    return;
}

// ���� ���� ȭ���� ����ϴ� �Լ�
void infoDraw()
{
    system("cls"); // ȭ���� ����
    gotoxy(0, 0);
    std::cout << "\t\t";
    std::cout << "           [���۹�]" << std::endl << std::endl;
    std::cout << "                      �� �� : w ,a , s, d " << std::endl << std::endl;
    std::cout << "                      �� �� : �����̽���" << std::endl << std::endl;
    std::cout << "                      �����̽��ٸ� ������ ���� ȭ������ �̵��մϴ� " << std::endl << std::endl;
    std::cout << "                      ������ : �ڽ��� ";

    while (true)
    {
        char ch = _getch();
        if (ch == ' ')
        {
            break;
        }
    }
    system("cls"); // ȭ���� ����� ���� ȭ������ ���ư�
}

// ���� �޴��� �׸��� �Լ�
int menuDraw()
{
    int x = 25;
    int y = 10;
    gotoxy(x - 2, y);
    std::cout << "�� ���ӽ���";
    gotoxy(x, y + 1);
    std::cout << "��������";
    gotoxy(x, y + 2);
    std::cout << " ����";

    while (true)
    {
        char ch = _getch();
        if (ch == 'w' && y > 10)
        {
            gotoxy(x - 2, y);
            std::cout << " ";
            gotoxy(x - 2, --y);
            std::cout << "��";
        }
        else if (ch == 's' && y < 12)
        {
            gotoxy(x - 2, y);
            std::cout << " ";
            gotoxy(x - 2, ++y);
            std::cout << "��";
        }
        else if (ch == ' ')
        {
            return y - 10;
        }
    }
}

// �ʱ�ȭ �Լ�
void init()
{
    system("mode con cols=120 lines=60");
    system("title ���� ����");

    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// Ÿ��Ʋ ȭ���� �׸��� �Լ�
void titleDraw()
{
    system("cls"); // Ÿ��Ʋ ȭ���� �׸��� ���� ȭ���� ����
    gotoxy(0, 0);
    std::cout << "��--------------------------------------------------------��" << std::endl;
    std::cout << "|             @              @      @@@@@    @           |" << std::endl;
    std::cout << "|      @@@    @       @@@    @       @@      @@          |" << std::endl;
    std::cout << "|     @   @   @@@    @   @   @      @@ @@    @           |" << std::endl;
    std::cout << "|      @@@    @       @@@    @           @@@@@           |" << std::endl;
    std::cout << "|             @              @               @           |" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    std::cout << "��--------------------------------------------------------��" << std::endl;
}

// ���� ���� �Լ�
void gamestart()
{
    system("cls"); // ���� ���� ���� ȭ���� ����
    Player player("�÷��̾�", 6, 1, 5, 4, 1, 50, 43);
    Monster monster("������", 80, 1, 16);

    char lastKey = 's';

    int monsterX = 48;
    int monsterY = 2;
    drawmap();

    while (true)
    {
        if (player.GetHp() <= 0)
        {
            break;
        }
        else if (monster.GetHp() <= 0)
        {
            break;
        }

        gotoxy(0, 0);
        cursor();

        player.UpdateInvincibility();

        monster.moveTowardsPlayer(player.GetPlayerCoorX(), player.GetPlayerCoorY());

        monster.drawMonster(monster.GetMx(), monster.GetMy());

        if (player.CollidingWithMonster(monster))
        {
            player.TakeDamage(monster.GetDamage());
        }

        player.DrawHearts();
        monster.monsterHpBar();
        player.UpdateBullets(monster);

        switch (lastKey)
        {
        case 'w':
            player.DrawPlayerB();
            break;
        case 's':
            player.DrawPlayerF();
            break;
        case 'a':
            player.DrawPlayerSideLeft();
            break;
        case 'd':
            player.DrawPlayerSideRight();
            break;
        default:
            player.DrawPlayerF();
            break;
        }

        // Ű �Է� ó��
        if (_kbhit())
        {
            char ch = _getch();
            player.PlayerMove(ch);

            if (ch == 27)
            {
                break;
            }
            if (ch != ' ')
            {
                lastKey = ch;
            }
            if (ch == ' ')
            {
                player.Attack();
            }
        }
    }
}
// gotoxy �Լ� ����
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Ŀ�� ���� �Լ�
void cursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// ���α׷� ������
int main()
{
    gametitle();
}
