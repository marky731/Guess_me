//
//  Player.hpp
//  2200007052_OOP_Project
//
//  Created by MAC on 31.12.2023.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>

using namespace std;

class Player
{
protected:
    string username;
    string gamePlayed[3];
    int gameScore;
    
    
    
public:
    Player();

    void setTotalScore(int score);
    
    
    void setUserName();
    
    
    void setGamePlayed(string game);
    
    int getGameScore();
    
    string getUserName();
};



#endif /* Player_hpp */
