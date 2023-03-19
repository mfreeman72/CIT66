#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cerr << "Can't create socket!";
        return -1;
    }

    // Bind the socket to IP / Port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000); // htons --> "Host to network short" - translates numbers larger than 255 depending on big- or little-endian processors
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr); // converts IP address pointer string to array of numbers --> 127.0.0.1 becomes {127, 0, 0, 1}

    if (bind(listening, (sockaddr*)&hint, sizeof(hint)) == -1 )
    {
        cerr << "Can't bind to IP/Port";
        return -2;
    }

    // Mark the socket for listening in
    if (listen(listening, SOMAXCONN) == -1 )
    {
        cerr << "Can't listen!";
        return -3;
    }

    // Multi-client listening
    fd_set master;

    FD_ZERO(&master);

    FD_SET(listening, &master);

    while (true)
    {
        fd_set copy = master;

        int socketCount = select(0, &copy, nullptr, nullptr, nullptr);

        system("pause");

        for (int i = 0; i < socketCount; i++)
        {
            int sock = copy.fd_array[i];

            if (sock == listening)
            {
                // Accept a new connection
                int client = accept(listening, nullptr, nullptr);

                // Add the new connection to the list of connected clients
                FD_SET(client, &master);

                // Send a welcome message to the connected client
                string welcomeMsg = "Welcome to the Awesome Chat Server!";
                send(client, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
            }
            else
            {
                char buf[4096];
                ZeroMemory(buf, 4096);

                int bytesIn = recv(sock, buf, 4096,0);
                if (bytesIn <= 0)
                {
                    // Drop the client
                    closesocket(sock);
                    FD_CLR(sock, &master);
                }
                else
                {
                    // Send message to other clients, and definitely not the listening socket

                    for (int i = 0; i < master.fd_count; i++)
                    {
                        int outSock = master.fd_array[i];
                        if (outSock != listening && outSock != sock)
                        {
                            ostringstream ss;
                            ss << "SOCKET #" << sock << ": " << buf << "\r\n";
                            string strOut = ss.str();

                            send(outSock, strOut.c_str(), strOut.size() + 1, 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}



//    // Accept a call
//    sockaddr_in client;
//    socklen_t clientsize = sizeof(client);
//    char host[NI_MAXHOST];
//    char svc[NI_MAXSERV];
//
//    int clientSocket = accept(listening, (sockaddr*) &client, &clientsize);
//    if (clientSocket == -1 )
//    {
//        cerr << "Problem with client connecting!";
//        return -4;
//    }
//
//    // Close the listening socket
//    close(listening);
//
//    memset(host, 0, NI_MAXHOST); // Releases used memory
//    memset(svc, 0, NI_MAXSERV);
//
//    int result = getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, svc, NI_MAXSERV, 0);
//
//    if (result)
//    {
//        cout << host << "connected on " << svc << endl;
//    }
//    else
//    {
//        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST); // Turn the IP array back into the IP string
//        cout << host << " connected on " << ntohs(client.sin_port) << endl;
//    }
//
//    // While receiving - display the message, echo message
//    char buf[4096];
//    while (true)
//    {
//        // Clear buffer
//        memset(buf, 0, 4096);
//        // Wait for message
//        int bytesRecv = recv(clientSocket, buf, 4096, 0);
//        if (bytesRecv == -1)
//        {
//            cerr << "There was a connection issue" << endl;
//            break;
//        }
//
//        if (bytesRecv == 0)
//        {
//            cout << "The client disconnected" << endl;
//            break;
//        }
//        // Display message
//        cout << "Received: " << string(buf, 0, bytesRecv) << endl;
//        // Resend message
//        send(clientSocket, buf, bytesRecv + 1, 0);
//    }
