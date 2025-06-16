#include "Person.h"

int Person::count = 0; // Initialize static member variable

// Constructor initializes name, age, and type, and increments count
Person::Person(string name, int age) : name(name), age(age), type("Person") { count++; }

string Person::getName() { return name; } // Returns the name of the person
int Person::getAge() { return age; } // Returns the age of the person
string Person::printType() { return type; } // Returns the type of the person
int Person::getCount() { return count; } // Returns the count of Person objects created
int Person::getId() { return -1; } // This is overridden in derived classes
Person::~Person() {} // Destructor does nothing