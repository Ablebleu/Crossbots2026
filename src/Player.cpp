#include "Player.h"

Player::Player(): money(1400) {
}

Player::~Player() {
}

const int Player::getMoney() const {
    return money;
}

const int Player::giveMoney(int m) {
    if (m > 0){
        if(m <= money) {
            money-=m;
            return m;
        }
        //std::cout << "Quantidade invalida para saldo disponivel" << std::endl;
    }
    //std::cout << "Quantidade invalida" << std::endl;
    return 0;
}

void Player::makeMoney(int m) {
    money += m;
}