// 2200007052
// ikram uygur


// vs code ?
// getline() ?
// wrong input type ?
// unused member access functions ?


// ALL REQUIREMENTS:
//  Classes ( Player. -BASED: Game.  -DERIVED: FindTheSynonym, MovieGame, GuessTheActor)
//  Constructors and Destructor (all of the four classes)
//  Accessor and Mutator Methods ( get_total_score(), getWord() )
//  Method overloading ( censor() )
//  Virtual Methods ( reminder() )
//  Inheritance (Game, FindTheSynonym, MovieGame, GuessTheActor)
//  Template function ( add_score() )
//  - Operator overloading ('==' for Game class, '+' for Player class)

#include <iostream>
#include <string>
#define NUM_OF_WORD 5
#define NUM_OF_MOVIE 7
#define NUM_OF_CHANCE 5
#define NUM_OF_ACTOR 7

using namespace std;


template <typename T> // Template function
T add_score(T total, T added)
{
    return total+added;
}


// ------------------------------------------------- //
class Game  // base class
{
protected:
    int number_of_attempts;
    string player;
    int difficulity_level;
    int total_score;
    bool keep_play;

public:
    Game()
    {

    }
    
    ~Game()
    {

    }
    
    void start()
    {
        cout << "GAME STARTED: \n";
    }
    
    void end()
    {
        keep_play = false;
    }
    
    void rules();
    
    
    void choose_level()
    {
        cout << " -Easy:   1\n -Medium: 2\n -Hard:   3\nyour choice (0 for exit this game): ";
        cin >> difficulity_level;
    }
    
    int getTotalScore()
    {
        return total_score;
    }
    
    
    virtual void reminder() = 0; // virtual function

    
    string censor(string pr_to_censor)
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

    // method overloading
    string censor(string pr_to_censor, int *letter_num)
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
                *letter_num -= 1; // we get the number of letters which are not spaces
            }
            else
            {
                pr_to_censor[letterNUM] = ' ';
            }
        }
        return censored;
    }
    
    friend bool operator==(Game& game1, Game& game2);

};


// ------------------------------------------------- //
class Player
{
protected:
    string username;
    string gamePlayed[3];
    int gameScore;
    
    
    
public:
    Player()
    {
        username = "";
        gameScore = 0;
    }
    
    
    void setTotalScore(int score)
    {
        gameScore += score;
    }
    
    
    void setUserName()
    {
        cout << "What is your name?  ";
        cin >> username;
    }
    
    
    void setGamePlayed(string game)
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
    
    int getGameScore()
    {
        return gameScore;
    }
    
    string getUserName()
    {
        return username;
    }
    
    friend Player operator+(Player& player1, Player& player2);

};



// ------------------------------------------------- //
// data type dor game
struct words_for_game {
    string word; // the word to be shown to user
    bool used; // the word is used or not
    string synonyms; // synonym of the word, which is wanted to be predicted from user
    int score;
};


class FindTheSynonym : public Game // class for first game.
{
// member variables:
private:
    words_for_game words[NUM_OF_WORD];
    
    string guess; // users answer
    
// membeer functions
public:
    FindTheSynonym()
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
            words[i].used = false;
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
    
    
    ~FindTheSynonym()
    {
        cout << "FIND SYNONYM GAME ENDED. \n";
        end(); // keep_play = false, print game ended
    }
    
    
    void getGuess(int num)
    {
        cout << "Word    : " << words[num].word << endl; //  print the word and get answer as input
        cout << "Synonym : ";
        cin >> guess;
    }
    
    
    bool check_answer(int num, int minus_score)
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
            total_score = add_score(total_score, words[num].score); // add the score of this word to the total score
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
    

    void start()  // override the virtual method
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
    string getWord(int num)
    {
        return words[num].word; // return the corresponding words for game
    }
        
    void reminder() override
    {
        cout << "Remember always to use lowercase letters during the game.\n";
        cout << "                       ----------\n\n";
    }
};



