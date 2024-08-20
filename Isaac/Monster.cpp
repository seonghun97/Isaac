#pragma once

#include "monster.h"


// �ܼ� �ؽ�Ʈ ���� ���� �Լ�
void TextColor(int foreground, int background) {
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ���͸� �׸��� �Լ�
//void drawMonster(int monsterX, int monsterY) {
//    const int height = 8; // ������ ���� ����
//    const int width = 15; // ������ �ִ� ��
//
//    std::string monster[height] = {
//        "     11111    ",
//        "    1111111   ",
//        "   122212221  ",
//        "  11211121111  ",
//        "  11222122211  ",
//        "  11111111111  ",
//        "  11111111111  ",
//        "  11  111  11  "
//    };
//
//    for (int i = 0; i < height; ++i) {
//        COORD coord;
//        coord.X = monsterX;  // X ��ġ ����
//        coord.Y = monsterY + i;  // Y ��ġ ����
//        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//
//        for (char& c : monster[i]) {
//            if (c == '1') {
//                TextColor(6, 6);  // ����� ����, ����� ���
//                std::cout << "��";
//            }
//            else if (c == '2') {
//                TextColor(15, 15);  // ��� ����, ��� ���
//                std::cout << "��";
//            }
//            else {
//                TextColor(0, 0);  // �⺻ ������ ���
//                std::cout << " ";
//            }
//        }
//    }
//    TextColor(15, 0);  // �⺻ ��� ����, ������ ������� ����
//}


Monster::Monster(std::string Mname, int hp, int Damage)
    :Mname(Mname), hp(hp), Damage(Damage),Mx(48),My(0),Mdx(0),Mdy(0)
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
                TextColor(8, 8);  // ȸ�� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '1') {
                TextColor(15, 15);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '2') {
                TextColor(11, 11);  // ���Ķ� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '3') {
                TextColor(15, 15);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(15, 0);  // �⺻ ��� ����, ������ ���
                std::cout << " ";
            }
        }
    }

    // �������� �ܼ� ���� ����
    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}

void Monster::Attack()
{
}


bool Monster::isHit(const Bullet& bullet) const
{
    const int width = 17;  // ������ �ʺ�
    const int height = 15;  // ������ ����

    int bulletX = bullet.GetX();
    int bulletY = bullet.GetY();

    
    return (bulletX >= Mx && bulletX < Mx + width && bulletY >= My && bulletY < My + height);
}




void Monster::TakeDamage(int Damage)
{
    hp -= Damage;
    if (hp <= 0)
    {
        std::cout << Mname << "�� �׾���!" << std::endl;
    }
}
//void Monster::moveTowardsPlayer(int playerX, int playerY) {
//    if (Mx < playerX) {
//        Mx++;  // ���Ͱ� �÷��̾��� ���ʿ� �ִٸ� ���������� �̵�
//    }
//    else if (Mx > playerX) {
//        Mx--;  // ���Ͱ� �÷��̾��� �����ʿ� �ִٸ� �������� �̵�
//    }
//
//    if (My < playerY) {
//        My++;  // ���Ͱ� �÷��̾��� ���ʿ� �ִٸ� �Ʒ��� �̵�
//    }
//    else if (My > playerY) {
//        My--;  // ���Ͱ� �÷��̾��� �Ʒ��ʿ� �ִٸ� ���� �̵�
//    }
//}



