#include "Person.h"

int Person::count = 0;

Person::Person() : name(""), age(0), type("Person"), phone("0"), address("") { count++; }

// Getters
string Person::getName() { return name; }
int Person::getAge() { return age; }
string Person::printType() { return type; }
string Person::getPhone() { return phone; }
string Person::getAddress() { return address; }
int Person::getCount() { return count; }
int Person::getId() { return -1; }

// Setters
void Person::setName(const string& name) { this->name = name; }
void Person::setAge(int age) { this->age = age; }
void Person::setType(const string& type) { this->type = type; }
void Person::setPhone(const string& phone) { this->phone = phone; }
void Person::setAddress(const string& address) { this->address = address; }

Person::~Person() {}