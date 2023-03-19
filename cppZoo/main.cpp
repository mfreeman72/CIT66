#include <iostream>
#include <fstream>
#include <limits>
#include <ctime>
#include <sstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Define zoo object class
class Zoo
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
    Zoo* next;

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
void sortAnimals(Zoo*);
bool nameInArray(string);
string getAnimalNames(string);
void animalReport();
void clearScreen();
void clearZoo();
void header();


//Define global arrays
string zooArray[4][4]; // Four animals of four species can be alive in zoo
string animalType[4] = {"Hyena", "Lion", "Tiger", "Bear"};

// Define global variables
int menuEntry;
int hyenaCount;
int lionCount;
int tigerCount;
int bearCount;

// Initialize linked list
Zoo* head = new Zoo();
Zoo* tail = head;

// Main program
int main()
{
    // Clear the screen and show "Zoo Manager" header and info
    clearScreen();

    // Loop back to zoo grid display and menu until quit menu option is selected
    while(menuEntry != 10)
    {
        genZooHabitats();
        menu();
    }
    return 0;
}

// Function to show "Zoo Manager" header and info
void header()
{
    cout << "Zoo Manager\n\n";
    cout << "You currently have 16 enclosures in current configuration: 4 habitats, each with 4 enclosures.\n";
    cout << "Living animals will be automatically assigned enclosures on a first-come, first-serve basis.\n";
    cout << "You may only have 4 live entries of each species at any given time stored in the zoo manager data,\n";
    cout << "but you can only have unlimited numbers of deceased animals' data stored.\n";
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
    Zoo* n = head;
    while(n != NULL)
    {
        if ((n->name == name) || (n->id == name))
            return true;
        n = n->next;
    }
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
    cout << "5. Clear all animals from zoo\n";
    cout << "6. Import zoo data from arrivingAnimals.txt file\n";
    cout << "7. Save zoo data to zooFile.txt file\n";
    cout << "8. Load zoo data from zooFile.txt file\n";
    cout << "9. Delete zooFile.txt file\n";
    cout << "10. Quit\n\n";
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
            clearZoo();
            break;
        case 6:
            importArrivals();
            break;
        case 7:
            saveZoo();
            break;
        case 8:
            loadZoo();
            break;
        case 9:
            delZoo();
            break;
        case 10:
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
    // Get current time
    time_t now = time(NULL);
    char* currentTime = ctime(&now);

    // Clear the screen
    clearScreen();

    cout << "\nEnter the following information for the new animal:\n";

    // Loop until a supported species is entered
    while ((tail->species != "hyena") && (tail->species != "lion") && (tail->species != "tiger") && (tail->species != "bear"))
    {
        cout << "\nSpecies (hyena/lion/tiger/bear): ";
        cin >> tail->species;
    }

    // Check if all zoo enclosures for given species are full and report that to user and exit this function
    if (((tail->species == "hyena") && (zooArray[0][3] != "")) || ((tail->species == "lion") && (zooArray[1][3] != "")) || ((tail->species == "tiger") && (zooArray[2][3] != "")) ||((tail->species == "bear") && (zooArray[3][3] != "")))
        {
            clearScreen();
            cout << "\nAll " << tail->species << " enclosures are full. We cannot add a new " << tail->species << " to the zoo.\n";
            return;
        }

    // Get country and/or city of origin for animal's birthplace
    cout << "\nCity and/or country of origin: ";
    cin.ignore();
    getline(cin, tail->origin);

    // Get a suggestion for an animal name
    string suggest = getAnimalNames(tail->species);

    // Get name from user, or assign the suggested name if no name is entered
    cout << "\nName (Leave empty for suggested name: " << suggest << "): ";
    getline(cin, tail->name);
    if (tail->name.empty())
        tail->name = suggest;

    // Get sex of animal, loop until either "male" or "female" is entered
    while ((tail->sex != "male") && (tail->sex != "female"))
    {
        cout << "\nSex (male/female): ";
        cin >> tail->sex;
    }

    // Get the weight of the animal
    cout << "\nWeight in pounds: ";
    cin >> tail->weight;

    // Get the color of the animal
    cout << "\nColor: ";
    cin.ignore();
    getline(cin, tail->color);

    // Get the age of the animal
    cout << "\nAge: ";
    cin >> tail->age;

    // Get the season the animal was born in, looping until an acceptable response is given
    while ((tail->season != "spring") && (tail->season != "summer") &&(tail->season != "fall") && (tail->season != "winter") && (tail->season != "unknown"))
    {
        cout << "\nSeason born in (spring/summer/winter/fall or unknown): ";
        cin >> tail->season;
    }

    // Get the approx. birth date
    tail->bday = bdayGen(tail->season, tail->age);

    // Set arrival date to current date
    tail->arrival = currentTime;

    // Get a unique ID for animal
    tail->id = uAnimalID(tail->species);

    // Assume any new animals are alive
    tail->isAlive = true;


    // Clear the screen and display the full info for the new animal
    clearScreen();
    cout << "\nHere is your new " << tail->species << ":\n\n";
    tail->info();

    // Generate new tail node and advance tail pointer
    Zoo* newAnimal = new Zoo();
    tail->next = newAnimal;
    tail = newAnimal;
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
    cout << "\n(Name found)" << endl;
    Zoo* n = head;
    Zoo* prev = n;
    // Find the animal name or ID in the array and begin editing info
    while (n != NULL)
    {
        cout << "\n(Looking for animal in linked list)" << endl;
        if ((n->id == nameID) || (n->name == nameID))
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
                            if (n == head)
                            {
                                head == head->next;
                                delete n;
                            }
                            else
                            {
                                prev->next = n->next;
                                delete n;
                            }

                            // Sort the enclosure list
                            sortAnimals(head);
                            return;
                        }
                    }
            }

            // Edit dead/alive status?

            // Check for appropriate response
            while ((alive != "yes")  && alive != "no")
            {
                cout << "\nIs this " << n->species << " still alive (yes/no)? ";
                cin >> alive;

                // Assign the new dead/alive status
                if (alive == "yes")
                    n->isAlive = true;
                if (alive == "no")
                    n->isAlive = false;
            }

            cout << "\nEdit the following information (press Enter to keep current value): ";

            // Ignore any previous cin data to make getline work correctly
            cin.ignore();

            // Check for appropriate response
            while ((sex != "male") && (sex != "female"))
            {
                // Edit animal's sex?
                cout << "\nSex (male/female -- currently: " << n->sex << "): ";
                getline(cin, sex);

                // Assign new value if changed
                if (!sex.empty())
                    n->sex = sex;
                else
                    sex = n->sex;
            }

            // Edit animal's name?
            cout << "\nName (currently: " << n->name << "): ";
            getline(cin, name);

            // Assign new value if changed
            if (!name.empty())
                n->name = name;

            // Edit animal's age?
            cout << "\nAge: (currently: " << n->age << "): ";
            getline(cin, ageString);

            // Assign new value if changed
            if (!ageString.empty()) // The string "ageString" is used because .emtpy() requires a string to function
            {
                // Convert ageString data to an int and pass to variable "age"
                istringstream stream(ageString);
                stream >> age;
                n->age = age;
            }

            // Check for appropriate response
            while ((season != "spring") && (season != "summer") &&(season != "fall") && (season != "winter") && (season != "unknown"))
            {
                // Edit animal's season?
                cout << "\nSeason born in (spring/summer/winter/fall or unknown -- currently: " << n->season << "): ";
                getline(cin, season);

                // Assign new value if changed
                if (!season.empty())
                {
                    n->season = season;

                    // Change birth date to match new season
                    n->bday = bdayGen(n->season, n->age);
                }
                else
                    season = n->season;
            }

            // Clear the screen
            clearScreen();

            // Display full updated animal info
            cout << "\nHere is your updated animal:\n\n";
            n->info();
        }
        prev = n;
        n = n->next;
    }
}

