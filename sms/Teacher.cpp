#include "Teacher.h"
#include "Utility.h"
#include <iostream>
using namespace std;

int Teacher::count = 0; // Initialize static member variable

// Constructor initializes name, age, subject, teacher_id, and increments count
Teacher::Teacher(string name, int age, string subject, int teacher_id)
    : Person(name, age), subject(subject), teacher_id(teacher_id)
{
    count++;
    type = "Teacher";
}

void Teacher::printDetails()    // Print details of the teacher
{
    Utility::print_header("Teacher Details");
    cout << "Name: " << name << "\n"
         << "Age: " << age << "\n"
         << "Subject: " << subject << "\n"
         << "Teacher ID: " << teacher_id << endl;
}

int Teacher::get_by_id(int id, Person **data) // Get teacher by ID and print their details
{
    for (int i = 0; i < 100; i++)
    {
        if (data[i] != nullptr && data[i]->getId() == id && data[i]->printType() == "Teacher")
        {
            cout << data[i]->printType() << endl;
            data[i]->printDetails();
            return i;
        }
    }
    return -1;
}

bool Teacher::save(Person **data, int index) // Save the teacher to the data array, either at a new index or at a specified index
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

string Teacher::printType() { return type; }
int Teacher::getCount() { return count; }
int Teacher::getId() { return teacher_id; }
Teacher::~Teacher() {}
