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
        int moneyBet;

        virtual void playRound() = 0;
    public:
        Table(); 
        virtual ~Table(); 
        void addPlayer(Player* p); 

        virtual TableAction play();   
        void betMoney(int m);
    };
}

#endif