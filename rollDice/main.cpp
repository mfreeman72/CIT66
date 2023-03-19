#include <iostream>
#include <cstdlib>
#include <time.h> /* time */
using namespace std;

// function prototype for function defined below main - note there are no parameters
void rollDice();

int main()
{
    srand(time(NULL)); // seed the rand() function using the current runtime

	// call to get the value of two rolls of the dice
    rollDice();

    return 0;
}

//********** Programmer-defined Function **********
// returns the result of a single die roll from 1 to 6
void rollDice()
{
    int roll = 0;

    roll = rand() % 6 + 1;

    cout << roll << endl;
}
