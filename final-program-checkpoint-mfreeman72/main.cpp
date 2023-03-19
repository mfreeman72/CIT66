#include <iostream>
#include <fstream>

using namespace std;

// Define zoo object class
class Zoo
{
public:
    string species;
    string name;
    Zoo* next;
};

void importArrivals();
string getAnimalNames(string);
void assignNames(Zoo*);
bool nameInArray(string);
void animalReport(Zoo*);
void addAnimal(string,string);
void editAnimal(int,Zoo*);
void deleteAnimal(int, Zoo*);

// Initialize linked list
Zoo* head = new Zoo();
Zoo* tail = head;

int main()
{
    string newSpecies;
    string newName;
    int number;
    importArrivals();
    assignNames(head);
    animalReport(head);
    cout << "\nAdding a new animal:" << endl;
    while ((newSpecies != "hyena") && (newSpecies != "lion") && (newSpecies != "tiger") && (newSpecies != "bear"))
    {
        cout << "\n  Enter a new species (hyena/lion/tiger/bear): ";
        cin >> newSpecies;
    }
    cout << "\n  Enter name for new " << newSpecies << ": ";
    cin.ignore();
    getline(cin,newName);
    addAnimal(newSpecies,newName);
    cout << "\nAnimal added! Updating list..." << endl;
    animalReport(head);
    cout << "\nEditing an animal:" << endl;
    cout << "\n  Enter the animal number to edit: ";
    cin >> number;
    editAnimal(number,head);
    cout << "\nAnimal edited! Updating list..." << endl;
    animalReport(head);
    cout << "\nDeleting an animal:";
    cout << "\n  Enter the animal number to delete: ";
    cin >> number;
    deleteAnimal(number,head);
    cout << "\nAnimal deleted! Updating list..." << endl;
    animalReport(head);
    return 0;
}

// Function to find out if a name or ID has already been assigned to an animal
bool nameInArray(string name)
{
    Zoo* n = head;
    while(n != NULL)
    {
        if (n->name == name)
            return true;
        n = n->next;
    }
    return false;
}

