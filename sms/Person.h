#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person {
private:
    static int count; // Static member to keep track of the number of Person objects created
protected:
    string name; // Name of the person
    int age; // Age of the person
    string type; // Type of the person (e.g., "Student", "Teacher", "Staff")
public:
    Person(string name, int age); // Constructor to initialize name and age
    virtual void printDetails() = 0; // Pure virtual function to print details, is implemented by derived classes
    virtual string getName(); // Returns the name of the person
    virtual int getAge(); // Returns the age of the person
    virtual string printType(); // Returns the type of the person
    static int getCount(); // Returns the count of Person objects created
    virtual int getId(); // This is overridden in derived classes
    virtual ~Person(); // Destructor does nothing
};
#endif