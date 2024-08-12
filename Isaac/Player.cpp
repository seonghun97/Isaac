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
        std::cout << "Player " << name << " 죽었어!" << std::endl;
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
    std::string healthDisplay = "남은체력: ";
    for (int i = 0; i < MaxHp; ++i) {
        if (i < Hp) {
            healthDisplay += "♥"; // 체력이 있는 부분
        }
        else {
            healthDisplay += "♡"; // 체력이 없는 부분
        }
    }
    // 오른쪽 아래에 출력 (간단하게 아래에 출력하는 형태로 구현)
    std::cout << healthDisplay << std::endl;


}void Player::Attack()
{
}