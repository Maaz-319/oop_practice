#include "Staff.h"
#include "Utility.h"
#include <iostream>
using namespace std;

int Staff::count = 0;

Staff::Staff() : Person()
{
    count++;
    setType("Staff");
    staff_id = 0;
    designation = "";
}

void Staff::printDetails()
{
    Utility::print_header("Staff Details");
    cout << "Name: " << getName() << "\n"
         << "Age: " << getAge() << "\n"
         << "Phone: " << getPhone() << "\n"
         << "Address: " << getAddress() << "\n"
         << "Designation: " << designation << "\n"
         << "Staff ID: " << staff_id << endl;
}

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

string Staff::printType() { return Person::printType(); }
int Staff::getCount() { return count; }
int Staff::getId() { return staff_id; }
string Staff::getDesignation() { return designation; }

void Staff::setStaffId(int staff_id) 
{ 
    this->staff_id = staff_id; 
}

void Staff::setDesignation(const string& designation) 
{ 
    this->designation = designation; 
}

int Staff::getStaffId() const
{
    return staff_id;
}

Staff::~Staff() {}
