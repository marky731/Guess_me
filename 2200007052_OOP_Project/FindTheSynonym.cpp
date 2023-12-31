//
//  FindTheSynonym.cpp
//  2200007052_OOP_Project
//
//  Created by MAC on 31.12.2023.
//

#include "FindTheSynonym.hpp"

FindTheSynonym:: FindTheSynonym()
{
    cout << "\n--welcome to the find synonym game!-- \n\n";
    cout << "You have 5(easy), 3(medium) or 1(hard) chances to guess the synonym of the given TURKISH word.\n";
    cout << "         -------  ---------    ------- -------                                   -------\n\n";
    
    reminder();
    
// these line works on xcode and visual studio but not on vsCode.
// and i also cant create executable file because of these 5 lines :
//        words[0] = {"biçim", 0, "şekil", 5};
//        words[1] = {"cevap", 0, "yanıt", 5};
//        words[2] = {"obje", 0, "nesne", 5};
//        words[3] = {"kalp", 0, "yürek", 5};
//        words[4] = {"kabahat", 0, "suç"};
    
    
    for(int i = 0; i < 5; i++)
    {
        words[i].score = 5;
    }
    
    words[0].word = "biçim";
    words[1].word = "cevap";
    words[2].word = "obje";
    words[3].word = "kalp";
    words[4].word = "kabahat";
    
    words[0].synonyms = "şekil";
    words[1].synonyms = "yanıt";
    words[2].synonyms = "nesne";
    words[3].synonyms = "yürek";
    words[4].synonyms = "suç";
    
    number_of_attempts = 0;
    total_score = 0;
    keep_play = true;
}


FindTheSynonym:: ~FindTheSynonym()
{
    cout << "FIND SYNONYM GAME ENDED. \n";
    end(); // keep_play = false, print game ended
}


void FindTheSynonym:: getGuess(int num)
{
    cout << "Word    : " << words[num].word << endl; //  print the word and get answer as input
    cout << "Synonym : ";
    cin >> guess;
}


bool FindTheSynonym:: check_answer(int num, int minus_score)
{
    if (guess == "0")
    {
        end();
        return false;
    }
    else if(guess == words[num].synonyms)
    {
        cout << "-- ! correct answer ! --\n"; // inform user the answer is true
        //template function: add_score()
        total_score = total_score + words[num].score; // add the score of this word to the total score
        cout << "     Your score  : " << words[num].score << " \n"; // score of this round
        cout << "     Total score : " << total_score << " \n"; // score of total
        return  true; // answer is true
    }
    else
    {
        cout << "- wrong answer!\n"; // inform user the answer is false
        words[num].score -= minus_score;  // initial score is 5, decrease it if answer is wrong
        // (-1 if easy, -2 if medium, -3 if hard)
        
        if(words[num].score <= 0)
        {
            words[num].score = 0;
        }
        
        return false; //  answer is wrong
    }
}


void FindTheSynonym:: start()  // override the virtual method
{
    cout << "FIND SYNONYM GAME STARTED : \n";
    cout << "--------------------------\n";
    
    int minus_score=0;
    int totalAttempNUM=0;
    
    choose_level();
    
    if (difficulity_level == 1)
    {
        minus_score = 1;
        totalAttempNUM = 5;
    }
    else if (difficulity_level == 2)
    {
        minus_score = 2;
        totalAttempNUM = 3;
    }
    else if (difficulity_level == 3)
    {
        minus_score = 5;
        totalAttempNUM = 1;
    }
    else
    {
        cout << "Invalid input. \n";
    }

    int NumOfWord;
    for (NumOfWord = 0; NumOfWord < NUM_OF_WORD; NumOfWord++)
    {
        // for each word do the following:
        for (number_of_attempts=1; number_of_attempts <= totalAttempNUM; number_of_attempts++)
        {
            // for each attempt do the following:
            getGuess(NumOfWord); // method prints the word and gets answer as input
            bool is_answer_correct = check_answer(NumOfWord, minus_score);
            if (keep_play==false)
            {
                break; // check_answer() returns false if user enterd 0 as answer  to quit
            }
            
            // check answer
            if (is_answer_correct)
            {
                cout << endl;
                break; //stop guessing if answer is correct. Move to the next word
            }
            if(number_of_attempts == totalAttempNUM )
            {
                cout << "You have used all your chances. \n";
                cout << "     Your score  : " << words[NumOfWord].score << " \n"; // score of this round
                cout << "     Total score : " << total_score << " \n\n"; // score of total
            }
        }
        
        if (keep_play==false)
        {
            break; // check_answer() returns false if user enterd 0 as answer
        }
        
        if(NumOfWord < NUM_OF_WORD - 1)
        cout << "Next question (0 to quit) :\n";
    }
    
}


// member acces functions:
string FindTheSynonym:: getWord(int num)
{
    return words[num].word; // return the corresponding words for game
}
    
void FindTheSynonym:: reminder()
{
    cout << "Remember always to use lowercase letters during the game.\n";
    cout << "                       ----------\n\n";
}
