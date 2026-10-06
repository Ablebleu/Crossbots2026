#include "Games/Roulette.h"
#include <iostream>
#include <random>

#define CLEAR "\033[2J\033[1;1H"

namespace Games {
    Roulette::Roulette() : Table() {
    }

    Roulette::~Roulette() {
    }

    void Roulette::playRound() {
        moneyBet = 0;

        std::cout << CLEAR;
        std::cout << "Saldo do Jogador: $" << player->getMoney() << "\n\n";
        std::cout << "Digite o valor da aposta ou 0 para sair: ";

        int m = -1;
        while (moneyBet == 0 || m < 0) {
            std::cin >> m;
            if (m == 0) return;
            betMoney(player->giveMoney(m));
        }

        std::cout << CLEAR;
        std::cout << "--- ROLETA ---\n";
        std::cout << "1 - Apostar em Numero Exato (0 a 36) [Paga 36x]\n";
        std::cout << "2 - Apostar em Cor (1: Vermelho, 2: Preto) [Paga 2x]\n";
        std::cout << "3 - Apostar em Par/Impar (1: Par, 2: Impar) [Paga 2x]\n";
        std::cout << "4 - Apostar em Duzia (1: 1-12, 2: 13-24, 3: 25-36) [Paga 3x]\n";
        std::cout << "Escolha o tipo de aposta: ";

        int option = 0;
        std::cin >> option;

        int betChoice = -1;

        switch (option) {
            case 1:
                std::cout << "Digite o numero (0 a 36): ";
                std::cin >> betChoice;
                while (betChoice < 0 || betChoice > 36) {
                    std::cout << "Numero invalido (0-36): ";
                    std::cin >> betChoice;
                }
                break;
            case 2:
                std::cout << "Escolha a cor (1 - Vermelho, 2 - Preto): ";
                std::cin >> betChoice;
                while (betChoice != 1 && betChoice != 2) {
                    std::cout << "Opcao invalida (1 ou 2): ";
                    std::cin >> betChoice;
                }
                break;
            case 3:
                std::cout << "Escolha (1 - Par, 2 - Impar): ";
                std::cin >> betChoice;
                while (betChoice != 1 && betChoice != 2) {
                    std::cout << "Opcao invalida (1 ou 2): ";
                    std::cin >> betChoice;
                }
                break;
            case 4:
                std::cout << "Escolha a duzia (1: 1-12, 2: 13-24, 3: 25-36): ";
                std::cin >> betChoice;
                while (betChoice < 1 || betChoice > 3) {
                    std::cout << "Opcao invalida (1, 2 ou 3): ";
                    std::cin >> betChoice;
                }
                break;
            default:
                std::cout << "Opcao invalida! Aposta devolvida.\n";
                player->makeMoney(moneyBet);
                system("pause");
                return;
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, 36);
        int resultNumber = dist(gen);

        int redNumbers[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
        bool isRed = false;
        if (resultNumber != 0) {
            for (int r : redNumbers) {
                if (resultNumber == r) {
                    isRed = true;
                    break;
                }
            }
        }

        std::string colorStr = (resultNumber == 0) ? "Verde" : (isRed ? "Vermelho" : "Preto");

        std::cout << CLEAR;
        std::cout << "Girando a roleta...\n\n";
        std::cout << "Resultado: " << resultNumber << " (" << colorStr << ")\n\n";

        bool won = false;
        int multiplier = 0;

        switch (option) {
            case 1:
                if (betChoice == resultNumber) {
                    won = true;
                    multiplier = 36;
                }
                break;
            case 2:
                if (resultNumber != 0) {
                    if ((betChoice == 1 && isRed) || (betChoice == 2 && !isRed)) {
                        won = true;
                        multiplier = 2;
                    }
                }
                break;
            case 3:
                if (resultNumber != 0) {
                    bool isEven = (resultNumber % 2 == 0);
                    if ((betChoice == 1 && isEven) || (betChoice == 2 && !isEven)) {
                        won = true;
                        multiplier = 2;
                    }
                }
                break;
            case 4:
                if (resultNumber != 0) {
                    int dozen = (resultNumber - 1) / 12 + 1;
                    if (betChoice == dozen) {
                        won = true;
                        multiplier = 3;
                    }
                }
                break;
        }

        if (won) {
            int payout = moneyBet * multiplier;
            std::cout << "Parabens! Voce ganhou $" << payout << "!\n";
            player->makeMoney(payout);
        } else {
            std::cout << "Voce perdeu!\n";
        }

        system("pause");
    }
}