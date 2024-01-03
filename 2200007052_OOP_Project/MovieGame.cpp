//
//  MovieGame.cpp
//  2200007052_OOP_Project
//
//  Created by MAC on 31.12.2023.
//

#include "MovieGame.hpp"

MovieGame:: MovieGame()
{
    cout << "--welcome to the |MOVIE GUESSING| game!-- \n\n";
    cout << "Rules: \n";
    cout << " 1. You have 5 chances to guess a letter in the name of the movie.\n";
    cout << " 2. You have only one chance to guess the name of the movie.\n";
    cout << " 3. Easy: 2 words,   Medium: 3 words,   Hard: 4 words\n\n";
    cout << " Note: Name of the movies are in ENGLISH\n";
    cout << "       Use LOWERCASE letters during the game.\n";
    
    reminder();
    
    // initialize the data sets. curly braces for organizing
    {
        movies_2[0] = "star wars";
        movies_2[1] = "harry potter";
        movies_2[2] = "jurassic park";
        movies_2[3] = "fight club";
        movies_2[4] = "pulp fiction";
        movies_2[5] = "forrset gump";
        movies_2[6] = "toy story";
        
        movies_3[0] = "the dark knight";
        movies_3[1] = "the shawhank redemption";
        movies_3[2] = "the lion king";
        movies_3[3] = "twelve angry man";
        movies_3[4] = "the truman show";
        movies_3[5] = "the green mile";
        movies_3[6] = "fast and furious";
        
        movies_4[0] = "back to the future";
        movies_4[1] = "lord of the rings";
        movies_4[2] = "the dark knight rises";
        movies_4[3] = "pirates of the caribbean";
        movies_4[4] = "beauty and the beast";
        movies_4[5] = "there will be blood";
        movies_4[6] = "back to the future";
    }
    
    
    difficulity_level = 0;
    total_score = 0;
    number_of_attempts = 0;
    keep_play = true;
}

MovieGame:: ~MovieGame()
{
    end();
    cout << "MOVIE GAME ENDED. \n";
}

void MovieGame:: start()
{
    cout << "GUESS MOVIE NAME GAME STARTED : \n";
    cout << "------------------------------\n";
    
    choose_level();
    if (difficulity_level == 0)
    {
        end();
    }
    if (difficulity_level == 1)
    {
        guess(movies_2);  //get data set for easy mode for user to guess
    }
    else if (difficulity_level == 2)
    {
        guess(movies_3);  //get data set for medium mode for user to guess
    }
    else if (difficulity_level == 3)
    {
        guess(movies_4);  //get data set for hard mode for user to guess
    }

    
}

void MovieGame:: reminder()
{
    cout << "       (Enter 0 anywhen you want to QUIT)\n\n";
}

// these methods are private because i dont want them to be called outside of the class
bool MovieGame:: guess_name(string &current, string answer, string pr_movie, bool &correct_answer)
{
    cout << "Name of the movie : " << endl;
    cout << current << endl;
    
    // i had trouble with getting the space characters included by cin
    // so i found these two lines on internet to solve the problem
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the buffer
    getline(cin, answer);
    
    // since now the answer is stored in  variable 'answer'
    if (answer == "0")
    {
        end();
    }
    else if (answer.length() != current.length()) // if the length of answer is not correct
    {
        cout << "The length of words are not same! \n";
        cout << "Answer is : " << pr_movie << endl;
        score_per_movie = 0; // no gained score
    }
    else // if the length is correct:
    {
        //check every letter of the answer
        for(int letterNUM = 0; letterNUM < current.length(); letterNUM++)
        {
            if (answer[letterNUM] != pr_movie[letterNUM])
            {
                // if there is a letter doesn't match:
                cout << "Wrong answer. \n";
                cout << "Answer is : " << pr_movie << endl;
                correct_answer = false; // the answer is wrong
                score_per_movie = 0; // no gained score
                break; // so doesn't need to continue checking, get out of loop
            }
            else
            {
                //answer is correct if every letter are matched
                correct_answer = true;
            }
        }
        
        if(correct_answer)
        {
            // double ensure the boolen variable is true
            correct_answer = true;
            cout << "-- ! correct answer ! --\n"; // inform user the answer is true
        }
    }
    
    return true; // return true because the name is guessed once.
}

void MovieGame:: guess_letter(string &current, string pr_movie)
{
    char guessed_letter;
    bool is_letter_existed = false;

    cout << "Enter letter: ";
    cin >> guessed_letter;
    
    if (guessed_letter == '0')
        end();
    else
    {
        for(int letterNUM = 0; letterNUM < current.length(); letterNUM++)
        {
            if(guessed_letter == pr_movie[letterNUM]) // if the letter is matched
            {
                current[letterNUM] = guessed_letter; // make the letter appears to the user
                //if the letter is matched up, that indicates the letter exists in the movie name
                is_letter_existed = true;
            }
        }
        
        if(!is_letter_existed)
        {
            cout << "Letter does not exist in the name of the movie.\n";
        }
        
        cout << "\nmovie: " << current << endl; // show the current movie name with the guessed letters
    }
}


void MovieGame:: guess(string pr_movies[])
{
    int choice;
    for (int movieNUM = 0; movieNUM < NUM_OF_MOVIE; movieNUM++)
    {
        cout << "\n";
        cout << movieNUM+1 << "/" << NUM_OF_MOVIE << " : \n";
        cout << "-----\n";
        string current = censor(pr_movies[movieNUM]); // censor the correct answer
        string answer = censor(pr_movies[movieNUM]);  // the main aim actually is to declare string with the same lenght
        bool correct_answer = false; // if the answer is correct
        bool name_is_guessed = false;  // if the only chance of guessing name is used
        
        score_per_movie = 5;

            for (number_of_attempts=0; number_of_attempts < NUM_OF_CHANCE; number_of_attempts++) // user has four chances left
            {
                cout << "Movie: " << current << endl;
                cout << "--guess name:   1\n--guess letter: 2\n--terminate:    0\n";
                cout << "your choice  (1,2,0):";
                cin >> choice; // let ser decide to guess letter or name
                if(choice == 0)
                {
                    end();
                    break; // breaks the small for loop
                }
                if(choice == 1)  // if user decided to guess name
                {
                    // correct_answer is true if the only chance of usesr is
                    name_is_guessed = guess_name(current, answer, pr_movies[movieNUM], correct_answer);
                    if(keep_play==false)
                        break;
                    name_is_guessed = true;
                    number_of_attempts = 99; // double sure the for loop does not continue
                    choice = 3; // to avoid execute the if statement which calls guess_name()
                    break; // break because it don't need to gues letter below
                }
                // if for loop continues, that means user didn't choose 1, so guess letter
                guess_letter(current, pr_movies[movieNUM]);
                if(keep_play==false)
                    break;
                if (number_of_attempts+1 == NUM_OF_CHANCE) // if this is the last chance to guess letter and apparently is used above
                {
                    cout << "you have used all your chance!\n";
                    guess_name(current, answer, pr_movies[movieNUM], correct_answer);
                }
            }

        if(keep_play == true)
        {
            total_score = total_score + score_per_movie; // add the score of this word to the total score
            cout << "     Your score  : " << score_per_movie << " \n"; // score of this round
            cout << "     Total score : " << total_score << " \n"; // score of total
        }
        else if(keep_play == false)
        {
            break;
        }
        
    } // end of for loop
}
