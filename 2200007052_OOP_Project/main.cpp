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
        "the shawhank redemption",
        "the dark knight",
        "the lion king",
        "twelve angry man"
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
    }
    
    void choose_level()
    {
        cout << "-Easy: 1\n-Medium: 2\n-Hard: 3\nyour choice: ";
        cin >> level;
    }
    
    void guess()
    {
        if (level == 1)
        {
            int choice;
            for (int movieNUM = 0; movieNUM < NUM_OF_MOVIE; movieNUM++)
            {
                string current = censor(movies_2[movieNUM]);
                string answer = censor(movies_2[movieNUM]);
                bool correct_answer = false;
                
                cout << "\nmovie: " << current << endl;
                cout << "--guess name: 1\n--guess letter: 2\n";
                cout << "your choice: ";
                cin >> choice;
                
                if(choice == 1)
                {
                    cout << "Name of the movie " << current << " ? \n";
                    cin.ignore();
                    getline(cin, answer);
                    cout << answer.length() << current.length() << endl;
                    if (answer.length() != current.length())
                    {
                        cout << "The length of words are not same! \n";
                    }
                    else
                    {
                        for(int letterNUM = 0; letterNUM < current.length(); letterNUM++)
                        {
                            if (answer[letterNUM] != movies_2[movieNUM][letterNUM])
                            {
                                cout << "Wrong answer. ";
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
                            cout << "Correct! ";
                        }
                        
                    }
                }
                
                
            }
        }

    }
    
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
        movie_game.guess();
    }
    
    return 0;
}
