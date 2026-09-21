#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Games/Table.h"
#include "Cards/Deck.h"
#include "Cards/Hand.h"

namespace Games {
    class Blackjack : public Table {
    private:
        Cards::Deck deck;
        Cards::Hand dealerHand;
        Cards::Hand playerHand;
    protected:
        void playRound();

    public:
        Blackjack();
        ~Blackjack();
        
        void clearHands();
        void handReveal() const;
    };
}

#endif