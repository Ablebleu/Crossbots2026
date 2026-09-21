#ifndef CASINO_H
#define CASINO_H

#include "Games/Table.h"
#include "TableManager.h"
#include "Player.h"

class Casino {
private:
    Games::Table* game;        
    TableManager manager; 
    Player* player;      

public:
    Casino();             
    ~Casino();            

    void run();   
    void showLogo() const;
};

#endif