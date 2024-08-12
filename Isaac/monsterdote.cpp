#include <iostream>
#include <string>
#include <windows.h>

void TextColor(int foreground, int background) {
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawMonster() {
    const int height = 8; // �迭�� ���� ����
    const int width = 15; // �ִ� ��

    std::string monster[height] = {
        "     11111    ",
        "    1111111   ",
        "   122212221  ",
        "  11211121111  ",
        "  11222122211  ",
        "  11111111111  ",
        "  11111111111  ",
        "  11  111  11  "
    };

    for (int i = 0; i < height; ++i) {
        std::cout << std::string((120 - width) / 2, ' ');  // �߾� ����

        for (char& c : monster[i]) {
            if (c == '1') {
                TextColor(6, 6);  // ����� ����, ������ ���
                std::cout << "��";
            }
            else if (c == '2') {
                TextColor(15, 15);  // ��� ����, ������ ���
                std::cout << "��";
            }
            else {
                TextColor(0, 0);  // �⺻ ������ ���
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    TextColor(15, 0);  // �⺻ ��� ����, ������ ���
}

int main() {
    drawMonster();
    return 0;
}
