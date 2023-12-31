//
//  Game.cpp
//  2200007052_OOP_Project
//
//  Created by MAC on 31.12.2023.
//

#include <iostream>
#include "Game.hpp"

using namespace std;

Game:: Game()
{

}

Game:: ~Game()
{

}

void Game:: start()
{
    cout << "GAME STARTED: \n";
}

void Game:: end()
{
    keep_play = false;
}


void Game:: choose_level()
{
    cout << " -Easy:   1\n -Medium: 2\n -Hard:   3\nyour choice (0 for exit this game): ";
    cin >> difficulity_level;
}

int Game:: getTotalScore()
{
    return total_score;
}


void reminder(); // virtual function


string Game:: censor(string pr_to_censor)
{
    // temporary variable (which is gonna be censored)
    string censored = pr_to_censor;
    // censor the name of the movie
    for(int letterNUM = 0; letterNUM < censored.length(); letterNUM++)
    {
        // dont censor the spaces
        if(pr_to_censor[letterNUM]!=' ')
        {
            censored[letterNUM] = '*';
        }
        else
        {
            pr_to_censor[letterNUM] = ' ';
        }
    }
    return censored;
}


