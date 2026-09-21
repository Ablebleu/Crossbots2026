#include "TableManager.h"
#include <iostream>

TableManager::TableManager() {
    this->player = nullptr;
}

TableManager::~TableManager() {
}

void TableManager::assignPlayer(Player* p) {
    player = p;
}

void TableManager::showCatalog() const {
    std::cout << "1 - Roulette\n";
    std::cout << "2 - Blackjack\n";
    std::cout << "3 - Slot Machine\n";
    std::cout << "4 - Poker\n";
}

/*Table* TableManager::getTable(int i) {
    switch (i) {
        case 1:
            return nullptr;
        case 2:
            return nullptr;
        case 3:
            return nullptr;
        case 4:
            return nullptr;
        default:
            return nullptr;
    }
}*/