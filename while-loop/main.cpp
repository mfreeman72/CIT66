#include <iostream>

using namespace std;

int main()
{
    // Initialize variables
    int loopCounter = 0;
    int totalWeight = 0;
    int weight = 10;

    // Test the loop control variable
    while (loopCounter < 10)
    {
        // Increment control variable
        loopCounter++;

        // Add weight for each repetition
        totalWeight = totalWeight + weight;

        // Output each repetition
        cout << "Counter: " << loopCounter << "    Total Weight: " << totalWeight << endl;
    }
    return 0;
}
