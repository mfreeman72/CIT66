#include <iostream>
#include <gtk/gtk.h>
#include <gtkmm.h>
#include <fstream>
#include <limits>
#include <ctime>
#include <sstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Define functions
string bdayGen(string, int);
string uAnimalID(string);
string animalName(string, string, int);
void menu();
void importArrivals();
void loadZoo();
void saveZoo();
void delZoo();
void registerNew();
void editAnimal();
void genZooHabitats();
void sortAnimals();
bool nameInArray(string);
string getAnimalNames(string);
void animalReport();
void clearScreen();
void header();

Gtk::Window* window;
Gtk::Window* registerWindow;
Gtk::Grid* grid1;
Gtk::Menu* filenew;
Gtk::Menu* fileopen;
Gtk::Menu* filesave;
Gtk::Menu* fileimport;
Gtk::Menu* filedelete;
Gtk::Menu* filequit;
Gtk::Menu* editedit;
Gtk::Menu* editdelete;
Gtk::Menu* editclear;
Gtk::Menu* helpabout;
Gtk::Label* hyena;
GtkWidget *hyena1;
GtkWidget *hyena2;
GtkWidget *hyena3;
GtkWidget *hyena4;
Gtk::Label* lion;
GtkWidget *lion1;
GtkWidget *lion2;
GtkWidget *lion3;
GtkWidget *lion4;
Gtk::Label* tiger;
GtkWidget *tiger1;
GtkWidget *tiger2;
GtkWidget *tiger3;
GtkWidget *tiger4;
Gtk::Label* bear;
GtkWidget *bear1;
GtkWidget *bear2;
GtkWidget *bear3;
GtkWidget *bear4;
GtkWidget *reportview;
Gtk::Label* message;
GtkWidget *speciesCombo;
GtkWidget *originEntry;
GtkWidget *nameEntry;
GtkWidget *sexCombo;
GtkWidget *weightSpin;
GtkWidget *colorEntry;
GtkWidget *ageSpin;
GtkWidget *seasonSpin;
GtkWidget *cancelRegister;
GtkWidget *acceptRegister;
Gtk::Builder* builder;

//Define global arrays
string zooArray[4][4]; // Four animals of four species can be alive in zoo
string animalType[4] = {"Hyena", "Lion", "Tiger", "Bear"};

// Define global variables
int menuEntry;
int animalCount;
int hyenaCount;
int lionCount;
int tigerCount;
int bearCount;

// Define zoo object class
class zoo
{
public:
    string species;
    string name;
    string sex;
    int weight;
    string color;
    string origin;
    string arrival;
    string id;
    int age;
    string season;
    string bday;
    bool isAlive;

    void info()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Sex: " << sex << endl;
        cout << "Age: " << age << endl;
        cout << "Approx. Birth Date: " << bday << endl;
        cout << "Origin: " << origin << endl;
        cout << "Arrived: " << arrival;
        cout << "Status: ";
        if (isAlive)
            cout << "Alive";
        else
            cout << "Deceased";
    }
};

// Set constant ZOOMAX to describe the maximum number of animals the zoo can hold
const int ZOOMAX = 100;

// Create zoo object array called "animals"
zoo animals[ZOOMAX];

