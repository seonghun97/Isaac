#pragma once
#include <iostream>
#include <windows.h>
class Bullet {
public:
    int x, y;
    int dx, dy;
    bool active; // �Ѿ��� Ȱ��ȭ�� �������� Ȯ���ϴ� �÷���

    Bullet(); // �⺻ ������
    void init(int startX, int startY, int dirX, int dirY); // �Ѿ� �ʱ�ȭ
    void move(); // �Ѿ� �̵�
    bool isOutOfBounds() const; // �Ѿ��� ȭ�� ������ �������� Ȯ��
};
