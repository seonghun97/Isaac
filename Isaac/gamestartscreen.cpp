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

// 게임 타이틀 화면을 관리하는 함수
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

// 게임 정보 화면을 출력하는 함수
void infoDraw()
{
    system("cls"); // 화면을 지움
    gotoxy(0, 0);
    std::cout << "\t\t";
    std::cout << "           [조작법]" << std::endl << std::endl;
    std::cout << "                      이 동 : w ,a , s, d " << std::endl << std::endl;
    std::cout << "                      선 택 : 스페이스바" << std::endl << std::endl;
    std::cout << "                      스페이스바를 누르면 메인 화면으로 이동합니다 " << std::endl << std::endl;
    std::cout << "                      제작자 : 박승훈 ";

    while (true)
    {
        char ch = _getch();
        if (ch == ' ')
        {
            break;
        }
    }
    system("cls"); // 화면을 지우고 메인 화면으로 돌아감
}

// 메인 메뉴를 그리는 함수
int menuDraw()
{
    int x = 25;
    int y = 10;
    gotoxy(x - 2, y);
    std::cout << "▶ 게임시작";
    gotoxy(x, y + 1);
    std::cout << "게임정보";
    gotoxy(x, y + 2);
    std::cout << " 종료";

    while (true)
    {
        char ch = _getch();
        if (ch == 'w' && y > 10)
        {
            gotoxy(x - 2, y);
            std::cout << " ";
            gotoxy(x - 2, --y);
            std::cout << "▶";
        }
        else if (ch == 's' && y < 12)
        {
            gotoxy(x - 2, y);
            std::cout << " ";
            gotoxy(x - 2, ++y);
            std::cout << "▶";
        }
        else if (ch == ' ')
        {
            return y - 10;
        }
    }
}

// 초기화 함수
void init()
{
    system("mode con cols=120 lines=60");
    system("title 게임 제목");

    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// 타이틀 화면을 그리는 함수
void titleDraw()
{
    system("cls"); // 타이틀 화면을 그리기 전에 화면을 지움
    gotoxy(0, 0);
    std::cout << "┌--------------------------------------------------------┐" << std::endl;
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
    std::cout << "└--------------------------------------------------------┘" << std::endl;
}

// 게임 시작 함수
void gamestart()
{
    system("cls"); // 게임 시작 전에 화면을 지움
    Player player("플레이어", 6, 1, 5, 4, 1, 50, 43);
    Monster monster("아이작", 80, 1, 16);

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

        // 키 입력 처리
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
// gotoxy 함수 정의
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 커서 숨김 함수
void cursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// 프로그램 시작점
int main()
{
    gametitle();
}