// Main program
int main(int argc, char *argv[]) // Allow command-line arguments to be passed into main()
{
    gtk_init(&argc, &argv); // init Gtk

    // Establish contact with xml code used to adjust widget settings

    builder = create_from_file("cppZooUI.glade"); // Loads the Glade XML file from the Glade Gtk GUI builder application

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window")); // Makes the connection to the application window

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); // Causes the closed window to quit the program instead of just closing the window

    gtk_builder_connect_signals(builder, NULL); // Builds table of all callback functions to all GUI elements in your XML

    // Main window elements
    grid1 = GTK_WIDGET(gtk_builder_get_object(builder, "grid1"));
    filenew = GTK_WIDGET(gtk_builder_get_object(builder, "new"));
    fileopen = GTK_WIDGET(gtk_builder_get_object(builder, "open"));
    filesave = GTK_WIDGET(gtk_builder_get_object(builder, "save"));
    fileimport = GTK_WIDGET(gtk_builder_get_object(builder, "import"));
    filedelete = GTK_WIDGET(gtk_builder_get_object(builder, "delete"));
    filequit = GTK_WIDGET(gtk_builder_get_object(builder, "quit"));
    editedit = GTK_WIDGET(gtk_builder_get_object(builder, "edit"));
    editdelete = GTK_WIDGET(gtk_builder_get_object(builder, "deleteAnimal"));
    editclear = GTK_WIDGET(gtk_builder_get_object(builder, "clear"));
    helpabout = GTK_WIDGET(gtk_builder_get_object(builder, "about"));
    hyena = GTK_WIDGET(gtk_builder_get_object(builder, "hyena"));
    hyena1 = GTK_WIDGET(gtk_builder_get_object(builder, "hyena1"));
    hyena2 = GTK_WIDGET(gtk_builder_get_object(builder, "hyena2"));
    hyena3 = GTK_WIDGET(gtk_builder_get_object(builder, "hyena3"));
    hyena4 = GTK_WIDGET(gtk_builder_get_object(builder, "hyena4"));
    lion = GTK_WIDGET(gtk_builder_get_object(builder, "lion"));
    lion1 = GTK_WIDGET(gtk_builder_get_object(builder, "lion1"));
    lion2 = GTK_WIDGET(gtk_builder_get_object(builder, "lion2"));
    lion3 = GTK_WIDGET(gtk_builder_get_object(builder, "lion3"));
    lion4 = GTK_WIDGET(gtk_builder_get_object(builder, "lion4"));
    tiger = GTK_WIDGET(gtk_builder_get_object(builder, "tiger"));
    tiger1 = GTK_WIDGET(gtk_builder_get_object(builder, "tiger1"));
    tiger2 = GTK_WIDGET(gtk_builder_get_object(builder, "tiger2"));
    tiger3 = GTK_WIDGET(gtk_builder_get_object(builder, "tiger3"));
    tiger4 = GTK_WIDGET(gtk_builder_get_object(builder, "tiger4"));
    bear = GTK_WIDGET(gtk_builder_get_object(builder, "bear"));
    bear1 = GTK_WIDGET(gtk_builder_get_object(builder, "bear1"));
    bear2 = GTK_WIDGET(gtk_builder_get_object(builder, "bear2"));
    bear3 = GTK_WIDGET(gtk_builder_get_object(builder, "bear3"));
    bear4 = GTK_WIDGET(gtk_builder_get_object(builder, "bear4"));
    reportview = GTK_WIDGET(gtk_builder_get_object(builder, "reportview"));
    message = GTK_WIDGET(gtk_builder_get_object(builder, "message"));


    gtk_widget_show(window); // Cause the window to appear

    gtk_main(); // This will sit there and watch for events

    return EXIT_SUCCESS; // Exit when window closes

// Clear the screen and show "Zoo Manager" header and info
//
//    clearScreen();
//
//    // Loop back to zoo grid display and menu until quit menu option is selected
//    while(menuEntry != 9)
//    {
//        genZooHabitats();
//        menu();
//    }
//    return 0;
}

extern "C"
{
    void on_new_activate(GtkMenu *m)
    {
        // "Register" window elements
        registerWindow = GTK_WIDGET(gtk_builder_get_object(builder, "registerWindow"));

        speciesCombo = GTK_WIDGET(gtk_builder_get_object(builder, "speciesCombo"));
        originEntry = GTK_WIDGET(gtk_builder_get_object(builder, "originEntry"));
        nameEntry = GTK_WIDGET(gtk_builder_get_object(builder, "nameEntry"));
        sexCombo = GTK_WIDGET(gtk_builder_get_object(builder, "sexCombo"));
        weightSpin = GTK_WIDGET(gtk_builder_get_object(builder, "weightSpin"));
        colorEntry = GTK_WIDGET(gtk_builder_get_object(builder, "colorEntry"));
        ageSpin = GTK_WIDGET(gtk_builder_get_object(builder, "ageSpin"));
        seasonSpin = GTK_WIDGET(gtk_builder_get_object(builder, "seasonSpin"));
        cancelRegister = GTK_WIDGET(gtk_builder_get_object(builder, "cancelRegister"));
        acceptRegister = GTK_WIDGET(gtk_builder_get_object(builder, "acceptRegister"));

        gtk_label_set_text(GTK_LABEL(message), (const gchar*) "Registering new animal...");
        gtk_widget_show(registerWindow);
    }
    void on_open_activate(GtkMenu *m)
    {
        gtk_label_set_text(GTK_LABEL(message), (const gchar*) "Opening zoofile.txt...");
        loadZoo();
    }
    void on_save_activate(GtkMenu *m)
    {
        gtk_label_set_text(GTK_LABEL(message), (const gchar*) "Saving zoofile.txt...");
        saveZoo();
    }
    void on_import_activate(GtkMenu *m)
    {
        gtk_label_set_text(GTK_LABEL(message), (const gchar*) "Importing animals...");
    }
    void on_delete_activate(GtkMenu *m)
    {
        gtk_label_set_text(GTK_LABEL(message), (const gchar*) "Deleting zoofile.txt...");
        delZoo();
    }
    int on_quit_activate(GtkMenu *m)
    {
        gtk_label_set_text(GTK_LABEL(message), (const gchar*) "Quiting program...");
    }
    void on_edit_activate(GtkMenu *m)
    {
        gtk_label_set_text(GTK_LABEL(message), (const gchar*) "Editing animal...");
    }
    void on_deleteAnimal_activate(GtkMenu *m)
    {
        gtk_label_set_text(GTK_LABEL(message), (const gchar*) "Deleting animal...");
    }
    void on_clear_activate(GtkMenu *m)
    {
        gtk_label_set_text(GTK_LABEL(message), (const gchar*) "Clearing zoo...");
    }
    void on_about_activate(GtkMenu *m)
    {
        gtk_label_set_text(GTK_LABEL(message), (const gchar*) "Opening about dialog...");
    }
}

