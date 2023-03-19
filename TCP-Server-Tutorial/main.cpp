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
    string portNumStr;
    int portNum;

    // Get user-generated port number for connection
    cout << "Enter port number for chat server connection (press Enter for default of 54000): ";
    getline(cin, portNumStr);

    if (portNumStr == "")
        portNum = 54000;
    else
        portNum = stoi(portNumStr);

    cout << "Chat server listening on port number " << portNum << endl;

    // Initialize a socket for connection
    int socketListener = socket(AF_INET, SOCK_STREAM, 0);
    if (socketListener == -1)
    {
        cerr << "Error creating socket";
        return -1;
    }

    // Bind the socket to IP / Port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(portNum); // htons --> "Host to network short" - translates numbers larger than 255 depending on big- or little-endian processors
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr); // converts IP address pointer string to array of numbers --> 127.0.0.1 becomes {127, 0, 0, 1}

    if (bind(socketListener, (sockaddr*)&hint, sizeof(hint)) == -1)
    {
        cerr << "Error binding socket to IP/Port";
        return -2;
    }

    // Mark the socket for listening
    if (listen(socketListener, SOMAXCONN) == -1)
    {
        cerr << "Error listening";
        return -3;
    }

    // Accept a call
    sockaddr_in client;
    socklen_t clientsize = sizeof(client);
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    int clientSocket = accept(socketListener, (sockaddr*) &client, &clientsize);
    if (clientSocket == -1)
    {
        cerr << "Error connecting to client";
        return -4;
    }

    // Close the listening socket
    close(socketListener);

    memset(host, 0, NI_MAXHOST); // Releases used memory
    memset(service, 0, NI_MAXSERV);

    int result = getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0);

    if (result)
    {
        cout << host << "connected on " << service << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST); // Turn the IP array back into the IP string
        cout << host << " connected on " << ntohs(client.sin_port) << endl;
    }

    // While receiving - display the message, echo message
    char buf[4096];
    while (true)
    {
        // Clear buffer
        memset(buf, 0, 4096);
        // Wait for message
        int bytesRecv = recv(clientSocket, buf, 4096, 0);
        if (bytesRecv == -1)
        {
            cerr << "There was a connection issue" << endl;
            break;
        }

        if (bytesRecv == 0)
        {
            cout << "The client disconnected" << endl;
            break;
        }
        // Display message
        cout << "Received: " << string(buf, 0, bytesRecv) << endl;
        // Resend message
        send(clientSocket, buf, bytesRecv + 1, 0);
    }
    return 0;
}
