#ifndef CASINO_H
#define CASINO_H

//#include "Table.h"
#include "TableManager.h"
#include "Player.h"

class Casino {
private:
    //Table* game;        
    TableManager manager; 
    Player* player;      

public:
    Casino();             
    ~Casino();            

    void run();   
    void showLogo() const;
};

#endif