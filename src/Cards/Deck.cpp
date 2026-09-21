#include "Cards/Deck.h"
#include <algorithm>
#include <random>

namespace Cards {
    Deck::Deck() {
        deck.clear();
        for (int naipe = 0; naipe < 4; naipe++) {
            for (int rank = 1; rank <= 13; rank++) {
                deck.push_back(new Card(rank, naipe));
            }
        }
    }

    Deck::~Deck() {
        for (size_t i = 0; i < this->deck.size(); ++i) {
            delete deck[i];
        }
        deck.clear();
    }

    void Deck::insertBack(Card* card) {
        deck.push_back(card);
    }

    Card* Deck::drawCard() {
        Card* top = deck.back();
        deck.pop_back();
        return top;
    }

    void Deck::shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);
    }
}