//Function to sort animals into enclosures
void sortAnimals(Zoo* n)
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
    while(n != NULL)
    {
        if ((n->species == "hyena") && (n->isAlive) && (hyenas < 4))
        {
            zooArray[0][hyenas] = n->name;
            hyenas++;
        }
        if ((n->species == "lion") && (n->isAlive) && (lions < 4))
        {
            zooArray[1][lions] = n->name;
            lions++;
        }
        if ((n->species == "tiger") && (n->isAlive) && (tigers < 4))
        {
            zooArray[2][tigers] = n->name;
            tigers++;
        }
        if ((n->species == "bear") && (n->isAlive) && (bears < 4))
        {
            zooArray[3][bears] = n->name;
            bears++;
        }
        n = n->next;
    }
}

// Function to display the enclosure grid
void genZooHabitats()
{
    // Sort the animals into their enclosures
    sortAnimals(head);

    // Table Header
    cout << "\n\nCurrent zoo enclosures:\n\n";

    // Column labels
    cout << "\t| 1\t\t| 2\t\t| 3\t\t| 4\t\t|\n";
    for(int i=0; i<4; i++)
    {
        // Row separator
        cout << "--------+---------------+---------------+---------------+---------------+\n";
        // Row label
        cout << animalType[i] << "s\t| ";
        // Loop through array to fill in each cell in grid
        for(int j=0; j<4; j++)
        {
            cout << zooArray[i][j] << "\t";
            if(zooArray[i][j].length() <= 5)
                   cout << "\t";
            cout << "| ";
        }
        cout << endl;
    }
    cout << "--------+---------------+---------------+---------------+---------------+\n";
}

// Display a full animal report for the entire zoo population, including deceased animals
void animalReport()
{
    string tempType;
    clearScreen();
    Zoo* n;
    cout << "Full Animal Report\n\n";

    for (int i=0; i<4; i++)
    {
        cout << ">>>>>>>>>>>>>   " << animalType[i] << "s:   <<<<<<<<<<<<<\n\n";

        tempType = animalType[i];
        transform(tempType.begin(),tempType.end(),tempType.begin(),::tolower);
        n = head;
        while (n != NULL)
        {
            if (n->species == tempType)
            {
                n->info();
                cout << "\n\n";
            }
            n = n->next;
        }
    }
}

