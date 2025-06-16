#include "Person.h"

int Person::count = 0;

Person::Person(string name, int age) : name(name), age(age), type("Person") { count++; }
string Person::getName() { return name; }
int Person::getAge() { return age; }
string Person::printType() { return type; }
int Person::getCount() { return count; }
int Person::getId() { return -1; }
Person::~Person() {}