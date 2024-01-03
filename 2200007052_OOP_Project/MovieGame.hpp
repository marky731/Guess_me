//
//  MovieGame.hpp
//  2200007052_OOP_Project
//
//  Created by MAC on 31.12.2023.
//

#ifndef MovieGame_hpp
#define MovieGame_hpp

#define NUM_OF_MOVIE 7
#define NUM_OF_CHANCE 5



#include <iostream>
#include "Game.hpp"

class MovieGame : public Game
{
// member variables:
private:
    // data set for easy mode
    string movies_2[NUM_OF_MOVIE];
    // data set for medium mode
    string movies_3[NUM_OF_MOVIE];
    // data set for hard mode
    string movies_4[NUM_OF_MOVIE];
    
    int score_per_movie;
        
public:
    MovieGame();
    
    ~MovieGame();
    
    void start();
    
    void reminder() override;
    
// these methods are private because i dont want them to be called outside of the class
private:
    bool guess_name(string &current, string answer, string pr_movie, bool &correct_answer);
    
    void guess_letter(string &current, string pr_movie);
    
    void guess(string pr_movies[]);
};



#endif /* MovieGame_hpp */
