//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//#include <vector>
//#include <thread>
//#include <chrono>
//
//using namespace std;
//
//// 콘솔 커서 위치 이동 함수
//void gotoxy(int x, int y) {
//    COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//// 총알 클래스 정의
//class Bullet {
//public:
//    int x, y;
//    int dx, dy;
//
//    Bullet(int startX, int startY, int dirX, int dirY) : x(startX), y(startY), dx(dirX), dy(dirY) {}
//
//    void move() {
//        gotoxy(x, y);
//        cout << " "; // 이전 위치의 총알 지우기
//        x += dx;
//        y += dy;
//        if (x >= 0 && x < 80 && y >= 0 && y < 25) { // 화면 끝에 도달하지 않았다면 출력
//            gotoxy(x, y);
//            cout << "-";
//        }
//    }
//
//    bool isOutOfBounds() const {
//        return x < 0 || x >= 80 || y < 0 || y >= 25; // 화면 밖에 나가면 true
//    }
//};
//
//// 몬스터 클래스 정의
//class Monster {
//public:
//    int x, y, health;
//    int moveCounter; // 몬스터가 움직이는 속도를 조절하기 위한 카운터
//
//    Monster(int startX, int startY) : x(startX), y(startY), health(20), moveCounter(0) {}
//
//    void move(int targetX, int targetY) {
//        if (moveCounter == 0) { // 4번 중 1번만 이동
//            gotoxy(x, y);
//            cout << " "; // 이전 위치의 몬스터 지우기
//
//            if (x < targetX) x++;
//            else if (x > targetX) x--;
//
//            if (y < targetY) y++;
//            else if (y > targetY) y--;
//
//            gotoxy(x, y);
//            cout << "M"; // 새로운 위치에 몬스터 출력
//        }
//        moveCounter = (moveCounter + 1) % 8; // 4번 중 1번만 이동하게 함
//    }
//
//    bool isHit(int bulletX, int bulletY) const {
//        return x == bulletX && y == bulletY; // 총알과 몬스터가 같은 위치면 맞은 것
//    }
//
//    bool isDead() const {
//        return health <= 0; // 체력이 0 이하이면 몬스터 사망
//    }
//};
//
//int main() {
//    int x = 10, y = 10; // 플레이어 초기 위치
//    int dx = 1, dy = 0; // 초기 방향 (오른쪽)
//    char ch;
//    vector<Bullet> bullets; // 발사된 총알을 저장할 벡터
//    Monster monster(40, 12); // 몬스터 초기 위치
//
//    gotoxy(x, y);
//    cout << "@"; // 초기 캐릭터 출력
//
//    while (true) {
//        if (_kbhit()) { // 키 입력이 있을 때만 실행
//            ch = _getch(); // 키 입력 받기
//
//            // 캐릭터 이동 및 방향 설정
//            gotoxy(x, y);
//            cout << " "; // 기존 위치의 캐릭터 지우기
//
//            if (ch == 'w') {
//                y--;
//                dx = 0; dy = -1; // 위쪽 바라보기
//            }
//            else if (ch == 's') {
//                y++;
//                dx = 0; dy = 1; // 아래쪽 바라보기
//            }
//            else if (ch == 'a') {
//                x--;
//                dx = -1; dy = 0; // 왼쪽 바라보기
//            }
//            else if (ch == 'd') {
//                x++;
//                dx = 1; dy = 0; // 오른쪽 바라보기
//            }
//            else if (ch == ' ') {
//                bullets.emplace_back(x + dx, y + dy, dx, dy); // 바라보는 방향으로 총알 발사
//            }
//            else if (ch == 27) break; // ESC 키를 누르면 종료
//
//            gotoxy(x, y);
//            cout << "@"; // 새로운 위치에 캐릭터 출력
//        }
//
//        // 총알 이동 및 몬스터와의 충돌 검사
//        for (auto it = bullets.begin(); it != bullets.end();) {
//            it->move();
//            if (it->isOutOfBounds()) {
//                it = bullets.erase(it); // 화면 밖으로 나간 총알 제거
//            }
//            else if (monster.isHit(it->x, it->y)) {
//                monster.health -= 1; // 몬스터가 총알에 맞으면 체력 감소
//                gotoxy(monster.x, monster.y);
//                cout << " "; // 맞은 몬스터 지우기
//                it = bullets.erase(it); // 총알도 제거
//            }
//            else {
//                ++it;
//            }
//        }
//
//        // 몬스터 이동 및 플레이어와의 충돌 검사
//        if (!monster.isDead()) {
//            monster.move(x, y);
//            if (monster.x == x && monster.y == y) {
//                gotoxy(0, 0);
//                cout << "You died!"; // 플레이어가 몬스터에 닿으면 게임 종료
//                break;
//            }
//        }
//        else {
//            gotoxy(0, 0);
//            cout << "You win!"; // 몬스터가 죽으면 승리
//            break;
//        }
//
//        this_thread::sleep_for(chrono::milliseconds(100)); // 움직임 속도 조절
//    }
//
//    return 0;
//}
#include "Player.h"

int main() {
    Player player("Hero", 10, 5, 3, 2, 1, 0, 0);

  

    return 0;
}
