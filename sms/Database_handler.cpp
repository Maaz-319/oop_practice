#include "Database_handler.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"

#include <iostream>
#include <fstream>
using namespace std;

void save_person(Person **data)
{
    ofstream file_stud("students.txt");
    ofstream file_teach("teachers.txt");
    ofstream file_staff("staff.txt");

    if (!file_stud.is_open() || !file_teach.is_open() || !file_staff.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (int i = 0; data[i] != nullptr; i++)
    {
        if (data[i]->printType() == "Student")
        {
            file_stud << data[i]->getName() << "`"
                      << data[i]->getAge() << "`"
                      << data[i]->getId() << endl;
        }        else if (data[i]->printType() == "Teacher")
        {
            Teacher *teacher = static_cast<Teacher *>(data[i]);
            file_teach << data[i]->getName() << "`"
                       << data[i]->getAge() << "`"
                       << data[i]->getId() << "`"
                       << teacher->get_subject() << endl;
        }        else if (data[i]->printType() == "Staff")
        {
            Staff *staff = static_cast<Staff *>(data[i]);
            file_staff << data[i]->getName() << "`"
                       << data[i]->getAge() << "`"
                       << data[i]->getId() << "`"
                       << staff->getDesignation() << endl;
        }
    }
    file_stud.close();
    file_teach.close();
    file_staff.close();
}

Person **read_person()
{
    Person **data = new Person *[100];
    for (int i = 0; i < 100; i++)
    {
        data[i] = nullptr;
    }
    ifstream file_stud("students.txt");
    ifstream file_teach("teachers.txt");
    ifstream file_staff("staff.txt");

    if (!file_stud.is_open() || !file_teach.is_open() || !file_staff.is_open())
    {
        cerr << "Error opening file for reading." << endl;
        return nullptr;
    }

    string line;
    int index = 0;

    while (getline(file_stud, line))
    {
        string name, age_str, id_str;
        size_t pos1 = line.find('`');
        size_t pos2 = line.find('`', pos1 + 1);
        name = line.substr(0, pos1);
        age_str = line.substr(pos1 + 1, pos2 - pos1 - 1);
        id_str = line.substr(pos2 + 1);
        int age = stoi(age_str);
        int id = stoi(id_str);
        data[index++] = new Student(name, age, id);
    }

    while (getline(file_teach, line))
    {
        string name, age_str, id_str, subject;
        size_t pos1 = line.find('`');
        size_t pos2 = line.find('`', pos1 + 1);
        size_t pos3 = line.find('`', pos2 + 1);
        name = line.substr(0, pos1);
        age_str = line.substr(pos1 + 1, pos2 - pos1 - 1);
        id_str = line.substr(pos2 + 1, pos3 - pos2 - 1);
        subject = line.substr(pos3 + 1);
        int age = stoi(age_str);
        int id = stoi(id_str);
        data[index++] = new Teacher(name, age, subject, id);
    }

    while (getline(file_staff, line))
    {
        string name, age_str, id_str, designation;
        size_t pos1 = line.find('`');
        size_t pos2 = line.find('`', pos1 + 1);
        size_t pos3 = line.find('`', pos2 + 1);
        name = line.substr(0, pos1);
        age_str = line.substr(pos1 + 1, pos2 - pos1 - 1);
        id_str = line.substr(pos2 + 1, pos3 - pos2 - 1);
        designation = line.substr(pos3 + 1);
        int age = stoi(age_str);
        int id = stoi(id_str);
        data[index++] = new Staff(name, age, designation, id);
    }

    file_stud.close();
    file_teach.close();
    file_staff.close();
    data[index] = nullptr;

    return data;
}