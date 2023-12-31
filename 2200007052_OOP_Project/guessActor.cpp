//
//  guessActor.cpp
//  2200007052_OOP_Project
//
//  Created by MAC on 31.12.2023.
//

#include "guessActor.hpp"

guessActor:: guessActor()
{
    cout << "--welcome to the |ACTOR GUESSING| game!-- \n\n";
    cout << "You have to guess the actor based on the movies! \n";
    cout << "\nRules: \n";
    cout << "1. You can choose 3 LEVELS of DIFFICULITY.\n";
    cout << "2. You get 1 movie for HARD level, 2 movies for MEDIUM level and 3 movies for EASY level.\n";
    cout << "           ----------------        --------------------          ------------------\n";
    cout << "3. You get 1 point for EASY level, 2 points for MEDIUM level and 3 points for HARD level.\n";
    cout << "           ----------------        --------------------          ------------------\n";
    cout << "4. You have 1 chance to guess at every level.\n\n";

    reminder();
        
    //declare the actor and movies:
    {
        question[0].actor = "leonardo dicaprio";
        question[0].movie[0] = "Blood diamond";
        question[0].movie[1] = "The Wolf of Wall Street";
        question[0].movie[2] = "Titanic";
        
        question[1].actor = "johnny depp";
        question[1].movie[0] = "Charlie and the Chocolate Factory";
        question[1].movie[1] = "Alice in Wonderland";
        question[1].movie[2] = "Pirates of the Caribbean";
        
        question[2].actor = "tom hanks";
        question[2].movie[0] = "Catch Me If You Can";
        question[2].movie[1] = "The Green Mile";
        question[2].movie[2] = "Forrest Gump";
        
        question[3].actor = "brad pitt";
        question[3].movie[0] = "Once Upon a Time in Hollywood";
        question[3].movie[1] = "The Curious Case of Benjamin Button";
        question[3].movie[2] = "Fight Club";
        
        question[4].actor = "dwayne johnson";
        question[4].movie[0] = "Jumanji: Welcome to the Jungle";
        question[4].movie[1] = "Rampage";
        question[4].movie[2] = "Fast & Furious Presents: Hobbs & Shaw";
        
        question[5].actor = "al pacino";
        question[5].movie[0] = "The Irishman";
        question[5].movie[1] = "The Godfather";
        question[5].movie[2] = "Scarface";
        
        question[6].actor = "jim carrey";
        question[6].movie[0] = "Eternal Sunshine of the Spotless Mind";
        question[6].movie[1] = "The Mask";
        question[6].movie[2] = "The Truman Show";
        
        difficulity_level = 0;
        total_score = 0;
        number_of_attempts = 0;
        keep_play = true;
    }
}

guessActor:: ~guessActor()
{
    cout << "ACTOR GAME ENDED.\n";
    end();
}

void guessActor:: reminder()
{
    cout << "NOTE: Use LOWERCASE letters during the game.\n";
    cout << "      Enter 0 anywhen you want to QUIT.\n\n";
}

void guessActor:: start()
{
    while(keep_play)
    {
        cout << "\nGUESS ACTOR GAME STARTED :\n";
        cout << "------------------------------\n";
        cout << endl;
        choose_level();
        if (difficulity_level == 0)
        {
            end();
            break;
        }
        if (difficulity_level == 1)
        {
            int movieNUM = 3;
            guess_actor(movieNUM);
            break;
        }
        else if (difficulity_level == 2)
        {
            int movieNUM = 2;
            guess_actor(movieNUM);
            break;
        }
        else if (difficulity_level == 3)
        {
            int movieNUM = 1;
            guess_actor(movieNUM);
            break;
        }
        else
        {
            cout << "Invalid input! \n";
            continue;
        }
    }
}



bool guessActor:: guess_actor(int pr_movieNUM)
{
    // i get this line from internet to make getline() work properly. (no more contents we didn't see in class included in my code)
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the buffer
    
    for (int actorNUM = 0; actorNUM<NUM_OF_ACTOR; actorNUM++)
    {
        // for each actor
        cout << "\n";
        cout << actorNUM+1 << "/" << NUM_OF_ACTOR << " : \n";
        cout << "-----\n";
        for(int i = 0; i<pr_movieNUM; i++) // print corresponding amount of movie names
        {
            cout << "  " << i+1 << ".Movie Name: " << question[actorNUM].movie[i] << "\n";
        }
        
        string censored = censor(question[actorNUM].actor); // censor the name of actor and show it to user
        string answer = censor(question[actorNUM].actor); // to make length of string answer equal to string of actors name

        cout << "Actor :  " << censored << "\n";
        cout << "Answer:  ";
        
        getline(cin, answer);
        
        // since now the answer is stored in  variable 'answer'
        if (answer == "0")
        {
            return false;
        }
        else if (answer.length() != question[actorNUM].actor.length())
        {
            cout << "Length of the answer is not same! \n";
            cout << "The answer was : " << question[actorNUM].actor << "\n";
            cout << "Your answer was: " << answer << endl;
            cout << "     Your score  : 0 \n"; // score of this round
            cout << "     Total score : " << total_score << " \n\n"; // score of total
        }
        else // if user answered the question appropriately
        {
            if(answer == question[actorNUM].actor) //i fthe answer is correct
            {
                cout << "-- ! correct answer ! --\n"; // inform user the answer is true

                total_score =  total_score + difficulity_level; // my template function
                // pr_movieNUM because number of movie player gets is equal to the score for that round
                
                cout << "     Your score  : " << difficulity_level << " \n"; // score of this round
                cout << "     Total score : " << total_score << " \n\n"; // score of total
            }
            else // answer is wrong
            {
                cout << "Wrong! \n";
                cout << "The answer was : " << question[actorNUM].actor << "\n";
                cout << "     Your score  : 0 \n"; // score of this round
                cout << "     Total score : " << total_score << " \n\n"; // score of total
            }
        }
    } // end of for loop
    
    end();
    return true;
}
