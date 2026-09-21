#ifndef TABLE_H
#define TABLE_H

#include "Player.h"

namespace Games {
    enum TableAction {
        CONTINUE,
        CHANGE_GAME,
        EXIT_SESSION
    };

    class Table {
    protected:
        Player* player; 

    public:
        Table(); 
        virtual ~Table(); 

        void addPlayer(Player* p); 
        virtual void playRound() = 0;
        virtual TableAction play();   
    };
}

#endif