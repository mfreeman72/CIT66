#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    float average = 4.43050;
    cout << "Original: " << average << endl;
    cout << "Three decimal places: " << setprecision(4) << average << endl;
    cout << "Width of 9: " << setw(9) << average << endl;
    cout << "Pad with a character: " << setw(9) << setfill('>') << average << endl;
    return 0;
}
