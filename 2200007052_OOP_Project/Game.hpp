//
//  Game.hpp
//  2200007052_OOP_Project
//
//  Created by MAC on 31.12.2023.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>

using namespace std;

class Game  // base class
{
protected:
    int number_of_attempts;
    string player;
    int difficulity_level;
    int total_score;
    bool keep_play;

public:
    Game();
    
    ~Game();
    
    void start();
    
    void end();
    
    void rules();
    
    void choose_level();
    
    int getTotalScore();
    
    virtual void reminder() = 0; // virtual function
    
    string censor(string pr_to_censor);
};



#endif /* Game_hpp */
