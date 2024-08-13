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








}


void Player::DisplayHealth() const {
    std::string healthDisplay = "����ü��: "    ;
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