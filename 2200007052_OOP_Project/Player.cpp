//
//  Player.cpp
//  2200007052_OOP_Project
//
//  Created by MAC on 31.12.2023.
//

#include "Player.hpp"

Player:: Player()
{
    username = "";
    gameScore = 0;
}


void Player::  setTotalScore(int score)
{
    gameScore += score;
}


void Player:: setUserName()
{
    cout << "What is your name?  ";
    cin >> username;
}


void Player:: setGamePlayed(string game)
{
    if (game == "Find Synonym")
    {
        gamePlayed[0] = game;
    }
    else if (game == "Movie Game")
    {
        gamePlayed[1] = game;
    }
    else if (game == "Guess the Ator")
    {
        gamePlayed[2] = game;
    }
}

int Player:: getGameScore()
{
    return gameScore;
}

string Player:: getUserName()
{
    return username;
}
