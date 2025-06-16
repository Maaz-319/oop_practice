#include "Student.h"
#include "Utility.h"
#include <iostream>
#include <conio.h>
using namespace std;

int Student::count = 0; // Initialize static member variable


// Constructor initializes name, age, stud_id, and increments count
Student::Student(string name, int age, int stud_id) : Person(name, age), stud_id(stud_id)
{
    count++;
    type = "Student";
}

void Student::printDetails() // Print details of the student
{
    Utility::print_header("Student Details");
    cout << "Name: " << name << "\n"
         << "Age: " << age << "\n"
         << "Student ID: " << stud_id << endl;
}

int Student::get_by_id(int id, Person **data) // Get student by ID and print their details
{
    for (int i = 0; i < 100; i++)
    {
        if (data[i] != nullptr && data[i]->getId() == id && data[i]->printType() == "Student")
        {
            cout << data[i]->printType() << endl;
            data[i]->printDetails();
            return i;
        }
    }
    return -1;
}

bool Student::save(Person **data, int index) // Save the student to the data array, either at a new index or at a specified index
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

string Student::printType() { return type; }
int Student::getCount() { return count; }
int Student::getId() { return stud_id; }
Student::~Student() {}