// Function to load and return sample names for each animal species from the "animalNames.txt" file
string getAnimalNames(string animalSpecies)
{
    // Define local variables
    string myText = "";
    string animalNames[16];
    string hyenas[10];
    string lions[10];
    string tigers[10];
    string bears[10];
    int counter = 0;

    // Open animalNames.txt
    ifstream MyFile("animalNames.txt");

    // Read animalNames.txt and place each line in "animals" array
    while (getline(MyFile, myText))
    {
        animalNames[counter] = myText;
        counter++;
    }

    // Close the file
    MyFile.close();

    // Parse the first 10 names from each line of the "animals" array
    for (int i=0; i<counter + 1; i++)
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
            comma = animalNames[i+2].find(",");
            length = comma;

            // Iterate through the first 10 names
            for (int j=0; j<10; j++)
            {
                // Place animal name starting at the position <start> and going through the next <length> number of charaters
                hyenas[j] = animalNames[i+2].substr(start,length);
                // Ignore the next comma and space to get the start position of the next name
                start = comma + 2;
                // Find the position of the next comma
                comma = animalNames[i+2].find(",", start);
                // Calculate the length of the word
                length = comma - start;
            }
        }
        // Check for the "Lion Names:" header
        if (animalNames[i].find("Lion Names:") != string::npos)
        {
            // Initial values for position and length of first name
            start = 0;
            comma = animalNames[i+2].find(",");
            length = comma;
            // Iterate through the first 10 names
            for (int j=0; j<10; j++)
            {
                // Place animal name starting at the position <start> and going through the next <length> number of charaters
                lions[j] = animalNames[i+2].substr(start,length);
                // Ignore the next comma and space to get the start position of the next name
                start = comma + 2;
                // Find the position of the next comma
                comma = animalNames[i+2].find(",", start);
                // Calculate the length of the word
                length = comma - start;
            }
        }
        // Check for the "Tiger names:" header
        if (animalNames[i].find("Tiger Names:") != string::npos)
        {
            // Initial values for position and length of first name
            start = 0;
            comma = animalNames[i+2].find(",");
            length = comma;
            // Iterate through the first 10 names
            for (int j=0; j<10; j++)
            {
                // Place animal name starting at the position <start> and going through the next <length> number of charaters
                tigers[j] = animalNames[i+2].substr(start,length);
                // Ignore the next comma and space to get the start position of the next name
                start = comma + 2;
                // Find the position of the next comma
                comma = animalNames[i+2].find(",", start);
                // Calculate the length of the word
                length = comma - start;
            }
        }
        // Check for the "Bear Names:" header
        if (animalNames[i].find("Bear Names:") != string::npos)
        {
            // Initial values for position and length of first name
            start = 0;
            comma = animalNames[i+2].find(",");
            length = comma;
            // Iterate through the first 10 names
            for (int j=0; j<10; j++)
            {
                // Place animal name starting at the position <start> and going through the next <length> number of charaters
                bears[j] = animalNames[i+2].substr(start,length);
                // Ignore the next comma and space to get the start position of the next name
                start = comma + 2;
                // Find the position of the next comma
                comma = animalNames[i+2].find(",", start);
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
}

// Import arriving animal information from the arrivingAnimals.txt file
void importArrivals()
{
    // Define temp variable and array
    string animalInput;
    string tempAnimals[100];
    int start;
    int pointer;

    try
    {
        // Create a text stream, used to output the text file
        ifstream myFile("arrivingAnimals.txt");

        // Inform user that file is being loaded in
        cout << "\nImporting animal information...\n";

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
            // Parse data from each line of the file

            // Find animal's species
            start = tempAnimals[i].find("male ",1) + 5;
            pointer = tempAnimals[i].find(",",start);
            tail->species = tempAnimals[i].substr(start, pointer - start);

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

void assignNames(Zoo* n)
{
    cout << "\nAssigning names to animals..." << endl;
    while (n != NULL)
    {
        n->name = getAnimalNames(n->species);
        n = n->next;
    }
}

// Display a full animal report for the entire zoo population, including deceased animals
void animalReport(Zoo* n)
{
    int counter = 1;
    cout << "\n\nAnimals:\n\n";
    while (n != NULL)
    {
        if (n->name != "")
        {
            cout << counter << ". Name: " << n->name << " -- Species: " << n->species << endl;
            counter++;
        }
        n = n->next;
    }
}

void addAnimal(string species,string name)
{
    tail->species = species;
    tail->name = name;
    tail->next = new Zoo();
    tail = tail->next;
}

void editAnimal(int num,Zoo* n)
{
    cout << "\n  Editing animal number " << num << endl;
    Zoo* prev = head;
    string tempSpecies;
    string tempName;
    int counter = 1;
    while (n != NULL)
    {
        if (counter == num)
        {
            while ((tempSpecies != "hyena") && (tempSpecies != "lion") && (tempSpecies != "tiger") && (tempSpecies != "bear"))
            {
                cout << "\n  Enter a species (hyena/lion/tiger/bear): ";
                cin >> tempSpecies;
            }
            n->species = tempSpecies;
            cout << "\n  Enter new name: ";
            cin.ignore();
            getline(cin,tempName);
            n->name = tempName;
        }
        prev = n;
        n = n->next;
        counter++;
    }
}

void deleteAnimal(int num, Zoo* n)
{
    cout << "\n  Deleting animal number " << num << endl;
    Zoo* prev = head;
    int counter = 1;
    while (n != NULL)
    {
        if (counter == num)
        {
            if (n == head)
            {
                head = n->next;
                delete n;
                return;
            }
            else
                prev->next = n->next;
                delete n;
                return;
        }
        prev = n;
        n = n->next;
        counter++;
    }
}
