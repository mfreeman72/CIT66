#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

// mF midterm

class Exception : public exception
{
public:
    char * what ()
    {
        return "Invalid entry";
    }
};

void menu();
void loadZoo();
void saveZoo();
void delZoo();
void signZoo();
void appendZoo();
void habitatID();
void populateHabitats();
void displayZoo();

string zooArray[3][3] = {{"Simba", "Nala", "Scar"},{"Rajah", "Tigger", "Tony"},{"Pooh", "Smokey", "Baloo"}};
string animalType[3] = {"Lion", "Tiger", "Bear"};
string signature = "";
int menuEntry = 0;

int main()
{
    cout << "Zoo Manager\n\n";

    cout << "9 enclosures available in current configuration: 3 habitats, each with 3 enclosures\n\n";

    displayZoo();

    while(menuEntry != 8)
    {
        menu();
    }
    return 0;
}

void menu()
{
    cout << "\nMenu Options:\n\n";
    cout << "1. Reassign zoo enclosure habitats\n";
    cout << "2. Change animal names\n";
    cout << "3. Display current zoo enclosure data\n";
    cout << "4. Authorize zoo assignments with digital signature\n";
    cout << "5. Save zoo data to file\n";
    cout << "6. Load zoo data from existing file\n";
    cout << "7. Delete zoo file\n";
    cout << "8. Quit Zoo Manager program\n\n";
    cout << "Please enter your menu choice: ";

    try
    {
        cin >> menuEntry;
        switch(menuEntry)
        {
        case 1:
            habitatID();
        break;

        case 2:
            populateHabitats();
        break;

        case 3:
            displayZoo();
        break;

        case 4:
            signZoo();
            break;

        case 5:
            saveZoo();
            break;
        case 6:
            loadZoo();
            break;
        case 7:
            delZoo();
            break;
        case 8:
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    }
}

void habitatID()
{
    cout << "\n\n";
    for(int i=0; i<3; i++)
    {
        cout << "Enter the type of animal for habitat " << i + 1 << ": ";
        cin >> animalType[i];
    }
}

void populateHabitats()
{
    cout << "\n\n";
    for (int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
        cout << "Please enter the name or ID for " << animalType[i] << " in enclosure number " << (j+1) << ": ";
        cin >> zooArray[i][j];
        }
        cout << endl;
    }

}

void displayZoo()
{
    // Table Header
    cout << "\n\nYour current zoo data:" << endl;

    // Column labels
    cout << "\t| 1\t\t| 2\t\t| 3\t\t|" << endl;;
    for(int i=0; i<3; i++)
    {
        // Row separator
        cout << "--------+---------------+---------------+---------------+" << endl;
        // Row label
        cout << animalType[i] << "s\t| ";
        // Loop through array to fill in each cell in grid
        for(int j=0; j<3; j++)
        {
            cout << zooArray[i][j] << "\t";
            if(zooArray[i][j].length() <= 5)
               {
                   cout << "\t";
               }
            cout << "| ";
        }
        cout << endl;
    }
    cout << "--------+---------------+---------------+---------------+" << endl;
    if (signature != "")
    {
        cout << "\n\nThese enclosures have been authorized by " << signature << "\n\n";
    }
}

void signZoo()
{
    cout << "\n\nEnter name for authorized signature confirming animal assignments: ";

    cin.ignore();
    getline(cin, signature);

    cout << "\n\nAuthorized as " << signature << ".\n\n";
}

void loadZoo()
{
    string animal;
    string animals[13];
    try
    {
        // Create a text string, used to output the text file
        ifstream myFile("/home/mike/zooFile.txt");
        // Read the file line by line
        cout << "\n\nLoading file...\n\n";
        int counter = 0;
        while(getline(myFile,animal)){
            animals[counter] = animal;
            counter++;
        }
        myFile.close();

        for (int k=0; k<3; k++)
        {
            animalType[k] = animals[k];
        }
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                zooArray[i][j] = animals[3+(i*3)+j];
            }
        }
        if (animals[12] != "")
        {
            signature = animals[12];
        }
    }
    catch (...)
    {
        cout << "\nException caught! \n";
    }
}

void saveZoo()
{
    cout << "\n\nSaving zoo data...\n\n";
    try
    {
        ofstream myFile("/home/mike/zooFile.txt");
        for (int k=0; k<3;k++)
        {
            myFile << animalType[k] << "\n";
        }
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                myFile << zooArray[i][j] << "\n";
            }
        }
        myFile.close();
    }
    catch (...)
    {
        cout << "\nException caught! \n";
    }
    if (signature != "")
    {
        cout << "\n\nSigning file with authorized signature...\n\n";
        try
        {
            // Create a fstream object for appending
            fstream myFile("/home/mike/zooFile.txt", std::fstream::app);
            // Append to the file
            myFile << signature << "\n";
            // Close the file
            myFile.close();
        }
        catch (...)
        {
            cout << "\nException caught! \n";
        }

    }

}

void delZoo()
{
    if( remove( "/home/mike/zooFile.txt" ) != 0 )
        cout << "\n\nError deleting file\n\n";
    else
        cout << "\n\nFile successfully deleted\n\n";
}
