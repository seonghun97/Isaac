#pragma once
#include <iostream>
#include <string>
#include <windows.h>

// 콘솔 텍스트 색상 설정 함수
void TextColor(int foreground, int background) {
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 몬스터를 그리는 함수
//void drawMonster(int monsterX, int monsterY) {
//    const int height = 8; // 몬스터의 실제 높이
//    const int width = 15; // 몬스터의 최대 폭
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
//        coord.X = monsterX;  // X 위치 설정
//        coord.Y = monsterY + i;  // Y 위치 설정
//        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//
//        for (char& c : monster[i]) {
//            if (c == '1') {
//                TextColor(6, 6);  // 노란색 전경, 노란색 배경
//                std::cout << "■";
//            }
//            else if (c == '2') {
//                TextColor(15, 15);  // 흰색 전경, 흰색 배경
//                std::cout << "■";
//            }
//            else {
//                TextColor(0, 0);  // 기본 검은색 배경
//                std::cout << " ";
//            }
//        }
//    }
//    TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경으로 리셋
//}
void drawMonster(int monsterX, int monsterY) 
{
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
    
    for (int i = 0; i < height; ++i)
    {
        COORD coord;
        coord.X = 60;  // X 위치 설정
        coord.Y = 5;  // Y 위치 설정
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
    

    for (int i = 0; i < height; ++i) 
    {   
        
        for (char& c : isaac[i]) 
        {
            if (c == '0')
            {
                TextColor(8, 8);  // 회색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '1') 
            {
                TextColor(15, 15);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '2')
            {
                TextColor(11, 11);  // 연파랑 전경, 검은색 배경
                std::cout << "■";
            }
            else if (c == '3') 
            {
                TextColor(15, 0);  // 흰색 전경, 검은색 배경
                std::cout << "■";
            }
            else 
            {
                TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
                std::cout << " ";
            }
        }
        std::cout << std::endl;

    }

    // 마지막에 콘솔 색상 리셋
    TextColor(15, 0);  // 기본 흰색 전경, 검은색 배경
}
