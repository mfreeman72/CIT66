#include <iostream>

using namespace std;

class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee
{
private: // Encapsulation of object attributes
    string Company;
    int Age;
protected: // Allows attribute to be accessible by child class, but not by anything outside of classes
    string Name;

public:
    // Getters and setters to interact with encapsulated data
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    string getCompany()
    {
        return Company;
    }
    void setAge(int age)
    {
        if(age>=18)
            Age = age;
    }
    int getAge()
    {
        return Age;
    }
    // Methods to introduce object behaviors
    void IntroduceYourself() // Method -- object-linked function
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }

    void AskForPromotion()
    {
        if(Age>30)
            cout << Name << " got promoted!" << endl;
        else
            cout << Name << ", sorry. No promotion for you!" << endl;
    }

    virtual void Work() // virtual function checks for alternate implementation in child classes, and adjusts for them when using pointers
    {
        cout << Name << " is checking e-mail, task backlog, performing tasks..." << endl;
    }

    Employee(string name, string company, int age) // Contructor
    {
        Name = name;
        Company = company;
        Age = age;
    }
};

class Developer:public Employee // Create child class from Employee class; public makes all methods accessible to child class
{
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage)
        :Employee(name,company,age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void FixBug()
    {
        cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
    }
    void Work()
    {
        cout << Name << " is writing " << FavProgrammingLanguage << " code" << endl;
    }

};

class Teacher:public Employee
{
public:
    string Subject;
    void PrepareLesson()
    {
        cout << Name << " is preparing " << Subject << " lesson" << endl;
    }
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }
    void Work()
    {
        cout << Name << " is teaching " << Subject << endl;
    }

};

int main()
{
    Employee employee1 = Employee("Saldina","YouTube - CodeBeauty",25); // Calling constructor
    employee1.IntroduceYourself(); // Call method

    Employee employee2 = Employee("John","Amazon",35);
    employee2.IntroduceYourself();

    employee1.AskForPromotion();
    employee2.AskForPromotion();

    Developer d = Developer("Mike", "YouTube", 49, "Python");
    d.FixBug();

    Teacher t = Teacher("Jack", "Cool School", 35, "History");
    t.PrepareLesson();
    t.AskForPromotion();
    // The most common use of polymorphism is when a parent class reference is used to refer to a child class object
    d.Work();
    t.Work();

    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->Work(); // without virtual function, this would only give the original Employee.Work() function response
    e2->Work();

    return 0;
}
