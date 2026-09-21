#ifndef TABLE_MANAGER_H
#define TABLE_MANAGER_H

//#include "Table.h"
#include "Player.h"

class TableManager {
private:
    Player* player;

public:
    TableManager();  
    ~TableManager(); 

    void assignPlayer(Player* p); 
    void showCatalog() const; 
    //Table* getTable(int i);    
};

#endif 