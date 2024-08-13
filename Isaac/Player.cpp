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
        std::cout << "Player " << name << " �׾���!" << std::endl;
    }
    else
    {
        std::cout << "Player " << name << " took " << damage << " damage. Remaining HP: " << Hp << std::endl;
    }
}

void Player::PlayerMove(char direction)
{
    // �̵� ���� ���� �߰�
}

void Player::DisplayHealth() const {
    std::string healthDisplay = "����ü��: ";
    for (int i = 0; i < Hp; ++i) {
        healthDisplay += "��";
    }
    std::cout << healthDisplay << std::endl;
}

void Player::Attack()
{
    // ���� ���� ���� �߰�
}

void Player::TextColor(int font, int backGround) const {
    int Color = font + backGround * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void Player::DrawPlayerF() const {
    const int height = 10;
    const int width = 10;

    std::string Player[height] = {
        "    0000       ",
        "   0    0 ",
        "  0 1  1 0 ",
        "   0    0 ",
        "    0000          ",
        "   0 00 0         ",
        "    0  0    ",
        "    0  0       ",
    };

    for (int i = 0; i < height; ++i) {
        std::cout << std::string((120 - width) / 2, ' ');  // �߾� ����

        for (char& c : Player[i]) {
            if (c == '0') {
                TextColor(8, 8);  // ȸ�� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '1') {
                TextColor(15, 15);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(15, 0);  // �⺻ ��� ����, ������ ���
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}

void Player::DrawPlayerB() const {
    const int height = 10;
    const int width = 10;

    std::string Playerb[height] = {
        "    0000       ",
        "   0    0 ",
        "  0      0 ",
        "   0    0 ",
        "    0000          ",
        "   0 00 0         ",
        "    0  0    ",
        "    0  0       ",
    };

    for (int i = 0; i < height; ++i) {
        std::cout << std::string((120 - width) / 2, ' ');  // �߾� ����

        for (char& c : Playerb[i]) {
            if (c == '0') {
                TextColor(8, 8);  // ȸ�� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(15, 0);  // �⺻ ��� ����, ������ ���
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}

void Player::DrawPlayerSideLeft() const {
    const int height = 10;
    const int width = 10;

    std::string Players[height] = {
        "    0000       ",
        "   0    0 ",
        "  0 1    0 ",
        "   0    0 ",
        "    0000      ",
        "     00             ",
        "     00    ",
        "     00       ",
    };

    for (int i = 0; i < height; ++i) {
        std::cout << std::string((120 - width) / 2, ' ');  // �߾� ����

        for (char& c : Players[i]) {
            if (c == '0') {
                TextColor(8, 8);  // ȸ�� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '1') {
                TextColor(15, 15);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(15, 0);  // �⺻ ��� ����, ������ ���
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}

void Player::DrawPlayerSideRight() const {
    const int height = 10;
    const int width = 10;

    std::string Players[height] = {
        "    0000       ",
        "   0    0 ",
        "  0    1 0 ",
        "   0    0 ",
        "    0000      ",
        "     00             ",
        "     00    ",
        "     00       ",
    };

    for (int i = 0; i < height; ++i) {
        std::cout << std::string((120 - width) / 2, ' ');  // �߾� ����

        for (char& c : Players[i]) {
            if (c == '0') {
                TextColor(8, 8);  // ȸ�� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '1') {
                TextColor(15, 15);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(15, 0);  // �⺻ ��� ����, ������ ���
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}

void Player::DrawPlayerSideLeftWalk() const {
    const int height = 10;
    const int width = 10;

    std::string Player[height] = {
        "    0000       ",
        "   0    0 ",
        "  0 1    0 ",
        "   0    0 ",
        "    0000      ",
        "     00             ",
        "    0 0    ",
        "   0  0       ",
    };

    for (int i = 0; i < height; ++i) {
        std::cout << std::string((120 - width) / 2, ' ');  // �߾� ����

        for (char& c : Player[i]) {
            if (c == '0') {
                TextColor(8, 8);  // ȸ�� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '1') {
                TextColor(15, 15);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(15, 0);  // �⺻ ��� ����, ������ ���
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}

void Player::DrawPlayerSideRightWalk() const {
    const int height = 10;
    const int width = 10;

    std::string Player[height] = {
        "    0000       ",
        "   0    0 ",
        "  0    1 0 ",
        "   0    0 ",
        "    0000      ",
        "     00             ",
        "     0 0   ",
        "     0  0       ",
    };

    for (int i = 0; i < height; ++i) {
        std::cout << std::string((120 - width) / 2, ' ');  // �߾� ����

        for (char& c : Player[i]) {
            if (c == '0') {
                TextColor(8, 8);  // ȸ�� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '1') {
                TextColor(15, 15);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(15, 0);  // �⺻ ��� ����, ������ ���
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}
