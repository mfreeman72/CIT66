#include <iostream>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/wait.h>

using namespace std;

// Chat client
int main()
{
    // Define variables
    string IPStr;
    string portNumStr;
    int portNum;
    string nickname;

    // Get IP connection info from user
    cout << "Enter IP for chat server connection (leave blank to default to localhost): ";
    getline(cin, IPStr);

    // If blank, set to localhost/127.0.0.1
    if (IPStr == "")
        IPStr = "127.0.0.1";

    // Get port number info from user
    cout << "Enter port number for chat server connection (leave blank to default to port 54000): ";
    getline(cin, portNumStr);

    // If blank, set port to 54000
    if (portNumStr == "")
        portNum = 54000;
    // ...otherwise, convert the port input from user from a string to an integer so it can be used in the socket commands
    else
        portNum = stoi(portNumStr);

    // Get nickname from user
    cout << "Enter nickname for this chat session (leave blank to use \"Client\"): ";
    getline(cin, nickname);

    // If blank, set the nickname to display "Client" as the nickname
    if (nickname == "")
        nickname = "Client";

    // Begin connection
    cout << "\n\nConnecting as \"" << nickname << "\" to chat server at " << IPStr << ":" << portNum << endl;

    // Convert IP chosen by the user to a char pointer
    const char* serverIp = IPStr.c_str();

    // Define a message buffer, with max size of 4096 characters
    char buffer[4096];

    // Setup a socket
    struct hostent* host = gethostbyname(serverIp); // Get the connection server host by the entered server IP
    sockaddr_in sendSockAddr; // Define socket
    bzero((char*)&sendSockAddr, sizeof(sendSockAddr)); // Erase the data at the memory location defined by the socket
    sendSockAddr.sin_family = AF_INET; // Set socket to IPv4
    sendSockAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list)); // Connect socket to server host IP
    sendSockAddr.sin_port = htons(portNum); // Send data to user-selected port number -- htons -> converts the unsigned short integer hostshort from host byte order to network byte order
    int socketListener = socket(AF_INET, SOCK_STREAM, 0); // Initialize socket for listening

    // Set up connection
    int status = connect(socketListener,(sockaddr*) &sendSockAddr, sizeof(sendSockAddr)); // Initialize the connection

    // Test the connection
    if(status < 0)
    {
        cout<<"Error connecting to socket!"<<endl;
        exit(0);
    }
    cout << "Connected to the server!" << endl;

    // Define log variables
    int bytesRead, bytesWritten = 0;
    struct timeval start1, end1;

    // Get time for logging connection
    gettimeofday(&start1, NULL);

    // Begin conversation loop
    while(1)
    {
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
            // Send exit signal to server
            send(socketListener, (char*)&buffer, strlen(buffer), 0);
            break;
        }

        // Append [nickname] to the front end of the user input
        appendedUserInput = "[" + nickname + "] " + userInput;

        // Copy appendedUserInput to the send buffer as a pointer to an array of characters
        strcpy(buffer, appendedUserInput.c_str());

        // Send the buffer and log the number of bytes sent
        bytesWritten += send(socketListener, (char*)&buffer, strlen(buffer), 0);

        // Switch to listening to for a response back from the server
        cout << "Awaiting server response..." << endl;

        // Clear the buffer
        memset(&buffer, 0, sizeof(buffer));

        // Read response into the buffer and log the number of bytes read
        bytesRead += recv(socketListener, (char*)&buffer, sizeof(buffer), 0);

        // Watch for "exit" response
        if(!strcmp(buffer, "exit"))
        {
            cout << "Server has quit the session" << endl;
            break;
        }

        // Display the response from server
        cout << buffer << endl;
    }

    // Close socket and log the time connection was closed
    gettimeofday(&end1, NULL);
    close(socketListener);

    // Display the connection log
    cout << "********Session********" << endl;
    cout << "Bytes written: " << bytesWritten <<
    " Bytes read: " << bytesRead << endl;
    cout << "Elapsed time: " << (end1.tv_sec- start1.tv_sec)
      << " secs" << endl;
    cout << "Connection closed" << endl;

    return 0;
}
