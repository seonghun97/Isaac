#include <iostream>
#include <string>
#include <windows.h>  // Windows 콘솔 색상 설정에 필요

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
        std::cout << std::string((120 - width) / 2, ' ');  // 중앙 정렬

        for (char& c : isaac[i]) {
            if (c == '0') {
                TextColor(8, 8);  // 회색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '1') {
                TextColor(15, 15);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '2') {
                TextColor(11, 11);  // 연파랑 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '3') {
                TextColor(15, 0);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else {
                TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // 마지막에 콘솔 색상 리셋
    TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
}

int main() {
    drawIsaac();
    return 0;
}
