#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;

// genAnimalName.cpp
// mF 10/3/22
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
//  ifstream myFile;
  string myStr = "";
  string fileName = "";
//  int myPause = 0;
//  int num1 = 0;

  // Open a file for reading.
//  try {
//    myFile.open("C:/cStuff/midProgFiles/animalNames.txt");
    cout << "Opening animalNames.txt...\n";
    ifstream myFile("~/Desktop/FCC/CIT-66/warmup-03oct22-dennis-and-michael/animalNames.txt");
//  } catch (const ifstream::failure& e) {
//      cout << "\n Cannot open file! ";
//  }


  // What happens here if this file does not exist?
  // get this code working!
//  try {
//    getline(myFile, myStr);
//  } catch (...) {
//     cout << "\n Cannot open file (second try) " << endl;
//  }


  // Read the file one line at a time.
  // TODO: Remove the file and see what happens...
  // TODO: Add error handling here to check for the file
//  myPause = 0;
//  while (getline(myFile, myStr) && myPause < 2) {
    cout << "Reading lines:";
    while (getline(myFile, myStr)) {
        cout << "\nPrinting a line...";
        cout << "\n  " << myStr;
//    cout << " \n Enter 1 for next line, 2 to stop: ";
//    cin >> myPause;
  }
  cout << "\n\n *********** end of while loop reading file a line at a time **********\n\n";

  // return to top of file
//  myFile.clear();
//  myFile.seekg(0);

    // Close the file.
  myFile.close();

  // Where are the Hyena names in the array?


}
