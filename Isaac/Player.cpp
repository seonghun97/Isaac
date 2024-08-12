#include "Player.h"

Player::Player(std::string name, int MaxHp, int Hp, int Damage, int Range, int AtkSpeed, int PlayerSpeed)
    : name(name), MaxHp(MaxHp), Hp(Hp), Damage(Damage), Range(Range), AtkSpeed(AtkSpeed), PlayerSpeed(PlayerSpeed)
{

}

void Player::TakeDamage(int damage) 
{
    Hp -= damage;
    if (Hp <= 0) 
    {
        std::cout << "Player " << name << " �׾���!" << std::endl;
    }
    else
    {
        std::cout << "Player " << name << " took " << damage << " damage. Remaining HP: " << Hp << std::endl;
    }
}

void Player::PlayerMove(char direction)
{
    switch (direction)
    {
    case 'w': std::cout << "Move up" << std::endl; break;
    case 's': std::cout << "Move down" << std::endl; break;
    case 'a': std::cout << "Move left" << std::endl; break;
    case 'd': std::cout << "Move right" << std::endl; break;
    default: std::cout << "Invalid direction!" << std::endl; break;
    }
}


void Player::DisplayHealth() const {
    std::string healthDisplay = "����ü��: ";
    for (int i = 0; i < MaxHp; ++i) {
        if (i < Hp) {
            healthDisplay += "��"; // ü���� �ִ� �κ�
        }
        else {
            healthDisplay += "��"; // ü���� ���� �κ�
        }
    }
    // ������ �Ʒ��� ��� (�����ϰ� �Ʒ��� ����ϴ� ���·� ����)
    std::cout << healthDisplay << std::endl;


}void Player::Attack()
{
}