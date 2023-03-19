#include <iostream>
#include <string>

using namespace std;
string nickname;
string input;

int main(int argc, char *argv[])
{
    cout << "Please enter a nickname for this session: ";
    getline(cin, nickname);

//    cout << "Starting chat server on port " << argv[1] << "..." << endl;
    cout << "Starting chat server on port 12345..." << endl;
//    if(argc != 2)
//    {
//        cerr << "Usage: chatroom-server <port>" << endl;
//        exit(0);
//    }

    while((input != "exit") && (input != "quit"))
    {
        cout << nickname << " > ";
        getline(cin, input);
    }

    return 0;
}
