#include "Teacher.h"
#include "Utility.h"
#include <iostream>
using namespace std;

int Teacher::count = 0;

Teacher::Teacher() : Person()
{
    count++;
    setType("Teacher");
    subject = "";
    teacher_id = 0;
}

void Teacher::printDetails()
{
    Utility::print_header("Teacher Details");
    cout << "Name: " << getName() << "\n"
         << "Age: " << getAge() << "\n"
         << "Phone: " << getPhone() << "\n"
         << "Address: " << getAddress() << "\n"
         << "Subject: " << subject << "\n"
         << "Teacher ID: " << teacher_id << endl;
}

void Teacher::setTeacherId(int id)
{
    teacher_id = id;
}

void Teacher::setSubject(const string& subject)
{
    this->subject = subject;
}

int Teacher::getTeacherId() const
{
    return teacher_id;
}

string Teacher::getSubject() const
{
    return subject;
}

int Teacher::get_by_id(int id, Person **data)
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

bool Teacher::save(Person **data, int index)
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

string Teacher::printType() { return Person::printType(); }
int Teacher::getCount() { return count; }
int Teacher::getId() { return teacher_id; }
Teacher::~Teacher() {}
