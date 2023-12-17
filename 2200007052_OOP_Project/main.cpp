// 2200007052
// ikram uygur


// must be incloded ?
// getline() ?
// wrong input type ?
// input  problems in find synonyms ?
// variables that aren't used in alghorithm ?

#include <iostream>
#include <string>
#define NUM_OF_WORD 5
#define NUM_OF_MOVIE 7
using namespace std;

struct words_for_game {
    string word; // the word to be shown to user
    bool used; // the word is used or not
    string synonyms; // synonym of the word, which is wanted to be predicted from user
    int score; 
}; //data type for datas of guessing synonym games

class Game
{
protected:
    int number_of_attempts;
    int player;
    int difficulity_level;
    int total_score;
    bool keep_play;

public:
    Game()
    {
        
    }
    void start()
    {
        cout << "GAME STARTED: \n";
    }
    void end()
    {
        keep_play = false;
        cout << "GAME ENDED. \n";

    }
    void rules();

};

class FindTheSynonym : public Game // class for first game. Game is to find the synonym of a word
{
private:
    words_for_game words[NUM_OF_WORD];
    
    string guess; // users answer
    
public:
    FindTheSynonym()
    {
        cout << "--welcome to the find synonym game!-- \n";
        cout << "You have five chances to guess the synonym of the given turkish word.\n";
        cout << "Remember always to use lowercase letters during the game.\n\n";
        
        words[0] = {"biçim", 0, "şekil", 5};
        words[1] = {"cevap", 0, "yanıt", 5};
        words[2] = {"obje", 0, "nesne", 5};
        words[3] = {"kalp", 0, "yürek", 5};
        words[4] = {"kabahat", 0, "suç", 5};
        
        number_of_attempts = 0;
        total_score = 0;
        keep_play = true;
    }
    
    ~FindTheSynonym()
    {
        end();
    }
    
    bool check_answer(int num)
    {
    
            if(guess == words[num].synonyms)
            {
                cout << "-- ! correct answer ! --\n"; // inform user the answer is true
                total_score += words[num].score; // add the score of this word to the total score
                cout << "     Your score  : " << words[num].score << " \n"; // score of this round
                cout << "     Total score : " << total_score << " \n"; // score of total
                return  true; // answer is true
            }
            else
            {
                cout << "- wrong answer!\n"; // inform user the answer is false
                words[num].score --;  // initial score is 5, decrease it by one if answer is wrong
                return false; //  answer is wrong
            }
    }
    
    void getGuess(int num)
    {
        cout << "Word    : " << words[num].word << endl; //  print the word and get answer as input
        cout << "Synonym : ";
        cin >> guess;
    }
    
    void start()
    {
        Game :: start();
        int NumOfWord;
        for (NumOfWord = 0; NumOfWord < NUM_OF_WORD; NumOfWord++)
        {// for each word do the following:
            for (number_of_attempts=1; number_of_attempts<=5; number_of_attempts++)
            { // 5 chance to guess
                getGuess(NumOfWord); // method prints the word and gets answer as input
                bool is_answer_correct = check_answer(NumOfWord); // check answer
                if (is_answer_correct)
                {
                    cout << endl;
                    break; //stop guessing if answer is correct
                }
                if(number_of_attempts == 5 )
                cout << "You have used all your 5 chances. \n\n";
            }
            
            if(NumOfWord < NUM_OF_WORD - 1)
            cout << "Next question:\n";
        }
        
    }
    
    string getWord(int num)
    {
        return words[num].word; // return the corresponding words for game
    }
    
    int get_total_score()
    {
        return total_score; // member acces function.
    }
};

class MovieGame : public Game
{
private:
    // data set for easy mode
    string movies_2[NUM_OF_MOVIE];
    // data set for medium mode
    string movies_3[NUM_OF_MOVIE];
    // data set for hard mode
    string movies_4[NUM_OF_MOVIE];
    // level (easy medium hard)
    int score_per_movie;
        
    
public:
    MovieGame()
    {
        cout << "--welcome to the |MOVIE GUESSING| game!-- \n\n";
        cout << "Rules: \n";
        cout << " 1. You have 5 chances to guess a letter in the name of the movie.\n";
        cout << " 2. You have only one chance to guess the name of the movie.\n";
        cout << "Note: Name of the movies are in english\n\n";
        
        movies_2[0] = "star wars";
        movies_2[1] = "the godfather";
        movies_2[2] = "jurassic park";
        movies_2[3] = "fight club";
        movies_2[4] = "pulp fiction";
        movies_2[5] = "forrset gump";
        movies_2[6] = "the matrix";
        
        movies_3[0] = "the dark knight";
        movies_3[1] = "the shawhank redemption";
        movies_3[2] = "the lion king";
        movies_3[3] = "twelve angry man";
        movies_3[4] = "the truman show";
        movies_3[5] = "the green mile";
        movies_3[6] = "fast and furious";
        
        difficulity_level = 0;
        total_score = 0;
    }
    
