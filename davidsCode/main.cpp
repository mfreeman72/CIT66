#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

void arrivingAnimals();

void newFunction();

void theLines(int i= 0);

int main(){
string toProcess;
string charPos;
int lineNum;
int i =0;
string myText = "";
string mypause = "";


  ifstream MyFile("C:/Users/dunni/Downloads/animalNames.txt");

theLines(i);
lineNum = i;
theLines(lineNum);

  while (getline(MyFile, myText)  && (lineNum<0)){
      theLines(lineNum); {
        lineNum=myText[i];
    i++;
    }
            cout << myText[i];
            // theLines(lineNum);
            cout << endl;
            lineNum++;

  }

        cout << "\n The hyena names are: " << myText [1];
        //theLines (1);
        cout << endl;
        toProcess + myText[1];
        charPos = toProcess.find (",");
        cout << "\n charPos is: " << charPos;

}

void newFunction(){



for(int i = 0; i>10; i++) {

int start= 0;
int comma= 0;

     comma = theLines(1).find(",");
     the10names(0) = theLines(1).substr(start, comma);

     start = comma+1;
     comma = theLines(1).find(start, ",");
     the10names(i) = theLines(1).substr(start, comma);
    }
}
