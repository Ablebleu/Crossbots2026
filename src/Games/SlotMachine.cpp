#include "Games/SlotMachine.h"
#include <iostream>
#include <random>

#define CLEAR "\033[2J\033[1;1H"

namespace Games {
    SlotMachine::SlotMachine() : Table() {
        symbols = {"7", "B", "S", "C", "D"};
    }

    SlotMachine::~SlotMachine() {
    }

    void SlotMachine::playRound() {
        moneyBet = 0;

        std::cout << CLEAR;
        std::cout << "Saldo do Jogador: $" << player->getMoney() << "\n\n";
        std::cout << "Legenda de Simbolos:\n";
        std::cout << "[7] Sete | [B] BAR | [S] Sino | [C] Cereja | [D] Diamante\n\n";
        std::cout << "Digite o valor da aposta ou 0 para sair: ";

        int m = -1;
        while (moneyBet == 0 || m < 0) {
            std::cin >> m;
            if (m == 0) return;
            betMoney(player->giveMoney(m));
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<size_t> dist(0, symbols.size() - 1);

        std::string s1 = symbols[dist(gen)];
        std::string s2 = symbols[dist(gen)];
        std::string s3 = symbols[dist(gen)];

        std::cout << CLEAR;
        std::cout << "--- CACA-NIQUEL ---\n\n";
        std::cout << "   +---+  +---+  +---+\n";
        std::cout << "   | " << s1 << " |  | " << s2 << " |  | " << s3 << " |\n";
        std::cout << "   +---+  +---+  +---+\n\n";

        if (s1 == s2 && s2 == s3) {
            if (s1 == "7") {
                std::cout << "JACKPOT! Tres 7s! Voce ganhou 20x a aposta!\n";
                player->makeMoney(moneyBet * 20);
            } else {
                std::cout << "TRES IGUAIS! Voce ganhou 5x a aposta!\n";
                player->makeMoney(moneyBet * 5);
            }
        } else if (s1 == s2 || s1 == s3 || s2 == s3) {
            std::cout << "UM PAR! Voce recuperou o dobro da aposta (2x)!\n";
            player->makeMoney(moneyBet * 2);
        } else {
            std::cout << "Que pena, nenhum par. Voce perdeu!\n";
        }

        system("pause");
    }
}