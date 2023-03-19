#include <iostream>

using namespace std;

int main()
{
    int withoutParentheses = 3 + 2 * 5;
    int withParentheses = (3 + 2) * 5;
    cout << "Without parentheses: " << withoutParentheses << endl;
    cout << "With parentheses: " << withParentheses << endl;
    return 0;
}
