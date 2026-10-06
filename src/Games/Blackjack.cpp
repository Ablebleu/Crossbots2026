#include "Games/Blackjack.h"
#include <iostream>
#define CLEAR "\033[2J\033[1;1H"

namespace Games {
    Blackjack::Blackjack() : deck(), dealerHand(), playerHand() {
        deck.shuffle();
    }

    Blackjack::~Blackjack() {
    }

    void Blackjack::playRound() {
        clearHands();
        moneyBet = 0;

        std::cout << CLEAR;
        std::cout << "Saldo do Jogador: $" << player->getMoney() << "\n\n";
        std::cout << "Digite o valor da aposta ou 0 para sair: ";

        int m = -1;
        while ( moneyBet == 0 || m < 0 ) {
            std::cin >> m;
            if ( m <= 0 ) return;
            if( m > player->getMoney()) {
                std::cout << "Saldo insuficiente. Digite um valor menor ou igual a $" << player->getMoney() << ": ";
                continue;
            }
            betMoney(player->giveMoney(m));
        }

        for (int i = 0; i < 2; ++i) {
            playerHand.addCard(deck.drawCard());
            dealerHand.addCard(deck.drawCard());
        }
        
        std::cout << CLEAR;

        if(dealerHand.getBlackjackScore() != 21 
        && playerHand.getBlackjackScore() != 21) {
            std::cout << "Mao do dealer: \n";
            dealerHand.revealDealer();
        }
        else if (dealerHand.getBlackjackScore() == 21
        && playerHand.getBlackjackScore() != 21) {
            std::cout << "Dealer tem Blackjack!" << std::endl;
            handReveal();
            clearHands();
            system("pause");
            return;
        }
        else if (dealerHand.getBlackjackScore() != 21
        && playerHand.getBlackjackScore() == 21) {
            std::cout << "Blackjack! Voce ganhou!" << std::endl;
            handReveal();
            clearHands();
            player->makeMoney(moneyBet * 2);
            system("pause");
            return;
        }
        else {
            std::cout << "Empate com Blackjack!" << std::endl;
            handReveal();
            clearHands();
            player->makeMoney(moneyBet);
            system("pause");
            return;
        }
        std::cout << std::endl;
        std::cout << "Mao do jogador: \n";
        playerHand.revealCards();
        
        bool playerBusted = false;
        bool isFirstMove = true;
        int option = 0;

        while (playerHand.getBlackjackScore() < 21) {
            std::cout << "\n1 - Hit\n";
            std::cout << "2 - Stand\n";

            bool canDouble = isFirstMove && (player->getMoney() >= moneyBet);
            if (canDouble) {
                std::cout << "3 - Double Down\n";
            }

            std::cin >> option;

            if (option == 1) { // Hit
                playerHand.addCard(deck.drawCard());
                isFirstMove = false;

                std::cout << CLEAR;
                std::cout << "Mao do dealer: \n";
                dealerHand.revealDealer();
                std::cout << std::endl;
                std::cout << "Mao do jogador: \n";
                playerHand.revealCards();
            }
            else if (option == 2) { // Stand
                break;
            }
            else if (option == 3 && canDouble) { // Double Down
                betMoney(player->giveMoney(moneyBet));
                playerHand.addCard(deck.drawCard());

                std::cout << CLEAR;
                std::cout << "Mao do dealer: \n";
                dealerHand.revealDealer();
                std::cout << std::endl;
                std::cout << "Mao do jogador: \n";
                playerHand.revealCards();

                break;
            }
        }

        if (playerHand.getBlackjackScore() > 21) {
            playerBusted = true;
            std::cout << "\nVoce estourou!" << std::endl;
        }

        if (!playerBusted) {
            while (dealerHand.getBlackjackScore() < 17) {
                dealerHand.addCard(deck.drawCard());
            }
        }

        std::cout << CLEAR;
        handReveal();
        std::cout << std::endl;

        int playerScore = playerHand.getBlackjackScore();
        int dealerScore = dealerHand.getBlackjackScore();

        std::cout << "Pontuacao do Jogador: " << playerScore << std::endl;
        std::cout << "Pontuacao do Dealer: " << dealerScore << std::endl << std::endl;

        if (playerBusted) {
            std::cout << "Voce perdeu!" << std::endl;
        }
        else if (dealerScore > 21) {
            std::cout << "Dealer estourou! Voce ganhou!" << std::endl;
            player->makeMoney(moneyBet * 2);
        }
        else if (playerScore > dealerScore) {
            std::cout << "Voce ganhou!" << std::endl;
            player->makeMoney(moneyBet * 2);
        }
        else if (playerScore == dealerScore) {
            std::cout << "Empate!" << std::endl;
            player->makeMoney(moneyBet);
        }
        else {
            std::cout << "Dealer ganhou!" << std::endl;
        }

        clearHands();
        system("pause");
    }
    
    void Blackjack::clearHands(){
        while(!dealerHand.isEmpty()) {
            deck.insertBack(dealerHand.removeCard());
        }

        while(!playerHand.isEmpty()) {
            deck.insertBack(playerHand.removeCard());
        }
    }

    void Blackjack::handReveal() const {
        std::cout << "Mao do dealer: \n";
        dealerHand.revealCards();
        std::cout << std::endl;
        std::cout << "Mao do jogador: \n";
        playerHand.revealCards();
    }
}