#ifndef ROULETTE_H
#define ROULETTE_H

#include "Games/Table.h"

namespace Games {
    class Roulette : public Table {
    public:
        Roulette();
        ~Roulette();

        void playRound();
    };
}
#endif