// Function to show "Zoo Manager" header and info
void header()
{
    cout << "Zoo Manager\n\n";
    cout << "You currently have 16 enclosures in current configuration: 4 habitats, each with 4 enclosures.\n";
    cout << "You may have up to " << ZOOMAX << " animal entries stored (including deceased animals), but you can only have 4 live entries of each species at any given time.\n";
}

// Function to clear the screen (adapted for various OS's) and re-display header -- taken from several online sources
void clearScreen()
{
    // Clear a Windows screen
    #ifdef _WIN32
        system("cls");
    #endif

    #ifdef _WIN64
        system("cls");
    #endif

    // Clear a MacOS screen
    #ifdef TARGET_OS_MAC
        system("clear");
    #endif

    // Clear a Linux screen
    #ifdef __linux__
        system("clear");
    #endif

    // Display header
    header();
}

// Function to load and return sample names for each animal species from the "animalNames.txt" file
string getAnimalNames(string animalSpecies)
{
    // Define local variables
    string myText = "";
    string animalNames[8];
    string hyenas[10];
    string lions[10];
    string tigers[10];
    string bears[10];
    int count = 0;

    // Open animalNames.txt
    ifstream MyFile("animalNames.txt");

    // Read animalNames.txt and place each line in "animals" array
    while (getline(MyFile, myText))
    {
        animalNames[count] = myText;
        count++;
    }

    // Close the file
    MyFile.close();

    // Parse the first 10 names from each line of the "animals" array
    for (int i=0; i<count + 1; i++)
    {
        // Define position and length variables
        int start;
        int comma;
        int length;

        // Check for the "Hyena Names:" header
        if (animalNames[i].find("Hyena Names:") != string::npos)
        {
            // Initial values for position and length of first name
            start = 0;
            comma = animalNames[i+1].find(",");
            length = comma;

            // Iterate through the first 10 names
            for (int j=0; j<10; j++)
            {
                // Place animal name starting at the position <start> and going through the next <length> number of charaters
                hyenas[j] = animalNames[i+1].substr(start,length);
                // Ignore the next comma and space to get the start position of the next name
                start = comma + 2;
                // Find the position of the next comma
                comma = animalNames[i+1].find(",", start);
                // Calculate the length of the word
                length = comma - start;
            }
        }
        // Check for the "Lion Names:" header
        if (animalNames[i].find("Lion Names:") != string::npos)
        {
            // Initial values for position and length of first name
            start = 0;
            comma = animalNames[i+1].find(",");
            length = comma;
            // Iterate through the first 10 names
            for (int j=0; j<10; j++)
            {
                // Place animal name starting at the position <start> and going through the next <length> number of charaters
                lions[j] = animalNames[i+1].substr(start,length);
                // Ignore the next comma and space to get the start position of the next name
                start = comma + 2;
                // Find the position of the next comma
                comma = animalNames[i+1].find(",", start);
                // Calculate the length of the word
                length = comma - start;
            }
        }
        // Check for the "Tiger names:" header
        if (animalNames[i].find("Tiger names:") != string::npos)
        {
            // Initial values for position and length of first name
            start = 0;
            comma = animalNames[i+1].find(",");
            length = comma;
            // Iterate through the first 10 names
            for (int j=0; j<10; j++)
            {
                // Place animal name starting at the position <start> and going through the next <length> number of charaters
                tigers[j] = animalNames[i+1].substr(start,length);
                // Ignore the next comma and space to get the start position of the next name
                start = comma + 2;
                // Find the position of the next comma
                comma = animalNames[i+1].find(",", start);
                // Calculate the length of the word
                length = comma - start;
            }
        }
        // Check for the "Bear Names:" header
        if (animalNames[i].find("Bear Names:") != string::npos)
        {
            // Initial values for position and length of first name
            start = 0;
            comma = animalNames[i+1].find(",");
            length = comma;
            // Iterate through the first 10 names
            for (int j=0; j<10; j++)
            {
                // Place animal name starting at the position <start> and going through the next <length> number of charaters
                bears[j] = animalNames[i+1].substr(start,length);
                // Ignore the next comma and space to get the start position of the next name
                start = comma + 2;
                // Find the position of the next comma
                comma = animalNames[i+1].find(",", start);
                // Calculate the length of the word
                length = comma - start;
            }
        }
    }

    // Return names for each species ONLY if not already used. Otherwise return "No suggestion"
    if (animalSpecies == "hyena")
    {
        for (int i=0; i<10; i++)
            if (!nameInArray(hyenas[i]))
                return hyenas[i];
    }
    if (animalSpecies == "lion")
    {
        for (int i=0; i<10; i++)
            if (!nameInArray(lions[i]))
                return lions[i];
    }
    if (animalSpecies == "tiger")
    {
        for (int i=0; i<10; i++)
            if (!nameInArray(tigers[i]))
                return tigers[i];
    }
    if (animalSpecies == "bear")
    {
        for (int i=0; i<10; i++)
            if (!nameInArray(bears[i]))
                return bears[i];
    }
    return "No suggestion";
}

