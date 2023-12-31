//
//  guessActor.hpp
//  2200007052_OOP_Project
//
//  Created by MAC on 31.12.2023.
//

#ifndef guessActor_hpp
#define guessActor_hpp

#include <iostream>
#include "Game.hpp"

#define NUM_OF_ACTOR 7

using namespace std;


// ------------------------------------------------- //
struct actor_movie  // struct to store actor and movies of that actor as clue
{
    string actor;
    string movie[3];
};

// ------------------------------------------------- //
class guessActor: public Game
{
private:
    actor_movie question[NUM_OF_ACTOR];
    
public:
    guessActor();
    
    ~guessActor();
    
    void reminder() override;
    
    void start();
    
private:
    bool guess_actor(int pr_movieNUM);
    
};


#endif /* guessActor_hpp */
