//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//#include <vector>
//#include <thread>
//#include <chrono>
//
//using namespace std;
//
//// �ܼ� Ŀ�� ��ġ �̵� �Լ�
//void gotoxy(int x, int y) {
//    COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//// �Ѿ� Ŭ���� ����
//class Bullet {
//public:
//    int x, y;
//    int dx, dy;
//
//    Bullet(int startX, int startY, int dirX, int dirY) : x(startX), y(startY), dx(dirX), dy(dirY) {}
//
//    void move() {
//        gotoxy(x, y);
//        cout << " "; // ���� ��ġ�� �Ѿ� �����
//        x += dx;
//        y += dy;
//        if (x >= 0 && x < 80 && y >= 0 && y < 25) { // ȭ�� ���� �������� �ʾҴٸ� ���
//            gotoxy(x, y);
//            cout << "-";
//        }
//    }
//
//    bool isOutOfBounds() const {
//        return x < 0 || x >= 80 || y < 0 || y >= 25; // ȭ�� �ۿ� ������ true
//    }
//};
//
//// ���� Ŭ���� ����
//class Monster {
//public:
//    int x, y, health;
//    int moveCounter; // ���Ͱ� �����̴� �ӵ��� �����ϱ� ���� ī����
//
//    Monster(int startX, int startY) : x(startX), y(startY), health(20), moveCounter(0) {}
//
//    void move(int targetX, int targetY) {
//        if (moveCounter == 0) { // 4�� �� 1���� �̵�
//            gotoxy(x, y);
//            cout << " "; // ���� ��ġ�� ���� �����
//
//            if (x < targetX) x++;
//            else if (x > targetX) x--;
//
//            if (y < targetY) y++;
//            else if (y > targetY) y--;
//
//            gotoxy(x, y);
//            cout << "M"; // ���ο� ��ġ�� ���� ���
//        }
//        moveCounter = (moveCounter + 1) % 8; // 4�� �� 1���� �̵��ϰ� ��
//    }
//
//    bool isHit(int bulletX, int bulletY) const {
//        return x == bulletX && y == bulletY; // �Ѿ˰� ���Ͱ� ���� ��ġ�� ���� ��
//    }
//
//    bool isDead() const {
//        return health <= 0; // ü���� 0 �����̸� ���� ���
//    }
//};
//
//int main() {
//    int x = 10, y = 10; // �÷��̾� �ʱ� ��ġ
//    int dx = 1, dy = 0; // �ʱ� ���� (������)
//    char ch;
//    vector<Bullet> bullets; // �߻�� �Ѿ��� ������ ����
//    Monster monster(40, 12); // ���� �ʱ� ��ġ
//
//    gotoxy(x, y);
//    cout << "@"; // �ʱ� ĳ���� ���
//
//    while (true) {
//        if (_kbhit()) { // Ű �Է��� ���� ���� ����
//            ch = _getch(); // Ű �Է� �ޱ�
//
//            // ĳ���� �̵� �� ���� ����
//            gotoxy(x, y);
//            cout << " "; // ���� ��ġ�� ĳ���� �����
//
//            if (ch == 'w') {
//                y--;
//                dx = 0; dy = -1; // ���� �ٶ󺸱�
//            }
//            else if (ch == 's') {
//                y++;
//                dx = 0; dy = 1; // �Ʒ��� �ٶ󺸱�
//            }
//            else if (ch == 'a') {
//                x--;
//                dx = -1; dy = 0; // ���� �ٶ󺸱�
//            }
//            else if (ch == 'd') {
//                x++;
//                dx = 1; dy = 0; // ������ �ٶ󺸱�
//            }
//            else if (ch == ' ') {
//                bullets.emplace_back(x + dx, y + dy, dx, dy); // �ٶ󺸴� �������� �Ѿ� �߻�
//            }
//            else if (ch == 27) break; // ESC Ű�� ������ ����
//
//            gotoxy(x, y);
//            cout << "@"; // ���ο� ��ġ�� ĳ���� ���
//        }
//
//        // �Ѿ� �̵� �� ���Ϳ��� �浹 �˻�
//        for (auto it = bullets.begin(); it != bullets.end();) {
//            it->move();
//            if (it->isOutOfBounds()) {
//                it = bullets.erase(it); // ȭ�� ������ ���� �Ѿ� ����
//            }
//            else if (monster.isHit(it->x, it->y)) {
//                monster.health -= 1; // ���Ͱ� �Ѿ˿� ������ ü�� ����
//                gotoxy(monster.x, monster.y);
//                cout << " "; // ���� ���� �����
//                it = bullets.erase(it); // �Ѿ˵� ����
//            }
//            else {
//                ++it;
//            }
//        }
//
//        // ���� �̵� �� �÷��̾���� �浹 �˻�
//        if (!monster.isDead()) {
//            monster.move(x, y);
//            if (monster.x == x && monster.y == y) {
//                gotoxy(0, 0);
//                cout << "You died!"; // �÷��̾ ���Ϳ� ������ ���� ����
//                break;
//            }
//        }
//        else {
//            gotoxy(0, 0);
//            cout << "You win!"; // ���Ͱ� ������ �¸�
//            break;
//        }
//
//        this_thread::sleep_for(chrono::milliseconds(100)); // ������ �ӵ� ����
//    }
//
//    return 0;
//}
#include "Player.h"

int main() {
    Player player("Hero", 10, 5, 3, 2, 1, 0, 0);

  

    return 0;
}
