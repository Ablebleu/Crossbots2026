#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

namespace Cards {
    class Deck {
    private:
        std::vector<Card*> deck; 
        
    public:
        Deck(); 
        ~Deck(); 
        
        void insertBack(Card* card);
        Card* drawCard();
        void shuffle();  
    };
}

#endif 