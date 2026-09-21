#include "TableManager.h"
#include "Games/Blackjack.h"
#include <iostream>

TableManager::TableManager() : player(nullptr) {
}

TableManager::~TableManager() {
}

void TableManager::assignPlayer(Player* p) {
    player = p;
}

void TableManager::showCatalog() const {
    std::cout << "1 - Blackjack\n";
    std::cout << "2 - Poker\n";
    std::cout << "3 - Roulette\n";
    std::cout << "4 - Slot Machine\n";
}

Games::Table* TableManager::getTable(int i) {
    switch (i) {
        case 1:
            return new Games::Blackjack();
        case 2:
            return nullptr;
        case 3:
            return nullptr;
        case 4:
            return nullptr;
        default:
            return nullptr;
    }
}