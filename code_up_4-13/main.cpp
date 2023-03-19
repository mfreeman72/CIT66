#include <iostream>

using namespace std;

int main()
{
    int customers = 2361;
    float sumOfRatings = 10456.2;
    float averageRating = sumOfRatings / customers;
    int roundedAverage = int(averageRating);
    cout << "Average: " << averageRating << endl;
    cout << "Rounded average: " << roundedAverage << endl;
    return 0;
}
