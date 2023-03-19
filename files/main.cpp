#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream myFile;
    myFile.open("mike.txt", ios::out); // write
    if(myFile.is_open()) {
        myFile << "Hello/n";
        myFile << "This is the second line\n";
        myFile.close();
    }

    return 0;
}
