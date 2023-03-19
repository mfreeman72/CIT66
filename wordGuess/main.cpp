#include <iostream>
#include <time.h>

using namespace std;

// Define functions
bool checkGuess(string, string, string);

int main()
{
    // Initializa variables
    string guess;
    string hideWord;
    int remainingGuesses;
    string retry;
    string word;
    bool good;
    bool goodGuess;
    string dictionary[5] = {"computer", "bubble", "television", "boba fett", "minimal"};

    while (retry == "yes")
    {
        remainingGuesses = 10;
        srand (time(NULL));
        word = dictionary[rand() % 5];
        for(int i=0; i < word.length(); i++)
        {
            if(str(word[i]) == " ")
            {
                hideWord[i] = " ";
            } else
            {
                hideWord[i] = "_";
            }
        }
        while (remainingGuesses > 0)
        {
            cout << "\nWelcome to Word Guess!\n";
            cout << "The word you are guessing is " << str(word.length()) << " letters long.\n";
            cout << "Current guesses: " << hideWord << "  Guesses left: " << str(remainingGuesses);
            cout << "Guess a letter or word: ";
            cin >> guess;
            goodGuess = checkGuess(word, tolower(guess));
            if goodGuess
            {
                cout << "\nCorrect guess!\n";
            } else
            {
                cout << "\nSorry. Incorrect guess.\n";
                remainingGuesses--;
            }
            if(hideWord == word)
            {
                cout << "\nYOU WON!";
                remainingGuesses = 0;
            }
        }
        cout << "\nThe word was: "  << word;
        cout << "\nWould you like to play again (yes/no)? ";
        cin >> retry;
    }
    return 0;
}

bool checkGuess(word, guess)
{
    if(word.length() != 1)
    {
        if (word == guess)
        {
            hideWord = guess;
            return true;
        } else return false;
    } else
    {
        good = false;

        for(int i=0; i < word.length(); i++)
        {
            if (word[i] == guess)
            {
                hideWord[i] = guess;
                good = true;
            }
        }
        return good;
    }
}
