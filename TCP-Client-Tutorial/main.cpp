#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    string IPStr;
    string portNumStr;
    int portNum;
    string nickname;

    // Get IP connection info from user
    cout << "Enter IP for chat server connection (leave blank to default to localhost): ";
    getline(cin, IPStr);

    if (IPStr == "")
        IPStr = "127.0.0.1";

    // Get port number info from user
    cout << "Enter port number for chat server connection (leave blank to default to port 54000): ";
    getline(cin, portNumStr);

    if (portNumStr == "")
        portNum = 54000;
    else
        portNum = stoi(portNumStr);

    // Get nickname from user
    cout << "Enter nickname for this chat session (leave blank to use IP address): ";
    getline(cin, nickname);

    if (nickname == "")
        nickname = IPStr;

    cout << "Connecting as \"" << nickname << "\" to chat server at " << IPStr << ":" << portNum << endl;

    // Create socket
    int socketListener = socket(AF_INET, SOCK_STREAM, 0);
    if (socketListener == -1 )
    {
        cout << "Error connecting to socket" << endl;
        return 1;
    }

    // Create hint structure (information used to connect) for the server we're connecting with
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(portNum);
    inet_pton(AF_INET, IPStr.c_str(), &hint.sin_addr);

    // Connect to server on the socket
    int connectRes = connect(socketListener, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        cout << "Error connecting to server" << endl;
        return 1;
    }

    // While loop:
    char buf[4096];
    string userInput;
    string appendedUserInput;

    do
    {
        //   Enter lines of text
        cout << nickname << " > ";
        getline(cin, userInput);
        if ((userInput == "exit") or (userInput == "quit"))
        {
            close(socketListener);
            return 0;
        }

        appendedUserInput = "[" + nickname + "] " + userInput;

        //   Send to server
        int sendRes = send(socketListener, appendedUserInput.c_str(), appendedUserInput.size() + 1, 0);
        if (sendRes == -1)
        {
            cout << "Error sending to server" << endl;
            continue;
        }
        //   Wait for response
        memset(buf, 0, 4096);
        int bytesReceived = recv(socketListener, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cout << "Error getting response from server" << endl;
        }
        else
        {
        //   Display response
        cout << "(Received)" << endl;
        }
    } while (true);

    // Close the socket
    close(socketListener);

    return 0;
}
