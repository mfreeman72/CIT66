#include <iostream>
using namespace std;

// dH warmUp29aug22.cpp


// Demonstrate your mastery of Code::Blocks by...
//    1) add, edit, delete source files in a project
//    2) create a new .cpp file with the CodeBlock wizard and add it to your project
//    3) create a new project and.. add, edit, delete, save, open new *.cpp files -- where are your source files saved?
//
// Code up a function
//    1) get your function working
//    2) demonstrate understanding between function declaration and definition
//    3) code up a multi-parameter function and use it in a .cpp program!

// References:
// https://www.w3schools.com/CPP/cpp_functions.asp
// https://www.w3schools.com/CPP/cpp_function_multiple.asp


void someFunction() {
  cout << "\n\n Hello from someFunction! \n\n";

}

// function declaration only:
int sumTwoInts(int, int);

// My product function declaration:
int prodTwoInts(int, int);

int main()
{
    cout << "Warmup August 29, 2022!" << endl;
    cout << "\n\n Welcome to Functions...\n\n";

    // Call a function!
    someFunction();
    cout << "\n\n";

    // Call sumTwoInts() and prodTwoInts()
    cout << "the return value of sumTwoInts is... " << sumTwoInts(2,2) << "\n\n";
    cout << "The return value of prodTwoInts is... " << prodTwoInts(3,3) << "\n\n";
    return 0;
}


// function definition after main()!
// why does this work?

int sumTwoInts(int num1, int num2) {
  int result = 0;
  result = num1+ num2;
  return result;
}

int prodTwoInts(int num1, int num2)
{
    return (num1 * num2);
}
