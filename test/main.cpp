#include <iostream>
#include <string>

using namespace std;

int main()
{
    string portNumStr;
    int portNum;

    // Get user-generated port number for connection
    cout << "Enter port number for chat server connection (press Enter for default of 54000): ";
    getline(cin, portNumStr);

    if (portNumStr == "")
        portNum = 54000;
    else
        portNum = stoi(portNumStr);

    cout << "Working on port number " << portNum << endl;
    return 0;
}
