#include <iostream>
#include <string>
#include <windows.h>  // Windows 콘솔 색상 설정에 필요

void TextColor(int font, int backGround) {
    int Color = font + backGround * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void drawItemPoly() {
    const int height = 7;
    const int width = 15;

    std::string poly[height] = {
        "      0000      ",
        "     011110     ",
        "   0111122110   " ,
        "  011221112210  ",
        " 01111111111110 ",
        "  000222222000  ",
        "     000000     ",
       
      
    };

    for (int i = 0; i < height; ++i) {
        std::cout << std::string((120 - width) / 2, ' ');  // 중앙 정렬

        for (char& c : poly[i]) {
            if (c == '0') {
                TextColor(0, 0);  // 회색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '1') {
                TextColor(12, 12);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '2') {
                TextColor(6, 6);  // 연파랑 전경, 검은색 배경
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

void drawBandage() {
    const int height = 8;
    const int width = 15;

    std::string Bandage[height] = {
        " 11111111111111111  ",
        " 1               1 ",
        " 1       2       1 ",
        " 1      222      1 ",
        " 1       2       1   ",
        " 1               1 ",
        " 11111111111111111 ",
        " ",
                   
     
    };

    for (int i = 0; i < height; ++i) {
        std::cout << std::string((120 - width) / 2, ' ');  // 중앙 정렬

        for (char& c : Bandage[i]) {
            if (c == '0') {
                TextColor(0, 0); 
                std::cout << "■";
            }
            else if (c == '1') {
                TextColor(6, 6);  
                std::cout << "■";
            }
            else if (c == '2') {
                TextColor(12, 12);
                std::cout << "■";
            }
            else if (c == '3') {
                TextColor(8, 8);
                std::cout << "■";
            }
            else {
                TextColor(15, 0);
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // 마지막에 콘솔 색상 리셋
    TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
}

void DrawRange() {
    const int height = 11;
    const int width = 8;

    std::string Range[height] = {
        "    0    ",
        "   0 0   ",
        "  0   0  ",
        "  00000  ",
        "    0    ",
        "    0    ",
        "    0       ",
        "    0    ",
        "    0    ",
        "  1 0 1   ",
        " 1  0  1 ",

    };

    for (int i = 0; i < height; ++i) {
        std::cout << std::string((120 - width) / 2, ' ');  // 중앙 정렬

        for (char& c : Range[i]) {
            if (c == '0') {
                TextColor(8, 8);  // 회색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '1') {
                TextColor(15, 15);  // 흰색 전경, 검은색 배경
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

void DrawSpeed() {
    const int height = 11;
    const int width = 8;

    std::string Speed[height] = {
        " 1111111      0000    ",
        "             0    0   ",
        " 1111111      0000   ",
        "       00000000       ",
        " 1111111     00       ",
        "            00         ",
        "   1111111 00        ",
        "           00000       ",
        "  1111111  0    0      ",
        "       0000      0     ",
        "                 00    ",

    };

    for (int i = 0; i < height; ++i) {
        std::cout << std::string((120 - width) / 2, ' ');  // 중앙 정렬

        for (char& c : Speed[i]) {
            if (c == '0') {
                TextColor(11,11);  // 회색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '1') {
                TextColor(9, 9);  // 흰색 전경, 검은색 배경
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
    drawItemPoly();
    drawBandage();
    DrawRange();
    std::cout << std::endl;
    DrawSpeed();
    return 0;
}
