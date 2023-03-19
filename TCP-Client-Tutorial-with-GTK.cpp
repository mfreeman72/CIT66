#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <gtkmm.h>

using namespace std;

// Define the two possible GTK windows
Gtk::ApplicationWindow* window = nullptr; // Main application window
Gtk::Dialog* ipWindow = nullptr; // IP entry dialog window

// Define static functions for what happens for each window widget interaction
static

// IP entry dialog "Cancel" button clicked
void on_cancel_clicked()
{
  if(ipWindow)
    ipWindow->hide(); // hide() will close window
}

// Show the IP entry dialog
void showIPWindow()
{
    Gtk::Button* cancel = nullptr; // IP dialog Cancel button - Signals: on_cancel_clicked
    Gtk::Button* ok = nullptr; // IP dialog Ok button - Signals: on_ok_clicked and on_ok_enter
    Gtk::Entry* ip1 = nullptr; // IP dialog 1st IP entry box - Signals: on_ip1_changed
    Gtk::Entry* ip2 = nullptr; // IP dialog 1st IP entry box - Signals: on_ip2_changed
    Gtk::Entry* ip3 = nullptr; // IP dialog 1st IP entry box - Signals: on_ip3_changed
    Gtk::Entry* ip4 = nullptr; // IP dialog 1st IP entry box - Signals: on_ip4_changed
    Gtk::Entry* port = nullptr; // IP dialog 1st IP entry box - Signals: on_port_changed
    Gtk::Builder* builderIP = Gtk::Builder::create();

}

int main()
{
    auto app = Gtk::Application::create(argc, argv, "chatclient");

    Gtk::Builder* builderMain = Gtk::Builder::create();

    try
    {
        refBuilder->add_from_file("chatclient.glade");
    }
    catch(const Glib::FileError& ex)
    {
        std::cerr << "FileError: " << ex.what() << std::endl;
        return 1;
    }
    catch(const Glib::MarkupError& ex)
    {
        std::cerr << "MarkupError: " << ex.what() << std::endl;
        return 1;
    }
    catch(const Gtk::BuilderError& ex)
    {
        std::cerr << "BuilderError: " << ex.what() << std::endl;
        return 1;
    }

    builderMain->get_widget("window", window);

    if (window)
    {
        Gtk::MenuItem* connect = nullptr; // Main window connect menuitem - Signals: on_connect_activate
        builderMain->get_widget("connect",connect);
        if(connect)
        {
            connect->signal_activate().connect( sigc::ptr_fun(showIPWindow))
        }
        Gtk::MenuItem* disconnect = nullptr; // Main window disconnect menuitem - Signals: on_connect_activate
        Gtk::MenuItem* quit = nullptr; // Main window quit menuitem - Signals: on_connect_activate
        Gtk::TextView* viewer = nullptr; // Main window text viewer - Attached to viewbuffer
        Gtk::TextBuffer* viewBuffer = nullptr; // View buffer for text viewer - Handler: viewbuffer_insert_text_cb
        Gtk::Entry* input = nullptr; // Main window chat input box - Signals: on_input_changed
        Gtk::TextBuffer* inputBuffer = nullptr; // View buffer for input chatbox - Handler: on_inputbuffer_inserted_text
        Gtk::Button* sendButton = nullptr; // Main window send button - Signals: on_send-button_clicked and on_send-button_enter

    }

    Gtk::Builder* builderIP = Gtk::Builder::create();


    string IPStr;
    string portNumStr;
    int portNum;
    string nickname;

    // Get IP connection info from user
    cout << "Enter IP for chat server connection (leave blank for default of 127.0.0.1): ";
    getline(cin, IPStr);

    if (IPStr == "")
        IPStr = "127.0.0.1";

    // Get port number info from user
    cout << "Enter port number for chat server connection (leave blank for default of 54000): ";
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

    do
    {
        //   Enter lines of text
        cout << nickname << " > ";
        getline(cin, userInput);

        //   Send to server
        int sendRes = send(socketListener, userInput.c_str(), userInput.size() + 1, 0);
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