// ------------------------------------------------- //
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
    MovieGame()
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
    
    ~MovieGame()
    {
        end();
        cout << "MOVIE GAME ENDED. \n";
    }
    
    void start()
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
    
    void reminder() override
    {
        cout << "       (Enter 0 anywhen you want to QUIT)\n\n";
    }

// these methods are private because i dont want them to be called outside of the class
private:
    bool guess_name(string &current, string answer, string pr_movie, bool correct_answer)
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
    
    void guess_letter(string &current, string pr_movie)
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
    
    void guess(string pr_movies[])
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
            bool name_guessed = false;  // if the only chance of guessing name is used
            
            cout << "movie: " << current << endl;
            cout << "--guess name:   1\n--guess letter: 2\n--terminate:    0\n";
            cout << "your choice (1, 2, 0):"; // let ser decide to guess letter or name
            cin >> choice;
            if(choice == 0)
            {
                end();
                break;
            }
            
            score_per_movie = 5;

            if(choice == 2) // if user decided to gues letter at the first place
            {
                guess_letter(current, pr_movies[movieNUM]); // let user guess letter
                ++number_of_attempts; // became 1
                if(keep_play==false) // if user enter 0 as answer
                    {
                        break;
                    }
                for (number_of_attempts=1; number_of_attempts < NUM_OF_CHANCE; number_of_attempts++) // user has four chances left
                {
                    --score_per_movie;
                    cout << "--guess name:   1\n--guess letter: 2\n--terminate:    0\n";
                    cout << "your choice  (1,2,0):";
                    cin >> choice; // let ser decide to guess letter or name
                    if(choice == 0)
                    {
                        break; // breaks the small for loop
                    }
                    if(choice == 1)  // if user decided to guess name
                    {
                        // correct_answer is true if the only chance of usesr is
                        name_guessed = guess_name(current, answer, pr_movies[movieNUM], correct_answer);
                        if(keep_play==false)
                            break;
                        name_guessed = true;
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
                    }
                }
                if(choice == 0)
                {
                    end();
                    break; // breaks the main for loop
                }
            } // end of if(choice == 2)
            
            // if user decided to gues letter at the first place or tried to guess letter 5 times:
            if ( (choice == 1 || !name_guessed)&&keep_play)
            {
                // guess the name of the movie
                guess_name(current, answer, pr_movies[movieNUM], correct_answer);
            }
            
            if(keep_play==false)
                break;
            
            if(keep_play == true)
            {
                // my template function:
                total_score = add_score(total_score, score_per_movie); // add the score of this word to the total score
                cout << "     Your score  : " << score_per_movie << " \n"; // score of this round
                cout << "     Total score : " << total_score << " \n"; // score of total
            }
            
        } // end of for loop
    }
    
};


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
    guessActor()
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
    
    ~guessActor()
    {
        cout << "ACTOR GAME ENDED.\n";
        end();
    }
    
    void reminder() override
    {
        cout << "NOTE: Use LOWERCASE letters during the game.\n";
        cout << "      Enter 0 anywhen you want to QUIT.\n\n";
    }
    
    void start()
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

    
    
private:
    bool guess_actor(int pr_movieNUM)
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

                    total_score =  add_score(total_score, difficulity_level); // my template function
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
};


// ------------------------------------------------- //
Player operator+(Player& player1, Player& player2)
{
    Player result;
    result.setTotalScore(player1.getGameScore() + player2.getGameScore());
    // You might also want to combine other player-related information.
    return result;
}

bool operator==(Game& game1, Game& game2)
{
    return game1.getTotalScore() == game2.getTotalScore();
}




int main()
{
    cout << "\n\n";
    cout << "Welcome!\n";
    
    char c;
    Player player1; // create player object
    
    cout << "Do you want to set a user name (y/n)? ";
    cin >> c;
    
    if (c == 'y')
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

// algorithm works problemless for ever game
// 0 can terminate the game where ever you are in the algorithm.
// scoring system is working find
// no problem detected



// 2200007052
// ikram uygur