// Function to find and return approx. birth date for given season
string bdayGen(string season, int age)
{
    // Get current time
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);

	// Initialize variable for how much to decrease the year by if before date below
	int decrease = 1;

	// Find approx. date for appropriate birth season
	if(season == "spring")
    {
        if ((timePtr->tm_mon == 2 && timePtr->tm_mday >= 21) || timePtr->tm_mon > 2)
                decrease = 0;
        return "March 21, " + to_string(timePtr->tm_year + 1900 - age - decrease);;
    }
	else if(season == "summer")
    {
        if ((timePtr->tm_mon == 5) && (timePtr->tm_mday >= 21) || timePtr->tm_mon > 5)
                decrease = 0;
        return "June 21, " + to_string(timePtr->tm_year + 1900 - age - decrease);;
    }
	else if(season == "fall")
    {
        if ((timePtr->tm_mon == 8) && (timePtr->tm_mday >= 21) || timePtr->tm_mon > 8)
                decrease = 0;
        return "September 21, " + to_string(timePtr->tm_year + 1900 - age - decrease);;
    }
	else if(season == "winter")
    {
        if ((timePtr->tm_mon == 11) && (timePtr->tm_mday >= 21) || timePtr->tm_mon > 11)
                decrease = 0;
        return "December 21, " + to_string(timePtr->tm_year + 1900 - age - decrease);;
    }
    else
        return "January 1, " + to_string(timePtr->tm_year + 1900 - age);;
}

// Function to find a unique ID, depending on species and number of animals of that species in list
string uAnimalID(string species)
{
    // Add first two letters of species to the beginning of ID
    string ID = species.substr(0,2);

    // For each species, add a number to ID
    if (species == "hyena")
    {
        // If there are fewer than 10 animals of given species, add a leading zero
        if(hyenaCount < 10)
            ID += "0";
        ID += to_string(hyenaCount);
        // Since we're adding a new animal, increase the count
        hyenaCount++;
    }
    if (species == "lion")
    {
        if(lionCount < 10)
            ID += "0";
        ID+= to_string(lionCount);
        lionCount++;
    }
    if (species == "tiger")
    {
        if(tigerCount < 10)
            ID += "0";
        ID+= to_string(tigerCount);
        tigerCount++;
    }
    if (species == "bear")
    {
        if(bearCount < 10)
            ID += "0";
        ID+= to_string(bearCount);
        bearCount++;
    }

    return ID;
}

// Function to find out if a name or ID has already been assigned to an animal
bool nameInArray(string name)
{
    for (int i = 0; i < ZOOMAX; i++)
        if ((animals[i].name == name) || (animals[i].id == name))
            return true;
    return false;
}

