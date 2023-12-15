#include <iostream>
#define NUM_OF_WORD 5
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

    
    return 0;
}
