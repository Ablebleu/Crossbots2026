#include "Player.h"
#include <iostream>

Player::Player(): money(014) {
    std::cout << "Digite a quantidade de dinheiro inicial do jogador: ";
    std::cin >> money;
}

Player::~Player() {
}

const int Player::getMoney() const {
    return money;
}

const int Player::giveMoney(int m) {
    if (m >= 0){
        if(m <= money) {
            money-=m;
            return m;
        }
        std::cout << "Quantidade invalida para saldo disponivel" << std::endl;
    }
    std::cout << "Quantidade invalida" << std::endl;
    return -1;
}

void Player::makeMoney(int m) {
    money += m;
}