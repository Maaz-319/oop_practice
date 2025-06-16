#include "Staff.h"
#include "Utility.h" // Utility class for printing headers and messages
#include <iostream>
using namespace std;

int Staff::count = 0; // Initialize static member variable

#include "Person.h" // Base class for Person
// Constructor initializes name, age, designation, staff_id, and increments count
Staff::Staff(string name, int age, string designation, int staff_id)
    : Person(name, age), designation(designation), staff_id(staff_id)
{
    count++; // Increment the count of Staff objects
    type = "Staff"; // Set the type to "Staff"
}

// Print details of the staff member
void Staff::printDetails()
{
    Utility::print_header("Staff Details");
    cout << "Name: " << name << "\n"
         << "Age: " << age << "\n"
         << "Designation: " << designation << "\n"
         << "Staff ID: " << staff_id << endl;
}

// Get staff member by ID and print their details
int Staff::get_by_id(int id, Person **data)
{
    for (int i = 0; i < 100; i++)
    {
        if (data[i] != nullptr && data[i]->getId() == id && data[i]->printType() == "Staff")
        {
            cout << data[i]->printType() << endl;
            data[i]->printDetails();
            return i;
        }
    }
    return -1;
}

// Save the staff member to the data array, either at a new index or at a specified index
bool Staff::save(Person **data, int index)
{
    if (index == -1)
    {
        for (int i = 0; i < 100; i++)
        {
            if (data[i] == nullptr)
            {
                data[i] = this;
                return true;
            }
        }
        return false;
    }
    else
    {
        data[index] = this;
        return true;
    }
}

string Staff::printType() { return type; }
int Staff::getCount() { return count; }
int Staff::getId() { return staff_id; }
string Staff::getDesignation() { return designation; }
Staff::~Staff() {}
