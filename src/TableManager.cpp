#include "TableManager.h"
#include "Games/Blackjack.h"
#include "Games/Roulette.h"
#include "Games/SlotMachine.h"
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
    std::cout << "2 - Roulette\n";
    std::cout << "3 - Slot Machine\n";
}

Games::Table* TableManager::getTable(int i) {
    switch (i) {
        case 1:
            return new Games::Blackjack();
        case 2:
            return new Games::Roulette();
        case 3:
            return new Games::SlotMachine();
        default:
            return nullptr;
    }
    return nullptr;
}