// Import arriving animal information from the arrivingAnimals.txt file
void importArrivals()
{
    // Define temp variable and array
    string animalInput;
    string tempAnimals[100];
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
        clearZoo();

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
            tail->age = stoi(tempAnimals[i].substr(0, pointer));

            // Find animal's sex
            start = tempAnimals[i].find("old",1) + 4;
            pointer = tempAnimals[i].find(" ",start);
            tail->sex = tempAnimals[i].substr(start, pointer - start);

            // Find animal's species
            start = pointer + 1;
            pointer = tempAnimals[i].find(",",start);
            tail->species = tempAnimals[i].substr(start, pointer - start);

            if (tempAnimals[i].find("born in",start) < 30)
            {
                start = tempAnimals[i].find("in", pointer + 1) + 3;
                pointer = tempAnimals[i].find(" ",start) - 1;
                tail->season = tempAnimals[i].substr(start,pointer - start);
            }
            else
            {
                tail->season = "unknown";
            }

            // Find animal's color
            start = pointer + 1;
            pointer = tempAnimals[i].find("color",start) - 1;
            tail->color = tempAnimals[i].substr(start, pointer - start);

            // Find animal's weight
            start = pointer + 8;
            pointer = tempAnimals[i].find(" ",start);
            tail->weight = stoi(tempAnimals[i].substr(start, pointer - start));

            // Find animal's zoo of origin
            start = pointer + 14;
            tail->origin = tempAnimals[i].substr(start,string::npos);

            // Get a suggestion for an animal name
            string suggest = getAnimalNames(tail->species);

            // Get name from user, or assign the suggested name if no name is entered
            string tempInput;
            cout << "\nName this " << tail->species << " (Leave empty for suggested name: " << suggest << "): ";
            getline(cin, tail->name);
            if (tail->name.empty())
                tail->name = suggest;

            // Get the approx. birth date
            tail->bday = bdayGen(tail->season, tail->age);

            // Get a unique ID for animal
            tail->id = uAnimalID(tail->species);

            // Set arrival date to current date
            tail->arrival = currentTime;

            // Set alive status to true
            tail->isAlive = true;

            // Generate new tail node and advance tail pointer
            Zoo* newAnimal = new Zoo();
            tail->next = newAnimal;
            tail = newAnimal;
        }
    }

    // Catch any load errors
    catch (...)
    {
        cout << "\nException caught! \n";
    }
}

void clearZoo()
{
    Zoo* n = head;
    Zoo* nxtptr;
    // Iterante through and delete each tail node until head is reached
    cout << "\nClearing zoo data..." << endl;
    while (n != NULL)
    {
        nxtptr = n->next;
        delete n;
        n = nxtptr;
    }
    head = new Zoo();
    tail = head;

    hyenaCount = 0;
    lionCount = 0;
    tigerCount = 0;
    bearCount = 0;
}

// Load zoo information from the assigned save file
void loadZoo()
{
    // Define temp variable and array
    string animalInput;
    string tempAnimals[10000];

    // Clear the screen
    clearScreen();

    // Clear the entire zoo before loading new animal list
    clearZoo();

    try
    {
        // Create a text stream, used to output the text file
        ifstream myFile("zooFile.txt");

        // Inform user that file is being loaded in
        cout << "\nLoading file...\n";

        int counter = 0;

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
            tail->species = tempArray[0];
            tail->name = tempArray[1];
            tail->sex = tempArray[2];
            tail->weight = stoi(tempArray[3]);
            tail->color = tempArray[4];
            tail->origin = tempArray[5];
            tail->id = tempArray[6];
            tail->age = stoi(tempArray[7]);
            tail->season = tempArray[8];
            tail->bday = tempArray[9];
            if (tempArray[10] == "1")
                tail->isAlive = true;
            else
                tail->isAlive = false;

            if (tail->species == "hyena")
                hyenaCount++;
            if (tail->species == "lion")
                lionCount++;
            if (tail->species == "tiger")
                tigerCount++;
            if (tail->species == "bear")
                bearCount++;
            // Generate new tail node and advance tail pointer
            Zoo* newAnimal = new Zoo();
            tail->next = newAnimal;
            tail = newAnimal;
        }
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
    Zoo* n = head;
    try
    {
        // Open the output stream to send file data to
        ofstream myFile("zooFile.txt");

        // Iterate through all zoo objects
        while (n != NULL)
        {
            // Write any non-empty zoo objects to the file, separated by semicolons
            if (!n->name.empty())
            {
                myFile << n->species << ";"
                       << n->name << ";"
                       << n->sex << ";"
                       << n->weight << ";"
                       << n->color << ";"
                       << n->origin << ";"
                       << n->id << ";"
                       << n->age << ";"
                       << n->season << ";"
                       << n->bday << ";"
                       << n->isAlive << "\n";
            }
            n = n->next;
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
