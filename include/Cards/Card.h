#ifndef CARD_H
#define CARD_H

#include <string>

namespace Cards {
    class Card {
    private:
        std::string Naipe; 
        std::string Rank;  
        
    public:
        Card(int rank, int naipe); 
        ~Card();                

        const std::string getNaipe() const;
        const std::string getRank() const;
    };
} 

#endif 