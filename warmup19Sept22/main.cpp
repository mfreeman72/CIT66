#include <iostream>

using namespace std;

// mF 19 Sept 22

// Function prototypes

int main()
{
    string zoo[3][3];
    string animalTypes[3]];
    string animalName;


    string animalTypes[3] = {"Lions", "Tigers", "Bears"};
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout << "Please enter the name for " << animalTypes[i] << " number " << j << ": ";
            cin << animalName;
            zoo[i][j] = animalName;
        }
    }

    cout << "\n\nHere is your zoo:"

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout << animalTypes[i] << " " << j << ": " zoo[i][j] << "\t";
        }
        "\n"
    }

    return 0;
}
