#include <iostream>

using namespace std;

int main()
{
    int day = 0;
    cout << "Enter day number (1 = Monday, 7 = Sunday): ";
    cin >> day;
    switch (day)
        {
        case 1:
            cout << "\n\nToday is Monday\n";
            break;
        case 2:
            cout << "\n\nToday is Tuesday\n";
            break;
        case 3:
            cout << "\n\nToday is Wednesday\n";
            break;
        case 4:
            cout << "\n\nToday is Thursday\n";
            break;
        case 5:
            cout << "\n\nToday is Friday\n";
            break;
        case 6:
            cout << "\n\nToday is Saturday\n";
            break;
        case 7:
            cout << "\n\nToday is Sunday\n";
            break;
        default:
            cout << "Invalid day number!";
            break;
        }

    return 0;
}