// Function to display the menu and get user selection
void menu()
{
    cout << "\n\nMenu Options:\n\n";
    cout << "1. Register new animals\n";
    cout << "2. Edit/delete animal entry information\n";
    cout << "3. Display current zoo enclosure data\n";
    cout << "4. Print full zoo report\n";
    cout << "5. Import zoo data from arrivingAnimals.txt file\n";
    cout << "6. Save zoo data to zooFile.txt file\n";
    cout << "7. Load zoo data from zooFile.txt file\n";
    cout << "8. Delete zooFile.txt file\n";
    cout << "9. Quit\n\n";
    cout << "Please enter your menu choice: ";

    try
    {
        cin >> menuEntry;
        switch(menuEntry)
        {
        case 1:
            registerNew();
            break;
        case 2:
            editAnimal();
            break;
        case 3:
            clearScreen();
            break;
        case 4:
            animalReport();
            break;
        case 5:
            importArrivals();
            break;
        case 6:
            saveZoo();
            break;
        case 7:
            loadZoo();
            break;
        case 8:
            delZoo();
            break;
        case 9:
            break;
        default:
            throw string("Invalid Entry");
            break;
        }
    }
    catch(string e)
    {
        cout << "\n\n" << e << "\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Function to register a new animal into the zoo
void registerNew()
{
    // Define local variables
    string season;
    string species;
    string tempInput;

    // Get current time
    time_t now = time(NULL);
    char* currentTime = ctime(&now);

    // Clear the screen
    clearScreen();

    cout << "\nEnter the following information for the new animal:\n";

    // Loop until a supported species is entered
    while ((species != "hyena") && (species != "lion") && (species != "tiger") && (species != "bear"))
    {
        cout << "\nSpecies (hyena/lion/tiger/bear): ";
        cin >> species;
    }

    // Check if all zoo enclosures for given species are full and report that to user and exit this function
    if (((species == "hyena") && (zooArray[0][3] != "")) || ((species == "lion") && (zooArray[1][3] != "")) || ((species == "tiger") && (zooArray[2][3] != "")) ||((species == "bear") && (zooArray[3][3] != "")))
        {
            clearScreen();
            cout << "\nAll " << species << " enclosures are full. We cannot add a new " << species << " to the zoo.\n";
            return;
        }

    // Assign entered species to current array location
    animals[animalCount].species = species;

    // Get country and/or city of origin for animal's birthplace
    cout << "\nCity and/or country of origin: ";
    cin.ignore();
    getline(cin, animals[animalCount].origin);

    // Get a suggestion for an animal name
    string suggest = getAnimalNames(animals[animalCount].species);

    // Get name from user, or assign the suggested name if no name is entered
    cout << "\nName (Leave empty for suggested name: " << suggest << "): ";
    getline(cin, tempInput);
    if (!tempInput.empty())
        animals[animalCount].name = tempInput;
    else
        animals[animalCount].name = suggest;

    // Get sex of animal, loop until either "male" or "female" is entered
    while ((animals[animalCount].sex != "male") && (animals[animalCount].sex != "female"))
    {
        cout << "\nSex (male/female): ";
        cin >> animals[animalCount].sex;
    }

    // Get the weight of the animal
    cout << "\nWeight in pounds: ";
    cin >> animals[animalCount].weight;

    // Get the color of the animal
    cout << "\nColor: ";
    cin.ignore();
    getline(cin, animals[animalCount].color);

    // Get the age of the animal
    cout << "\nAge: ";
    cin >> animals[animalCount].age;

    // Get the season the animal was born in, looping until an acceptable response is given
    while ((animals[animalCount].season != "spring") && (animals[animalCount].season != "summer") &&(animals[animalCount].season != "fall") && (animals[animalCount].season != "winter") && (animals[animalCount].season != "unknown"))
    {
        cout << "\nSeason born in (spring/summer/winter/fall or unknown): ";
        cin >> animals[animalCount].season;
    }

    // Get the approx. birth date
    animals[animalCount].bday = bdayGen(animals[animalCount].season, animals[animalCount].age);

    // Set arrival date to current date
    animals[animalCount].arrival = currentTime;

    // Get a unique ID for animal
    animals[animalCount].id = uAnimalID(animals[animalCount].species);

    // Assume any new animals are alive
    animals[animalCount].isAlive = true;

    // Clear the screen and display the full info for the new animal
    clearScreen();
    cout << "\nHere is your new " << animals[animalCount].species << ":\n\n";
    animals[animalCount].info();
    animalCount++;
}

// Function to edit/delete an existing animal entry
void editAnimal()
{
    // Define local temp variables
    string nameID;
    string sex;
    string name;
    string ageString;
    int age;
    string alive;
    string season;
    string delAnimal;
    string confirmDelete;

    // Clear the screen
    clearScreen();

    // Get animal's name or ID to know which info to edit/delete
    cout << "\nEnter the animal's name or ID you want to edit: ";
    cin >> nameID;

    // Check if name or ID exists in array - if not, report that to user and return to menu
    if (!nameInArray(nameID))
    {
        clearScreen();
        cout << "\nName or ID not found!";
        return;
    }

    // Find the animal name or ID in the array and begin editing info
    for (int i=0; i<ZOOMAX; i++)
    {
        if ((animals[i].id == nameID) || (animals[i].name == nameID))
        {
            // Delete the animal?
            cout << "\nDo you wish to delete this animal entry (yes/no)? ";

            // Check for appropriate response
            while ((delAnimal != "yes") && (delAnimal != "no"))
            {
                cin >> delAnimal;

                // Confirm deletion
                if (delAnimal == "yes")

                    // Check for appropriate response
                    while ((confirmDelete != "yes") && (confirmDelete != "no"))
                    {
                        cout << "\nAre you sure you want this animal entry permanantly deleted (yes/no)? ";
                        cin >> confirmDelete;

                        // If confirmed, move all entries after deleted animal's array position, overwriting the deleted animal's entry with the next animal
                        if (confirmDelete == "yes")
                        {
                            for (int j=i; j<ZOOMAX-1; j++)
                            {
                                animals[j].species = animals[j+1].species;
                                animals[j].name = animals[j+1].name;
                                animals[j].sex = animals[j+1].sex;
                                animals[j].weight = animals[j+1].weight;
                                animals[j].color = animals[j+1].color;
                                animals[j].origin = animals[j+1].origin;
                                animals[j].id = animals[j+1].id;
                                animals[j].age = animals[j+1].age;
                                animals[j].season = animals[j+1].season;
                                animals[j].bday = animals[j+1].bday;
                                animals[j].isAlive = animals[j+1].isAlive;
                            }

                            // Sort the enclosure list
                            sortAnimals();
                            return;
                        }
                    }
            }

            // Edit dead/alive status?

            // Check for appropriate response
            while ((alive != "yes")  && alive != "no")
            {
                cout << "\nIs this " << animals[i].species << " still alive (yes/no)? ";
                cin >> alive;

                // Assign the new dead/alive status
                if (alive == "yes")
                    animals[i].isAlive = true;
                if (alive == "no")
                    animals[i].isAlive = false;
            }

            cout << "\nEdit the following information (press Enter to keep current value): ";
            // Ignore any previous cin data to make getline work correctly
            cin.ignore();

            // Check for appropriate response
            while ((sex != "male") && (sex != "female"))
            {
                // Edit animal's sex?
                cout << "\nSex (male/female -- currently: " << animals[i].sex << "): ";
                getline(cin, sex);

                // Assign new value if changed
                if (!sex.empty())
                    animals[i].sex = sex;
                else
                    sex = animals[i].sex;
            }

            // Edit animal's name?
            cout << "\nName (currently: " << animals[i].name << "): ";
            getline(cin, name);

            // Assign new value if changed
            if (!name.empty())
                animals[i].name = name;

            // Edit animal's age?
            cout << "\nAge: (currently: " << animals[i].age << "): ";
            getline(cin, ageString);

            // Assign new value if changed
            if (!ageString.empty()) // The string "ageString" is used because .emtpy() requires a string to function
            {
                // Convert ageString data to an int and pass to variable "age"
                istringstream stream(ageString);
                stream >> age;
                animals[i].age = age;
            }

            // Check for appropriate response
            while ((season != "spring") && (season != "summer") &&(season != "fall") && (season != "winter") && (season != "unknown"))
            {
                // Edit animal's season?
                cout << "\nSeason born in (spring/summer/winter/fall or unknown -- currently: " << animals[i].season << "): ";
                getline(cin, season);

                // Assign new value if changed
                if (!season.empty())
                {
                    animals[i].season = season;

                    // Change birth date to match new season
                    animals[i].bday = bdayGen(animals[i].season, animals[i].age);
                }
                else
                    season = animals[i].season;
            }

            // Clear the screen
            clearScreen();

            // Display full updated animal info
            cout << "\nHere is your updated animal:\n\n";
            animals[i].info();
        }
    }
}

//Function to sort animals into enclosures
void sortAnimals()
{
    int hyenas = 0;
    int lions = 0;
    int tigers = 0;
    int bears = 0;

    // Clear the enclosure array in case any animals have been deleted
    for (int x=0; x<4; x++)
        for (int y=0; y<4; y++)
            zooArray[x][y] = "";

    // Iterate through zoo objects and place animals in appropriate enclosure, only if they are listed as alive
    for (int i=0; i<ZOOMAX; i++)
    {
        if ((animals[i].species == "hyena") && (animals[i].isAlive))
        {
            zooArray[0][hyenas] = animals[i].name;
            hyenas++;
        }
        if ((animals[i].species == "lion") && (animals[i].isAlive))
        {
            zooArray[1][lions] = animals[i].name;
            lions++;
        }
        if ((animals[i].species == "tiger") && (animals[i].isAlive))
        {
            zooArray[2][tigers] = animals[i].name;
            tigers++;
        }
        if ((animals[i].species == "bear") && (animals[i].isAlive))
        {
            zooArray[3][bears] = animals[i].name;
            bears++;
        }
    }
}

// Function to display the enclosure grid
void genZooHabitats()
{
    // Sort the animals into their enclosures
    sortAnimals();
    gtk_label_set_text(GTK_LABEL(message), (const gchar*) "Creating Zoo Habitats...");
//    gtk_label_set_text(GTK_LABEL(hyena1), (const gchar*) zooArray[0][0]);
//    gtk_label_set_text(GTK_LABEL(hyena2), (const gchar*) zooArray[0][1]);
//    gtk_label_set_text(GTK_LABEL(hyena3), (const gchar*) zooArray[0][2]);
//    gtk_label_set_text(GTK_LABEL(hyena4), (const gchar*) zooArray[0][3]);
//    gtk_label_set_text(GTK_LABEL(lion1), (const gchar*) zooArray[1][0]);
//    gtk_label_set_text(GTK_LABEL(lion2), (const gchar*) zooArray[1][1]);
//    gtk_label_set_text(GTK_LABEL(lion3), (const gchar*) zooArray[1][2]);
//    gtk_label_set_text(GTK_LABEL(lion4), (const gchar*) zooArray[1][3]);
//    gtk_label_set_text(GTK_LABEL(tiger1), (const gchar*) zooArray[2][0]);
//    gtk_label_set_text(GTK_LABEL(tiger2), (const gchar*) zooArray[2][1]);
//    gtk_label_set_text(GTK_LABEL(tiger3), (const gchar*) zooArray[2][2]);
//    gtk_label_set_text(GTK_LABEL(tiger4), (const gchar*) zooArray[2][3]);
//    gtk_label_set_text(GTK_LABEL(bear1), (const gchar*) zooArray[3][0]);
//    gtk_label_set_text(GTK_LABEL(bear2), (const gchar*) zooArray[3][1]);
//    gtk_label_set_text(GTK_LABEL(bear3), (const gchar*) zooArray[3][2]);
//    gtk_label_set_text(GTK_LABEL(bear4), (const gchar*) zooArray[3][3]);
}

// Display a full animal report for the entire zoo population, including deceased animals
void animalReport()
{
    string tempType;
    clearScreen();

    cout << "Full Animal Report\n\n";

    for (int i=0; i<4; i++)
    {
        cout << ">>>>>>>>>>>>>   " << animalType[i] << "s:   <<<<<<<<<<<<<\n\n";

        tempType = animalType[i];
        transform(tempType.begin(),tempType.end(),tempType.begin(),::tolower);
        for(int j=0; j<ZOOMAX; j++)
        {
            if (animals[j].species == tempType)
            {
                animals[j].info();
                cout << "\n\n";
            }
        }
    }
}

// Import arriving animal information from the arrivingAnimals.txt file
void importArrivals()
{
    // Define temp variable and array
    string animalInput;
    string tempAnimals[ZOOMAX];
    string confirm;

    // Get current time
    time_t now = time(NULL);
    char* currentTime = ctime(&now);

    // Clear the screen
    clearScreen();

    // Confirm importing
    while ((confirm != "yes") && (confirm != "no"))
    {
        cout << "\nFor now, importing will erase any existing zoo data from memory. Are you sure you want to do this (yes/no)? ";
        cin >> confirm;
        if (confirm == "no")
            return;
    }

    try
    {
        // Create a text stream, used to output the text file
        ifstream myFile("arrivingAnimals.txt");

        // Inform user that file is being loaded in
        cout << "\nImporting animal information...\n";

        int counter = 0;

        // Clear the entire zoo before loading new animal list
        for (int i=0; i<ZOOMAX; i++)
        {
            animals[i].species = "";
            animals[i].name = "";
            animals[i].sex = "";
            animals[i].weight = 0;
            animals[i].color = "";
            animals[i].origin = "";
            animals[i].id = "";
            animals[i].age = 0;
            animals[i].season = "";
            animals[i].bday = "";
            animals[i].isAlive = true;
        }
        animalCount = 0;
        hyenaCount = 0;
        lionCount = 0;
        tigerCount = 0;
        bearCount = 0;

        // Read the file line by line
        while(getline(myFile,animalInput))
        {
            tempAnimals[counter] = animalInput;
            counter++;
        }

        // Close the file
        myFile.close();

        // Create a temporary array to arrange the loaded information
        string tempArray[11];
        cin.ignore();

        // Iterate through loaded data lines
        for (int i=0; i<counter; i++)
        {
            // Parse data from each line of the file

            cout << "\nImporting " << tempAnimals[i] << endl;

            // Find animal's age
            int start;
            int pointer = tempAnimals[i].find(" ",1);
            animals[i].age = stoi(tempAnimals[i].substr(0, pointer));

            // Find animal's sex
            start = tempAnimals[i].find("old",1) + 4;
            pointer = tempAnimals[i].find(" ",start);
            animals[i].sex = tempAnimals[i].substr(start, pointer - start);

            // Find animal's species
            start = pointer + 1;
            pointer = tempAnimals[i].find(",",start);
            animals[i].species = tempAnimals[i].substr(start, pointer - start);

            if (tempAnimals[i].find("born in",start) < 30)
            {
                start = tempAnimals[i].find("in", pointer + 1) + 3;
                pointer = tempAnimals[i].find(" ",start) - 1;
                animals[i].season = tempAnimals[i].substr(start,pointer - start);
            }
            else
            {
                animals[i].season = "unknown";
            }

            // Find animal's color
            start = pointer + 1;
            pointer = tempAnimals[i].find("color",start) - 1;
            animals[i].color = tempAnimals[i].substr(start, pointer - start);

            // Find animal's weight
            start = pointer + 8;
            pointer = tempAnimals[i].find(" ",start);
            animals[i].weight = stoi(tempAnimals[i].substr(start, pointer - start));

            // Find animal's zoo of origin
            start = pointer + 14;
            animals[i].origin = tempAnimals[i].substr(start,string::npos);

            // Get a suggestion for an animal name
            string suggest = getAnimalNames(animals[i].species);

            // Get name from user, or assign the suggested name if no name is entered
            string tempInput;
            cout << "\nName this " << animals[i].species << " (Leave empty for suggested name: " << suggest << "): ";
            getline(cin, tempInput);
            if (!tempInput.empty())
                animals[i].name = tempInput;
            else
                animals[i].name = suggest;

            // Get the approx. birth date
            animals[i].bday = bdayGen(animals[i].season, animals[i].age);

            // Get a unique ID for animal
            animals[i].id = uAnimalID(animals[i].species);

            // Set arrival date to current date
            animals[i].arrival = currentTime;

            // Set alive status to true
            animals[i].isAlive = true;
            animalCount++;
        }
    }

    // Catch any load errors
    catch (...)
    {
        cout << "\nException caught! \n";
    }
}

// Load zoo information from the assigned save file
void loadZoo()
{
    // Define temp variable and array
    string animalInput;
    string tempAnimals[ZOOMAX];

    // Clear the screen
    clearScreen();

    try
    {
        // Create a text stream, used to output the text file
        ifstream myFile("zooFile.txt");

        // Inform user that file is being loaded in
        cout << "\nLoading file...\n";

        int counter = 0;

        // Clear the entire zoo before loading new animal list
        for (int i=0; i<ZOOMAX; i++)
        {
            animals[i].species = "";
            animals[i].name = "";
            animals[i].sex = "";
            animals[i].weight = 0;
            animals[i].color = "";
            animals[i].origin = "";
            animals[i].id = "";
            animals[i].age = 0;
            animals[i].season = "";
            animals[i].bday = "";
            animals[i].isAlive = true;
        }
        animalCount = 0;
        hyenaCount = 0;
        lionCount = 0;
        tigerCount = 0;
        bearCount = 0;

        // Read the file line by line
        while(getline(myFile,animalInput))
        {
            tempAnimals[counter] = animalInput;
            counter++;
        }

        // Close the file
        myFile.close();

        // Create a temporary array to arrange the loaded information
        string tempArray[11];

        // Iterate through loaded data lines
        for (int i=0; i<counter; i++)
        {
            // Find each piece of animal data between each semicolon
            int start = 0;
            int semicolon = tempAnimals[i].find(";",1);

            for (int j=0; j<11; j++)
            {
                tempArray[j] = tempAnimals[i].substr(start,semicolon - start);
                start = semicolon + 1;
                semicolon = tempAnimals[i].find(";",start);
            }

            // Place each piece of animal data into an animal object
            animals[i].species = tempArray[0];
            animals[i].name = tempArray[1];
            animals[i].sex = tempArray[2];
            animals[i].weight = stoi(tempArray[3]);
            animals[i].color = tempArray[4];
            animals[i].origin = tempArray[5];
            animals[i].id = tempArray[6];
            animals[i].age = stoi(tempArray[7]);
            animals[i].season = tempArray[8];
            animals[i].bday = tempArray[9];
            if (tempArray[10] == "1")
                animals[i].isAlive = true;
            else
                animals[i].isAlive = false;
            animalCount++;
            if (animals[i].species == "hyena")
                hyenaCount++;
            if (animals[i].species == "lion")
                lionCount++;
            if (animals[i].species == "tiger")
                tigerCount++;
            if (animals[i].species == "bear")
                bearCount++;
        }
        genZooHabitats();
    }

    // Catch any load errors
    catch (...)
    {
        cout << "\nException caught! \n";
    }
}

// Function to save current zoo to the assigned save file
void saveZoo()
{
    // Clear the screen
    clearScreen();

    // Inform the user that the data is being saved
    cout << "\nSaving zoo data...\n";
    try
    {
        // Open the output stream to send file data to
        ofstream myFile("zooFile.txt");

        // Iterate through all zoo objects
        for (int i=0; i<ZOOMAX; i++)
            // Write any non-empty zoo objects to the file, separated by semicolons
            if (!animals[i].name.empty())
            {
                myFile << animals[i].species << ";"
                       << animals[i].name << ";"
                       << animals[i].sex << ";"
                       << animals[i].weight << ";"
                       << animals[i].color << ";"
                       << animals[i].origin << ";"
                       << animals[i].id << ";"
                       << animals[i].age << ";"
                       << animals[i].season << ";"
                       << animals[i].bday << ";"
                       << animals[i].isAlive << "\n";
            }

        // Close the file
        myFile.close();
    }

    // Catch any save errors
    catch (...)
    {
        cout << "\nException caught! \n";
    }
}

// Delete the save file
void delZoo()
{
    // Clear the screen
    clearScreen();

    // Report to the user whether or not the file was able to be deleted successfully
    if(remove( "zooFile.txt" ) != 0)
        cout << "\nError deleting file\n";
    else
        cout << "\nFile successfully deleted\n";
}
