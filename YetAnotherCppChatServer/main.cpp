#include <iostream>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/wait.h>

using namespace std;

// Chat Server
int main()
{
    // Define variables
    string portNumStr;
    int portNum;
    string nickname;

    // Get port number info from user
    cout << "Enter port number for chat server connection (leave blank for default of 54000): ";
    getline(cin, portNumStr);

    // If blank, set port to 54000
    if (portNumStr == "")
        portNum = 54000;
    // ...otherwise, convert the port input from user frpm a string to an integer so it can be used in the socket commands
    else
        portNum = stoi(portNumStr);

    // Get nickname from user
    cout << "Enter nickname for this chat session (leave blank to use \"Server\"): ";
    getline(cin, nickname);

    // If blank, set the nickname to display "Server" as the nickname
    if (nickname == "")
        nickname = "Server";

    // Begin listening for a connection
    cout << "\n\nChat server listening on port number " << portNum << endl;

    // Define a message buffer, with max size of 4096 characters
    char buffer[4096];

    // Setup a listening socket
    sockaddr_in servAddr; // Define the server listening socket
    bzero((char*)&servAddr, sizeof(servAddr)); // Erase the data at the memory location defined by the socket
    servAddr.sin_family = AF_INET; // Set socket to IPv4
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Listen for address of any IP
    servAddr.sin_port = htons(portNum); // Listen on user-selected port number -- htons -> converts the unsigned short integer hostshort from host byte order to network byte order
    int socketListener = socket(AF_INET, SOCK_STREAM, 0); // Initialize socket

    // Check for problems with socket
    if(socketListener < 0)
    {
        cerr << "Error establishing the server socket" << endl;
        exit(0);
    }

    //Bind the socket to its IP address
    int bindStatus = bind(socketListener, (struct sockaddr*) &servAddr,sizeof(servAddr));

    // Check for problems binding the socket
    if(bindStatus < 0)
    {
        cerr << "Error binding socket to local address" << endl;
        exit(0);
    }

    // Wait for a connection
    cout << "Waiting for a client to connect..." << endl;

    // Listen for up to 5 requests at a time
    listen(socketListener, 5);

    // Create a new socket for connecting to the client
    sockaddr_in newSockAddr;
    socklen_t newSockAddrSize = sizeof(newSockAddr);

    // Accept the new connection
    int newSocket = accept(socketListener, (sockaddr *)&newSockAddr, &newSockAddrSize);

    // Check for connection problems
    if(newSocket < 0)
    {
        cerr << "Error accepting request from client!" << endl;
        exit(1);
    }
    cout << "Connected with client!" << endl;

    // Define log variables
    int bytesRead, bytesWritten = 0;
    struct timeval start1, end1;

    // Get time for logging connection
    gettimeofday(&start1, NULL);

    // Begin conversation loop
    while(1)
    {
        // Listen for message from client
        cout << "Awaiting client response..." << endl;

        // Clear the buffer
        memset(&buffer, 0, sizeof(buffer));

        // Read response into the buffer and log the number of bytes read
        bytesRead += recv(newSocket, (char*)&buffer, sizeof(buffer), 0);

        // Watch for "exit" response
        if(!strcmp(buffer, "exit"))
        {
            cout << "Client has quit the session" << endl;
            break;
        }

        // Display the response from client
        cout << buffer << endl;

        // Switch to sending a message back to client

        // Chat prompt
        cout << nickname << " > ";

        // Define input and send strings
        string userInput;
        string appendedUserInput;

        // Get input line from user
        getline(cin, userInput);

        // Clear the buffer
        memset(&buffer, 0, sizeof(buffer));

        // Check if user wants to exit the program
        if(userInput == "exit")
        {
            // Send exit signal to client
            send(newSocket, (char*)&buffer, strlen(buffer), 0);
            break;
        }

        // Append [nickname] to the front end of the user input
        appendedUserInput = "[" + nickname + "] " + userInput;

        // Copy appendedUserInput to the send buffer as a pointer to an array of characters
        strcpy(buffer, appendedUserInput.c_str());

        // Send the buffer and log the number of bytes sent
        bytesWritten += send(newSocket, (char*)&buffer, strlen(buffer), 0);
    }

    // Close both sockets and log the time connection was closed
    gettimeofday(&end1, NULL);
    close(newSocket);
    close(socketListener);

    // Display the connection log
    cout << "********Session********" << endl;
    cout << "Bytes written: " << bytesWritten << " Bytes read: " << bytesRead << endl;
    cout << "Elapsed time: " << (end1.tv_sec - start1.tv_sec)
        << " secs" << endl;
    cout << "Connection closed..." << endl;

    return 0;
}
