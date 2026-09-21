#include "Cards/Hand.h"
#include <iostream>
#include <string>

namespace Cards {
    Hand::Hand() {
        hand.clear();
    }

    Hand::~Hand() {
        for ( Card* card : hand){
            delete card;
            card = nullptr;
        }
        hand.clear();
    }

    void Hand::addCard(Card* c) {
        if (c != nullptr) {
            hand.push_back(c);
        }
    }

    Card* Hand::replaceCard(int i, Card* c) {
        if (i < 0 || i >= static_cast<int>(hand.size())) {
            return nullptr;
        }
        Card* oldCard = hand[i];
        hand[i] = c;
        return oldCard;
    }

    Card* Hand::removeCard() {
        if (hand.empty()) {
            return nullptr;
        }
        Card* top = hand.back();
        hand.pop_back();
        return top;
    }

    const bool Hand::isEmpty() const {
        return hand.empty();
    }

    const int Hand::getBlackjackScore() const {
        int score = 0;
        int aces = 0;

        for (const Card* card : hand) {
            if (card == nullptr) continue;

            std::string rank = card->getRank();

            /*
            Regra Blackjack: A = 1 ou 11, depende de qual for melhor, 
            K,Q,J,10=10 e o resto é valor da carta normal
            */

            if (rank == "A") {
                aces++;
                score += 11; 
            } else if (rank == "K" || rank == "Q" || rank == "J" || rank == "10") {
                score += 10;
            } else {
                score += std::stoi(rank);
            }
        }

        while (score > 21 && aces > 0) {
            score -= 10;
            aces--;
        }
        return score;
    }

    const int Hand::getPokerScore() const {
    }

    static std::string getNaipeExtenso(const std::string& naipe) {
        if (naipe == "♥") return "Copas";
        if (naipe == "♦") return "Ouros";
        if (naipe == "♣") return "Paus";
        if (naipe == "♠") return "Espadas";
        return naipe;
    }

    void Hand::revealCards() const {
        if (hand.empty()) {
            std::cout << "Mao vazia\n";
            return;
        }

        for (int i = 0; i < static_cast<int>(hand.size()); ++i) {
            if (hand[i] != nullptr) {
                std::string naipe = getNaipeExtenso(hand[i]->getNaipe());
                std::cout << (i + 1) << ": " << hand[i]->getRank() << " de " << naipe << std::endl;
            }
        }
        std::cout << "\n";
    }

    void Hand::revealDealer() const {
        if (hand.empty()) {
            std::cout << "Mao vazia\n";
            return;
        }

        if (hand[0] != nullptr) {
            std::cout << "1: ?" << std::endl;
        }

        for (int i = 1; i < static_cast<int>(hand.size()); ++i) {
            std::string naipe = getNaipeExtenso(hand[i]->getNaipe());
                std::cout << (i + 1) << ": " << hand[i]->getRank() << " de " << naipe << std::endl;
        }
        std::cout << "\n";
    }
} 