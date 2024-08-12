#include <iostream>
#include <string>
#include <windows.h>  // Windows �ܼ� ���� ������ �ʿ�

void TextColor(int font, int backGround) {
    int Color = font + backGround * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void drawIsaac() {
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
        "      00  00     "
    };

    for (int i = 0; i < height; ++i) {
        std::cout << std::string((120 - width) / 2, ' ');  // �߾� ����

        for (char& c : isaac[i]) {
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
    drawIsaac();
    return 0;
}
