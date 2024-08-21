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