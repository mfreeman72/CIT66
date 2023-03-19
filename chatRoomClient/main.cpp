#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Starting chat client on " << argv[1] << "..." << endl;

    if(argc != 2)
    {
        cerr << "Usage: chatroom-client <server IP address>:<port>" << endl;
        exit(0);
    }


    return 0;
}
