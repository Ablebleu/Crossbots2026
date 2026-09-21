#include "Games/Table.h"
#include <iostream>
#define CLEAR "\033[2J\033[1;1H"

namespace Games {
    Table::Table() : player(nullptr) {
    }

    Table::~Table() {
    }

    void Table::addPlayer(Player* p) {
        player = p;
    }

    TableAction Table::play() {
        playRound();
        std::cout << CLEAR;
        std::cout << "Saldo atual: $" << player->getMoney() << "\n";
        std::cout << "0 - Sair do cassino\n";
        std::cout << "1 - Continuar nesta mesa\n";
        std::cout << "2 - Trocar de jogo\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 0:
                return EXIT_SESSION;
            case 1:
                return CONTINUE;
            case 2:
                return CHANGE_GAME;
            default:
                return CONTINUE;
        }
    }
}