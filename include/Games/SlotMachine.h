#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include "Games/Table.h"
#include <vector>
#include <string>

namespace Games {
    class SlotMachine : public Table {
    private:
        std::vector<std::string> symbols;

    public:
        SlotMachine();
        virtual ~SlotMachine();

        void playRound();
    };
}

#endif