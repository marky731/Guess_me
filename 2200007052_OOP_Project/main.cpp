#include <iostream>
#include <string>
#define NUM_OF_WORD 5
#define NUM_OF_MOVIE 7
using namespace std;

struct words_for_game {
    string word;
    bool used;
    string synonyms;
    int score = 5;
};

class Game
{
protected:
    int number_of_attempts = 0;
    int player;
    int difficulity_level;
    int total_score = 0;
    
    
    
public:
    void start();
    void end();
    void rules();

};

class FindTheSynonym : public Game
{
private:
    words_for_game words[NUM_OF_WORD] =
    {
        {"biçim", 0, "şekil"},
        {"cevap", 0, "yanıt"},
        {"obje", 0, "nesne"},
        {"kalp", 0, "yürek"},
        {"kabahat", 0, "suç"},
    };
    string guess;
    

public:
    
    FindTheSynonym()
    {
        cout << "--welcome to the find synonym game!-- \n\n";
    }
    
    string getWrod(int num)
    {
        return words[num].word;
    }
    
    bool check_answer(int num)
    {
    
            if(guess == words[num].synonyms)
            {
                cout << "correct answer!\n";
                total_score += words[num].score;
                cout << "Your score : " << words[num].score << ". \n";
                cout << "Your score : " << total_score << ". \n";
                return  true;
            }
            else
            {
                cout << "wrong answer!\n";
                words[num].score --;
                return false;
            }
    }
    
    void getGuess(int num)
    {
        cout << "Word: " << words[num].word << " ,  Synonym of it: ";
        cin >> guess;
    }
    
    int get_total_score()
    {
        return total_score;
    }
};

class MovieGame
{
private:
    string movies_2[NUM_OF_MOVIE] = {
        "star wars",
        "the godfather",
        "jurassic park",
        "fight club",
        "pulp fiction",
        "forrest gump",
        "the matrix"
    };
    string movies_3[NUM_OF_MOVIE] = {
        "the dark knight",
        "the shawhank redemption",
        "the lion king",
        "twelve angry man",
        "the truman show",
        "the green mile",
        "fast and furious"
    };
    string movies_4[NUM_OF_MOVIE];

    int level=0;
        
    
public:
    MovieGame()
    {
        cout << "--welcome to the movie guessing game!-- \n\n";
        cout << "Rules: \n";
        cout << "1. You have 5 chances to guess a letter in the name of the movie.\n";
        cout << "2. You have only one chance to guess the name of the movie.\n\n";
    }
    
    void choose_level()
    {
        cout << " -Easy:   1\n -Medium: 2\n -Hard:   3\nyour choice: ";
        cin >> level;
    }
    
    void start_guess()
    {
        if (level == 1)
        {
            guess(movies_2);
        }
        else if (level == 2)
        {
            guess(movies_3);
        }
        else if (level == 3)
        {
            guess(movies_4);
        }

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
        getline(cin, answer);
        if (answer.length() != current.length())
        {
            cout << "The length of words are not same! \n";
            cout << "Answer is : " << pr_movie << endl;
        }
        else
        {
            for(int letterNUM = 0; letterNUM < current.length(); letterNUM++)
            {
                if (answer[letterNUM] != pr_movie[letterNUM])
                {
                    cout << "Wrong answer. \n";
                    correct_answer = false;
                    break;
                }
                else
                {
                    correct_answer = true;
                }
            }
            
            if(correct_answer)
            {
                correct_answer = true;
                cout << "Correct! \n";
            }
            
        }
        return correct_answer;
    }
    
    void guess_letter(string &current, string pr_movie)
    {
        char guessed_letter;
        bool is_letter_existed = false;

        cout << "Enter letter: ";
        cin >> guessed_letter;
        
        for(int letterNUM = 0; letterNUM < current.length(); letterNUM++)
        {
            if(guessed_letter == pr_movie[letterNUM])
            {
                current[letterNUM] = guessed_letter;
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
            string current = censor(pr_movies[movieNUM]);
            string answer = censor(pr_movies[movieNUM]);
            bool correct_answer = false;
            
            cout << "\nmovie: " << current << endl;
            cout << "--guess name: 1\n--guess letter: 2\n";
            cout << "your choice: ";
            cin >> choice;
            
            if(choice == 2)
            {
                guess_letter(current, pr_movies[movieNUM]);
                for (int i = 0; i < 4; i++)
                {
                    cout << "--guess name: 1\n--guess letter: 2\n";
                    cout << "your choice: ";
                    cin >> choice;
                    if(choice == 1)
                    {
                        correct_answer = guess_name(current, answer, pr_movies[movieNUM], correct_answer);
                        i = 99;
                        choice = 3; // to avoid execute the if statement which calls guess_name()
                        break;
                    }
                    guess_letter(current, pr_movies[movieNUM]);
                    if (i+1 == 4)
                    {
                        cout << "you have used all your chance!\n";
                    }
                }
            }
            if ( choice == 1 || correct_answer == false)
            {
                if (correct_answer == false)
                {
                    guess_name(current, answer, pr_movies[movieNUM], correct_answer);
                }
            }
        }
    }
    
};


int main()
{
    
    cout << "Welcome! choose a game to play: \n";
    cout << "1 - Find the synonym\n";
    cout << "2 - Guess movie\n";
    cout << "3 - my game\n";
    
    int choice;
    cout << "\nEnter your choice (1,2,3) : ";
    cin >> choice;
    cout << endl;
    
    if (choice == 1)
    {
        FindTheSynonym synonym_game;
        for (int NumOfWord = 0; NumOfWord < NUM_OF_WORD; NumOfWord++)
        {
            for (int attemps=1; attemps<=5; attemps++)
            {
                synonym_game.getGuess(NumOfWord);
                bool is_answer_correct = synonym_game.check_answer(NumOfWord);
                if (is_answer_correct)
                {
                    cout << endl;
                    break;
                }
            }
            
            cout << "You have used all your 5 chances. \n\n";
            if(NumOfWord < NUM_OF_WORD - 1)
            cout << "Next question:\n";
        }
    }
    else if (choice == 2)
    {
        MovieGame movie_game;
        movie_game.choose_level();
        movie_game.start_guess();
    }
    
    return 0;
}
