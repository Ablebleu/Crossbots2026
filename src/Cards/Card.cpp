#include "Cards/Card.h"

namespace Cards {
    Card::Card(int rank, int naipe) {
        switch (rank) {
            case 1:  this->Rank = "A"; break;
            case 11: this->Rank = "J"; break;
            case 12: this->Rank = "Q"; break;
            case 13: this->Rank = "K"; break;
            default: this->Rank = std::to_string(rank); break;
        }

        switch (naipe) {
            case 0: this->Naipe = "♥"; break;
            case 1: this->Naipe = "♦"; break; 
            case 2: this->Naipe = "♣"; break;
            case 3: this->Naipe = "♠"; break; 
            default: this->Naipe = "?"; break;
        }
    }

    Card::~Card() {
    }

    const std::string Card::getNaipe() const {
        return Naipe;
    }

    const std::string Card::getRank() const {
        return Rank;
    }
}