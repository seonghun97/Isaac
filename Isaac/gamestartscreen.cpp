//#include <iostream>
//#include <windows.h>
//#include <conio.h>
//#include"Player.h"
//#include"gamestartscreen.h"
//#include "monster.h"
//
//
//int menuDraw();
//void init();
//void titleDraw();
//void infoDraw();
//void gotoxy(int x, int y);
//void gametitle();
//void drawmap();
//void cursor();
//void gamestart();
//
//
//void gametitle()
//{
//    init();
//    while (1)
//    {
//        titleDraw();
//        int menuCode = menuDraw();
//        if (menuCode == 0)
//        {
//            gamestart();
//        }
//        else if (menuCode == 1)
//        {
//            infoDraw();
//        }
//        else if (menuCode == 2)
//        {
//            break;
//        }
//    }
//    return;
//}
//
//void infoDraw()
//{
//    gotoxy(0, 0);
//    std::cout << "\t\t";
//    std::cout << "           [���۹�]" << std::endl << std::endl;
//    std::cout << "                      �� �� : w ,a , s, d " << std::endl << std::endl;
//    std::cout << "                      �� �� : �����̽���" << std::endl << std::endl;
//    std::cout << "                      �����̽��ٸ� ������ ���� ȭ������ �̵��մϴ� " << std::endl << std::endl;
//    std::cout << "                      ������ : �ڽ��� ";
//
//    while (1)
//    {
//        char ch = _getch();
//        if (ch == ' ')
//        {
//            break;
//        }
//    }
//}
//
//int menuDraw()
//{
//    int x = 25;
//    int y = 10;
//    gotoxy(x - 2, y);
//    std::cout << "�� ���ӽ���";
//    gotoxy(x, y + 1);
//    std::cout << "��������";
//    gotoxy(x, y + 2);
//    std::cout << " ����";
//
//    while (1)
//    {
//        char ch = _getch();
//        if (ch == 'w' && y > 10)
//        {
//            gotoxy(x - 2, y);
//            std::cout << " ";
//            gotoxy(x - 2, --y);
//            std::cout << "��";
//        }
//        else if (ch == 's' && y < 12)
//        {
//            gotoxy(x - 2, y);
//            std::cout << " ";
//            gotoxy(x - 2, ++y);
//            std::cout << "��";
//        }
//        else if (ch == ' ')
//        {
//            return y - 10;
//        }
//    }
//}
//
//void init()
//{
//    system("mode con cols=120 lines=60");
//    system("title ���� ����");
//
//    CONSOLE_CURSOR_INFO cursorInfo;
//    cursorInfo.dwSize = 1;
//    cursorInfo.bVisible = FALSE;
//    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
//}
//
//void titleDraw()
//{
//    gotoxy(0, 0);
//    std::cout << "��--------------------------------------------------------��" << std::endl;
//    std::cout << "|             @              @      @@@@@    @           |" << std::endl;
//    std::cout << "|      @@@    @       @@@    @       @@      @@          |" << std::endl;
//    std::cout << "|     @   @   @@@    @   @   @      @@ @@    @           |" << std::endl;
//    std::cout << "|      @@@    @       @@@    @           @@@@@           |" << std::endl;
//    std::cout << "|             @              @               @           |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "��--------------------------------------------------------��" << std::endl;
//}
//
//
//
//
//const int monsterWidth = 15;
//const int monsterHeight = 17;
//
//void gamestart()
//{
//    Player player("�÷��̾�", 6, 10, 5, 1, 1, 50, 43);
//    Monster monster("������", 80, 1);
//    char lastKey = 's';
//
//
//    int monsterX = 48;
//    int monsterY = 2;
//    drawmap();
//
//    while (true)
//    {
//        if (player.GetHp() <= 0)
//        {
//            std::cout << "�÷��̾� ���" << std::endl;
//            break;
//        }
//        else if (monster.GetHp() <= 0)
//        {
//            std::cout << monster.GetName() << " ���" << std::endl;
//            break;
//        }
//
//        gotoxy(0, 0);
//        cursor();
//
//        player.UpdateInvincibility();
//
//        // monster.moveTowardsPlayer(player.GetPlayerCoorX(), player.GetPlayerCoorY());
//
//        monster.drawMonster(monster.GetMx(), monster.GetMy());
//
//        if (player.CollidingWithMonster(monster))
//        {
//            player.TakeDamage(monster.GetDamage());
//        }
//
//        player.DrawHearts();
//
//        player.UpdateBullets(monster);
//
//        switch (lastKey)
//        {
//        case 'w':
//            player.DrawPlayerB();
//            break;
//        case 's':
//            player.DrawPlayerF();
//            break;
//        case 'a':
//            player.DrawPlayerSideLeft();
//            break;
//        case 'd':
//            player.DrawPlayerSideRight();
//            break;
//        default:
//            player.DrawPlayerF();
//            break;
//        }
//
//        // Ű �Է� ó��
//        if (_kbhit())
//        {
//            char ch = _getch();
//            player.PlayerMove(ch);
//
//            if (ch == 27)
//            {
//                break;
//            }
//            if (ch != ' ')
//            {
//                lastKey = ch;
//            }
//            if (ch == ' ')
//            {
//                player.Attack();
//            }
//        }
//
//        Sleep(10);
//    }
//}
//void gotoxy(int x, int y)
//{
//    COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//void cursor() {
//    CONSOLE_CURSOR_INFO cursorInfo;
//    cursorInfo.dwSize = 1;
//    cursorInfo.bVisible = FALSE;
//    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
//}
//
//int main()
//{
//    gametitle();
//}
//
//
//#pragma region �ʹ�
///*
//#include <iostream>
//#include <stdio.h>
//#include <windows.h>
//#include <conio.h>
//
//
//#define UP 0
//#define DOWN 1
//#define SUBMIT 2
//
//int keyControl();
//int menuDraw();
//void init();
//void titleDraw();
//void infoDraw();
//void gotoxy(int x, int y);
//
//int main()
//{
//    init();
//    while (1)
//    {
//        titleDraw();
//        int menuCode = menuDraw();
//        if (menuCode == 0)
//        {
//            //���ӽ���
//        }
//        else if (menuCode == 1)
//        {
//            infoDraw();
//        }
//        else if (menuCode == 2)
//        {
//            return 0;
//        }
//        system("cls");
//   }
//    return 0;
//}
//
//void infoDraw()
//{
//    system("cls");
//    std::cout << "\t\t";
//    std::cout << "           [���۹�]" << std::endl << std::endl;
//    std::cout << "                      �� �� : w ,a , s, d " << std::endl << std::endl;
//    std::cout << "                      �� �� : �����̽���" << std::endl << std::endl;
//    std::cout << "                      �����̽��ٸ� ������ ���� ȭ������ �̵��մϴ� " << std::endl << std::endl;
//    std::cout << "                      ������ : �ڽ��� ";
//    while (1) {
//        if (keyControl() == SUBMIT)
//        {
//            break;
//        }
//    }
//}
//
//int keyControl()
//{
//    char ch = _getch();
//
//    if (ch == 'w')
//    {
//        return UP;
//    }
//    else if (ch == 's')
//    {
//        return DOWN;
//    }
//    else if (ch == ' ')
//    {
//        return SUBMIT;
//    }
//    return -1; // �߸��� �Է�
//}
//
//int menuDraw()
//{
//    int x = 25;
//    int y = 10;
//    gotoxy(x - 2, y);
//    std::cout << "�� ���ӽ���";
//    gotoxy(x, y + 1);
//    std::cout << "��������";
//    gotoxy(x, y + 2);
//    std::cout << " �� ��";
//
//    while (1)
//    {
//        int n = keyControl();
//        switch (n)
//        {
//        case UP:
//        {
//            if (y > 10)
//            {
//                gotoxy(x - 2, y);
//                std::cout << " ";
//                gotoxy(x - 2, --y);
//                std::cout << "��";
//            }
//            break;
//        }
//        case DOWN:
//        {
//            if (y < 12)
//            {
//                gotoxy(x - 2, y);
//                std::cout << " ";
//                gotoxy(x - 2, ++y);
//                std::cout << "��";
//            }
//            break;
//        }
//        case SUBMIT:
//        {
//            return y - 10;
//        }
//        }
//    }
//}
//
//void init()
//{
//    system("mode con cols=120 lines=60");
//    system("title ���� ����");
//}
//
//void titleDraw()
//{
//    std::cout << "��--------------------------------------------------------��" << std::endl;
//    std::cout << "|             ��              ��      ������    ��           |" << std::endl;
//    std::cout << "|      ����    ��       ����    ��        ���     ���          |" << std::endl;
//    std::cout << "|     ��   ��   ����    ��   ��   ��      ���  ���   ��           |" << std::endl;
//    std::cout << "|      ����    ��       ����    ��          �������           |" << std::endl;
//    std::cout << "|             ��              ��               ��           |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "|                                                        |" << std::endl;
//    std::cout << "��--------------------------------------------------------��" << std::endl;
//}
//
//void gotoxy(int x, int y)
//{
//    COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//*/
//#pragma endregion