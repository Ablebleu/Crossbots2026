#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Cards/Card.h"

namespace Cards {
    class Deck; 
    class Hand {
    private:
        std::vector<Card*> hand; 
        
    public:
        Hand();
        ~Hand();
        
        void addCard(Card* c);
        Card* replaceCard(int i, Card* c);
        Card* removeCard(); 

        const bool isEmpty() const;
        
        // Regras de pontuação
        const int getBlackjackScore() const; 
        const int getPokerScore() const; 

        void revealCards() const;
        void revealDealer() const;
    };
}

#endif 