    ~MovieGame()
    {
        end();
    }

    void choose_level()
    {
        cout << " -Easy:   1\n -Medium: 2\n -Hard:   3\nyour choice (0 for exit this game): ";
        cin >> difficulity_level;
    }
    
    void start()
    {
        Game :: start();

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
    
    void end()
    {
        Game :: end();
    }
    
    
    
// these methods are private because i dont want them to be called outside of the class
private:
    
    string censor(string pr_movies)
    {
        // temporary variable (which is gonna be censored)
        string censored = pr_movies;
        // censor the name of the movie
        for(int letterNUM = 0; letterNUM < censored.length(); letterNUM++)
        {
            // dont censor the spaces
            if(pr_movies[letterNUM]!=' ')
            {
                censored[letterNUM] = '*';
            }
            else
            {
                pr_movies[letterNUM] = ' ';
            }
        }
        return censored;
    }
    
    bool guess_name(string &current, string answer, string pr_movie, bool correct_answer)
    {
        cout << "Name of the movie : " << endl;
        cout << current << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // i had trouble with getting the space characters included by cin
        getline(cin, answer);  // so i found these two lines on internet to solve the problem
        // since now the answer is stored in  variable 'answer'
        if (answer.length() != current.length()) // if the length of answer is not correct
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
                cout << "Correct! \n";
            }
            
        }
        return true; // return this because we need this for algorithm
    }
    
    void guess_letter(string &current, string pr_movie)
    {
        char guessed_letter;
        bool is_letter_existed = false;

        cout << "Enter letter: ";
        cin >> guessed_letter;
        
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
        
        cout << "movie: " << current << endl;
    }
    
    void guess(string pr_movies[])
    {
        int choice;
        for (int movieNUM = 0; movieNUM < NUM_OF_MOVIE; movieNUM++)
        {
            string current = censor(pr_movies[movieNUM]); // censor the correct answer
            string answer = censor(pr_movies[movieNUM]);  // the main aim actually is to declare string with the same lenght
            bool correct_answer = false; // if the answer is correct
            bool name_guessed = false;  // if the only chance of guessing name is used
            
            cout << "\n\nmovie: " << current << endl;
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
                for (int i = 0; i < 4; i++) // user has four chances left
                {
                    --score_per_movie;
                    cout << "--guess name:   1\n--guess letter: 2\n--terminate:    0\n";
                    cout << "your choice  (1,2,0):";
                    cin >> choice; // let ser decide to guess letter or name
                    if(choice == 1)  // if user decided to guess name
                    {
                        // correct_answer is true if the only chance of usesr is
                        name_guessed = guess_name(current, answer, pr_movies[movieNUM], correct_answer);
                        name_guessed = true;
                        i = 99; // double sure the for loop does not continue
                        choice = 3; // to avoid execute the if statement which calls guess_name()
                        break; // break because it don't need to gues letter below
                    }
                    // if for loop continues, that means user didn't choose 1, so guess letter
                    guess_letter(current, pr_movies[movieNUM]);
                    if (i+1 == 4) // if this is the last chance to guess letter and apparently is used above
                    {
                        cout << "you have used all your chance!\n";
                    }
                }
            }
            // if user decided to gues letter at the first place or tried to guess letter 5 times:
            if ( choice == 1 || !name_guessed)
            {
                // guess the name of the movie
                guess_name(current, answer, pr_movies[movieNUM], correct_answer);
            }
            total_score = total_score + score_per_movie;
            cout << "     Your score  : " << score_per_movie << " \n"; // score of this round
            cout << "     Total score : " << total_score << " \n"; // score of total
        }
    }
    
};


int main()
{
    cout << "Welcome!\n";
    Game myGame;
    while (1)
    {
        // menu:
        cout << "\n------------------------\n";
        cout << "Choose a game to play: \n";
        cout << "1 - Find the synonym\n";
        cout << "2 - Guess movie\n";
        cout << "3 - my game\n";
        
        // user chooses a game to play or exit
        int choice;
        cout << "\nEnter your choice (0 for terminate) : ";
        cin >> choice;
        cout << endl;
        
        if(choice == 0)
        {
            myGame.end();
            break;
        }
        if (choice == 1) // if the first game is choosen
        {
            FindTheSynonym synonym_game; // creaete object for 'find synonym game'
            synonym_game.start();
            
        }
        else if (choice == 2)
        {
            MovieGame movie_game;// creat game object
            movie_game.start(); // whole process of the game is in thi method
        }
        
    }
    
    return 0;
}
