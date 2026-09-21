#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int money;

public:
    Player();  
    ~Player(); 

    const int getMoney() const; 
    const int giveMoney(int m);   
    void makeMoney(int m); 
};

#endif