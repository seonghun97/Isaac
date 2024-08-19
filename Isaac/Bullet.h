//#pragma once
//#include <iostream>
//#include <windows.h>
//class Bullet {
//public:
//    int x, y;
//    int dx, dy;
//    bool active; // �Ѿ��� Ȱ��ȭ�� �������� Ȯ���ϴ� �÷���
//
//    Bullet(); // �⺻ ������
//    void init(int startX, int startY, int dirX, int dirY); // �Ѿ� �ʱ�ȭ
//    void move(); // �Ѿ� �̵�
//    bool isOutOfBounds() const; // �Ѿ��� ȭ�� ������ �������� Ȯ��
//};
#pragma once
#include <iostream>
#include <windows.h>

class Bullet {
public:
    // �Ѿ��� ��ġ�� �̵� ������ ��Ÿ���� ��� ����
    int x, y;
    int dx, dy;
    bool active;

    // ������: �Ѿ��� �ʱ� ��ġ�� ������ ����
    Bullet(int startX, int startY, int dirX, int dirY);

    // �Ѿ��� �̵���Ű�� �޼���
    void move();

    // �Ѿ��� Ȱ��ȭ �������� Ȯ���ϴ� �޼���
    bool isActive() const;

private:
    // �ܼ� Ŀ���� ��ġ�� �����ϴ� �޼���
    void gotoxy(int x, int y);
};
