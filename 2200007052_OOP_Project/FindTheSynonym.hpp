//
//  FindTheSynonym.hpp
//  2200007052_OOP_Project
//
//  Created by MAC on 31.12.2023.
//

#ifndef FindTheSynonym_hpp
#define FindTheSynonym_hpp

#define NUM_OF_WORD 5


#include <iostream>
#include "Game.hpp"

using namespace std;

struct words_for_game {
    string word; // the word to be shown to user
    string synonyms; // synonym of the word, which is wanted to be predicted from user
    int score;
    bool used;
};


class FindTheSynonym : public Game // class for first game.
{
// member variables:
private:
    words_for_game words[NUM_OF_WORD];
    
    string guess; // users answer
    
// membeer functions
public:
    FindTheSynonym();
    
    ~FindTheSynonym();
    
    void getGuess(int num);
    
    bool check_answer(int num, int minus_score);

    void start();  // override the virtual method
        
    void reminder() override;
};




#endif /* FindTheSynonym_hpp */
