#include <iostream>
#include <fstream>

// mF 9/21/22
// WarmUP21sep22

using namespace std;

// References:
        // https://www.w3schools.com/cpp/cpp_files.asp
        // https://www.w3schools.in/cplusplus/working-with-files

// Instructions:
        // 1) Discuss this code with your lab partner
        //     a) what does it do?
        //     b) where does it do it?
        //     c) how are file and path names used?
        //     d) what is try and catch?
        // 2) Code up this warmup and examine your new files
        // 3) Create a loop to write 100 lines of text to your new file
        // 4) Advanced: Open your text file and read the contents into a linear (1D) array.

int main()
{
    try
    {
        cout << "Creating /home/mike/Desktop/myTextFile.txt...";
        ofstream myFile("/home/mike/Desktop/myTextFile.txt");
        myFile << "\nThis is the first line of the file.";
        myFile << "\nThis is the second line of the file.";
        myFile << "\nThis is the third line of the file.";

        myFile << "\n\n100 Lines:";
        for(int i=0; i<100; i++)
        {
            myFile << "\nThis is line " << i + 1;
        }
        myFile.close();

    }
    catch (...)
    {
        cout << "\nThere was a problem creating your new file.";
    }

    string myTextStr;
    string myTextArray[110];
    int line = 0;

    try
    {
        ifstream myFile("/home/mike/Desktop/myTextFile.txt");
        cout << "\n\nContents of /home/mike/Desktop/myTextFile.txt:" << endl;

        while(getline(myFile,myTextStr))
        {
            cout << "\n" << myTextStr;
        }
        cout << "\n\nEnd of /home/mike/Desktop/myTextFile.txt";
        myFile.close();

    }
    catch (...)
    {
        cout << "\nThere was a problem reading your new file.";
    }

    try
    {
        ifstream myFile("/home/mike/Desktop/myTextFile.txt");
        cout << "\n\nCreating array..." << endl;

        while(getline(myFile,myTextStr))
        {
            myTextArray[line] = myTextStr;
            line++;
        }

        myFile.close();
    }
    catch (...)
    {
        cout << "\nThere was a problem reading your new file.";
    }


    try
    {
        fstream myFile("/home/mike/Desktop/myTextFile.txt",std::fstream::app);
        cout << "Appending to the file...";

        myFile << "\n\nHere is an appended line.";
        myFile << "\nAnother appended line.";
        myFile << "\nThe last appended line.";

        myFile.close();
    }
    catch (...)
    {
        cout << "\nThere was a problem appending to your file.";
    }

    try
    {
        ifstream myFile("/home/mike/Desktop/myTextFile.txt");
        cout << "\n\nContents of /home/mike/Desktop/myTextFile.txt:" << endl;

        while(getline(myFile,myTextStr))
        {
            cout << "\n" << myTextStr;
        }
        cout << "\n\nEnd of /home/mike/Desktop/myTextFile.txt";
        myFile.close();

    }
    catch (...)
    {
        cout << "\nThere was a problem reading your new file.";
    }
    return 0;
}
