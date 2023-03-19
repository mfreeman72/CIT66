#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
  string myText = "";
  string animals[8];
  string hyenas[10];
  string lions[10];
  string tigers[10];
  string bears[10];

  int count = 0;

  // Open animalNames.txt
  ifstream MyFile("animalNames.txt");
  // Read animalNames.txt and place each line in "animals" array
  while (getline(MyFile, myText)){
    animals[count] = myText;
    count++;
  }
  // Close the file
  MyFile.close();

  // Parse the first 10 names from each line of the "animals" array
  cout << "Parsed from file:\n\n";
  for (int i=0; i<count + 1; i++)
  {
      // Define position and length variables
      int start;
      int comma;
      int length;

      // Display the line currently being parsed
      cout << animals[i] << endl;

      // Each "if" statement checks for which line is an animal type indicator

      // Check for the "Hyena Names:" header
      if (animals[i].find("Hyena Names:") != string::npos)
      {
        // Initial values for position and length of first name
        start = 0;
        comma = animals[i+1].find(",");
        length = comma;

        // Iterate through the first 10 names
        for (int j=0; j<10; j++)
        {
            // Place animal name starting at the position <start> and going through the next <length> number of charaters
            hyenas[j] = animals[i+1].substr(start,length);
            // Ignore the next comma and space to get the start position of the next name
            start = comma + 2;
            // Find the position of the next comma
            comma = animals[i+1].find(",", start);
            // Calculate the length of the word
            length = comma - start;
        }
      }
      // Check for the "Lion Names:" header
      if (animals[i].find("Lion Names:") != string::npos)
      {
        // Initial values for position and length of first name
        start = 0;
        comma = animals[i+1].find(",");
        length = comma;
        // Iterate through the first 10 names
        for (int j=0; j<10; j++)
        {
            // Place animal name starting at the position <start> and going through the next <length> number of charaters
            lions[j] = animals[i+1].substr(start,length);
            // Ignore the next comma and space to get the start position of the next name
            start = comma + 2;
            // Find the position of the next comma
            comma = animals[i+1].find(",", start);
            // Calculate the length of the word
            length = comma - start;
        }
      }
      // Check for the "Tiger names:" header
      if (animals[i].find("Tiger names:") != string::npos)
      {
        // Initial values for position and length of first name
        start = 0;
        comma = animals[i+1].find(",");
        length = comma;
        // Iterate through the first 10 names
        for (int j=0; j<10; j++)
        {
            // Place animal name starting at the position <start> and going through the next <length> number of charaters
            tigers[j] = animals[i+1].substr(start,length);
            // Ignore the next comma and space to get the start position of the next name
            start = comma + 2;
            // Find the position of the next comma
            comma = animals[i+1].find(",", start);
            // Calculate the length of the word
            length = comma - start;
        }
      }
      // Check for the "Bear Names:" header
      if (animals[i].find("Bear Names:") != string::npos)
      {
        // Initial values for position and length of first name
        start = 0;
        comma = animals[i+1].find(",");
        length = comma;
        // Iterate through the first 10 names
        for (int j=0; j<10; j++)
        {
            // Place animal name starting at the position <start> and going through the next <length> number of charaters
            bears[j] = animals[i+1].substr(start,length);
            // Ignore the next comma and space to get the start position of the next name
            start = comma + 2;
            // Find the position of the next comma
            comma = animals[i+1].find(",", start);
            // Calculate the length of the word
            length = comma - start;
        }
      }
  }

  // Display formatted lists of animal names by type
  cout << "\n\nStored in animal arrays:";

  // Animal type headers (\t = tab)
  cout << "\n\nHyenas\t\tLions\t\tTigers\t\tBears" << endl;
  cout << "------\t\t-----\t\t------\t\t-----" << endl;
    // Iterate through each of the 10 array indexes
    for (int i=0; i<10; i++)
    {
        // Display names in index [i] of each animal type, separated by tabs
        cout << hyenas[i] << "\t\t" << lions[i] << "\t\t" << tigers[i] << "\t\t" << bears[i] << endl;
    }
}
