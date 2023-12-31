#include <iostream>
#include <string>

#include "Game.hpp"
#include "Player.hpp"
#include "FindTheSynonym.hpp"
#include "MovieGame.hpp"
#include "guessActor.hpp"

using namespace std;


int main()
{
    cout << "\n\n";
    cout << "Welcome!\n";
    
    char yes_no;
    Player player1; // create player object
    
    cout << "Do you want to set a user name (y/n)? ";
    cin >> yes_no;
    
    if (yes_no == 'y')
        player1.setUserName();
        
    while (1)
    {
        // menu:
        cout << "\n====================================\n";
        cout << "\nChoose a game to play: \n";
        cout << "------------------------\n";
        cout << "1 - Find the synonym\n";
        cout << "2 - Guess movie\n";
        cout << "3 - Guess actor\n\n";
        
        // user chooses a game to play or exit
        int choice;
        cout << "Enter your choice (0 for terminate) : ";
        cin >> choice;
        cout << endl;
        
        if(choice == 0)
        {
            break;
        }
        if (choice == 1) // if the first game is choosen
        {
            FindTheSynonym synonym_game; // create object for 'find synonym game'
            synonym_game.start();
            int score = synonym_game.getTotalScore();
            player1.setTotalScore(score);
        }
        else if (choice == 2)
        {
            MovieGame movie_game;// create game object
            movie_game.start(); // whole process of the game is in thi method
            int score = movie_game.getTotalScore();
            player1.setTotalScore(score);
        }
        else if (choice == 3)
        {
            guessActor actor_game;
            actor_game.start();
            int score = actor_game.getTotalScore();
            player1.setTotalScore(score);
        }
        else // if user enters invalid input
        {
            cout << "Invalid input!\n";
        }
        
    }
    
    cout << "Your total score: " << player1.getGameScore() << ". \n";
    cout << "Goodbye " << player1.getUserName()<< "!\n\n";
    
    return 0;
}

// algorithm works problemless for every game
// 0 can terminate the game where ever you are in the algorithm.
// scoring system is working find
// no problem detected
