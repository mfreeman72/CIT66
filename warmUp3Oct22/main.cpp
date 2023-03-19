#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;

// genAnimalName.cpp
// dH 9/28/22
// demo file for midterm program Fall '22 CIT-66 C++ Programming
//
// Use this file to help you write the genAnimalName() function in
// your midterm program.
//
// Common Programming Errors:
//   No error handling for file IO
//   File not found error not reported
//   Miscounting number of lines in the file (open the file by hand, if possible, and check!)
//   Miscalculating array element length. the sizeof() method returns the number of bytes, not the number of elements.
//
// References:
//   https://www.w3schools.com/cpp/cpp_files.asp
//   https://www.w3schools.com/cpp/cpp_arrays_size.asp
//   https://www.w3schools.com/cpp/cpp_exceptions.asp
//

// text files are in the directory: C:/cStuff/midProgFiles/


int main(){
  ifstream myFile;
  string myStr = "";
  string fileName = "";
  int counter = 0;
  int num1 = 0;
  string animalNamesArray[4][10];

  // Open a file for reading.
  try {
    myFile.open("/home/mike/Desktop/FCC/CIT-66/warmup-03oct22-dennis-and-michael/animalNames.txt");
  } catch (const ifstream::failure& e) {
      cout << "\n Cannot open file! ";
  }

  string animals[15];

  try {
      while (getline(myFile, myStr)) {
        cout << "\n" << myStr;
        animals[counter] = myStr;
        counter++;
      }
  } catch (...) {
     cout << "\n Cannot open file (second try) " << endl;
  }

  cout << "\n\n *********** end of while loop reading file a line at a time **********\n\n";

  // return to top of file
  myFile.clear();
  myFile.seekg(0);

    // Close the file.
  myFile.close();

  // Where are the Hyena names in the array?

  for (int i=0; i<15; i++)
  {
      if (animals[i].find("Hyena") || animals[i].find("Lion") || animals[i].find("Tiger") || animals[i].find("Bear"))
      {
          cout << "Hyenas = " << animals[i].find("Hyena");
          cout << animals[i+1] << endl;
      }
  }
}
