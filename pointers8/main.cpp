#include <iostream>
#include <memory>

using namespace std;

// Pointers Class video code-along - section 7

// Smart pointers -- these deallocate memory automatically

class MyClass
{
public:
    MyClass()
    {
        cout << "Contructor invoked" << endl;
    }
    ~MyClass()
    {
        cout << "Destructor invoked" << endl;
    }
};

int main()
{
    // Smart pointer # 1: Unique pointer
//    unique_ptr<int>unPtr1 = make_unique<int>(25); // sets up a unique pointer to a memory location, and assigns a value
//    unique_ptr<int>unPtr2 = move(unPtr1); // you cannot assign one pointer to another (unique_ptr<int>unPtr2 = unPtr1;) because of unique ownership, but you can move that ownership to a new pointer
//    cout << *unPtr2 << endl;
    // You also cannot access the pointer that the ownership was moved from (cout << *unPtr1 << endl;)

//    unique_ptr<MyClass>unPtr1 = make_unique<MyClass>();


    // Smart pointer # 2: Shared pointer -- can be shared between multiple owners
    // Smart pointers are limited by scope, so leaving a scope removed scope ownership or deallocates the memory once there are no owners
//    {
//        shared_ptr<MyClass>shPtr1 = make_shared<MyClass>();
//        cout << "Shared count: " << shPtr1.use_count() << endl;
//        {
//            shared_ptr<MyClass>shPtr2 = shPtr1;
//            cout << "Shared count: " << shPtr1.use_count() << endl;
//        }
//        cout << "Shared count: " << shPtr1.use_count() << endl;
//    }

    // Smart pointer # 3: Weak pointer

    // Allocating wePtr1:
    weak_ptr<int> wePtr1; // With scopes, shared and unique pointers would be kept alive if declared outside of the scope.
    {
        shared_ptr<int>shPtr1 = make_shared<int>(25);
        wePtr1 = shPtr1; // With weak pointers, if a value is assigned inside of a scope, the memory is deallocated, even if defined outside of scope
    }
    // wePtr1 is now deallocated.
    return 0;
}
