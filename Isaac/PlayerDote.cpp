#include <iostream>
#include <string>
#include <windows.h>  // Windows �ܼ� ���� ������ �ʿ�

void TextColor(int font, int backGround) {
    int Color = font + backGround * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void DrawPlayerF() {
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
            else if (c == '2') {
                TextColor(11, 11);  // ���Ķ� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '3') {
                TextColor(15, 0);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(15, 0);  // �⺻ ��� ����, ������ ���
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // �������� �ܼ� ���� ����
    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}
void DrawPlayerB() {
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
            else if (c == '1') {
                TextColor(15, 15);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '2') {
                TextColor(11, 11);  // ���Ķ� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '3') {
                TextColor(15, 0);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(15, 0);  // �⺻ ��� ����, ������ ���
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // �������� �ܼ� ���� ����
    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}
void DrawPlayerSideLeft() {
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
            else if (c == '2') {
                TextColor(11, 11);  // ���Ķ� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '3') {
                TextColor(15, 0);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(15, 0);  // �⺻ ��� ����, ������ ���
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // �������� �ܼ� ���� ����
    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}
void DrawPlayerSideRight() {
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
            else if (c == '2') {
                TextColor(11, 11);  // ���Ķ� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '3') {
                TextColor(15, 0);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(15, 0);  // �⺻ ��� ����, ������ ���
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // �������� �ܼ� ���� ����
    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}
void DrawPlayerSideLeftWalk() {
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
            else if (c == '2') {
                TextColor(11, 11);  // ���Ķ� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '3') {
                TextColor(15, 0);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(15, 0);  // �⺻ ��� ����, ������ ���
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // �������� �ܼ� ���� ����
    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}
void DrawPlayerSideRightWalk() {
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
            else if (c == '2') {
                TextColor(11, 11);  // ���Ķ� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '3') {
                TextColor(15, 0);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(15, 0);  // �⺻ ��� ����, ������ ���
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // �������� �ܼ� ���� ����
    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}

int main() {
    DrawPlayerF();
    std::cout << std::endl;
    DrawPlayerB();
    std::cout << std::endl;
    DrawPlayerSideLeft();
    std::cout << std::endl;
    DrawPlayerSideLeftWalk();
    std::cout << std::endl;
    DrawPlayerSideRight();
    std::cout << std::endl;
    DrawPlayerSideRightWalk();
    return 0;
}
