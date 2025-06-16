#include <iostream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <string>

#include "Utility.h"
#include "Colors.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"

using namespace std;

Person **data = new Person *[100];

// FUNCTIONS FOR ENTER DATA
void add_student()
{
    Utility::print_header("ADD NEW STUDENT");
    string name;
    int age, id;
    setConsoleColor("lightcyan");
    cout << "Student Name: ";
    resetConsoleColor();
    cin.ignore();
    getline(cin, name);
    setConsoleColor("lightcyan");
    cout << "Student Age: ";
    resetConsoleColor();
    cin >> age;
    setConsoleColor("lightcyan");
    cout << "Student ID: ";
    resetConsoleColor();
    cin >> id;
    Student *student = new Student(name, age, id);
    if (student->save(data))
    {
        Utility::print_success_message("Student saved successfully at position " + to_string(Person::getCount()));
    }
    else
    {
        Utility::print_error_message("Data is full, cannot save more Persons.");
    }
    getch();
}

void add_teacher()
{
    Utility::print_header("ADD NEW TEACHER");
    string name, subject;
    int age, id;
    setConsoleColor("lightcyan");
    cout << "Teacher Name: ";
    resetConsoleColor();
    cin.ignore();
    getline(cin, name);
    setConsoleColor("lightcyan");
    cout << "Teacher Age: ";
    resetConsoleColor();
    cin >> age;
    setConsoleColor("lightcyan");
    cout << "Subject: ";
    resetConsoleColor();
    cin.ignore();
    getline(cin, subject);
    setConsoleColor("lightcyan");
    cout << "Teacher ID: ";
    resetConsoleColor();
    cin >> id;
    Teacher *teacher = new Teacher(name, age, subject, id);
    if (teacher->save(data))
    {
        Utility::print_success_message("Teacher saved successfully at position " + to_string(Person::getCount()));
    }
    else
    {
        Utility::print_error_message("Data is full, cannot save more Persons.");
    }
    getch();
}

void add_staff()
{
    Utility::print_header("ADD NEW STAFF");
    string designation;
    string name;
    int age, id;
    setConsoleColor("lightcyan");
    cout << "Staff Name: ";
    resetConsoleColor();
    cin.ignore();
    getline(cin, name);
    setConsoleColor("lightcyan");
    cout << "Staff Age: ";
    resetConsoleColor();
    cin >> age;
    setConsoleColor("lightcyan");
    cout << "Designation: ";
    resetConsoleColor();
    cin.ignore();
    getline(cin, designation);
    setConsoleColor("lightcyan");
    cout << "Staff ID: ";
    resetConsoleColor();
    cin >> id;
    Staff *staff = new Staff(name, age, designation, id);
    if (staff->save(data))
    {
        Utility::print_success_message("Staff saved successfully at position " + to_string(Person::getCount()));
    }
    else
    {
        Utility::print_error_message("Data is full, cannot save more Persons.");
    }
    getch();
}

// FUNCTIONS FOR GET DATA
void get_student_data()
{
    Utility::print_header("GET STUDENT DATA");
    int id;
    setConsoleColor("lightcyan");
    cout << "Enter ID to find: ";
    resetConsoleColor();
    cin >> id;
    if (Student::get_by_id(id, data) == -1)
    {
        Utility::print_error_message("No Student found with ID: " + to_string(id));
    }
    getch();
}

void get_teacher_data()
{
    Utility::print_header("GET TEACHER DATA");
    int id;
    setConsoleColor("lightcyan");
    cout << "Enter ID to find: ";
    resetConsoleColor();
    cin >> id;
    if (Teacher::get_by_id(id, data) == -1)
    {
        Utility::print_error_message("No Teacher found with ID: " + to_string(id));
    }
    getch();
}

void get_staff_data()
{
    Utility::print_header("GET STAFF DATA");
    int id;
    setConsoleColor("lightcyan");
    cout << "Enter ID to find: ";
    resetConsoleColor();
    cin >> id;
    if (Staff::get_by_id(id, data) == -1)
    {
        Utility::print_error_message("No Staff found with ID: " + to_string(id));
    }
    getch();
}

// FUNCTIONS FOR MODIFY DATA
void modify_student_data()
{
    Utility::print_header("MODIFY STUDENT DATA");

    int id;
    cout << "Enter ID to modify: ";
    cin >> id;
    int index = Student::get_by_id(id, data);
    if (index == -1)
    {
        Utility::print_error_message("No student found with ID: " + to_string(id));
        return;
    }
    cout << "================================\n";
    string name;
    int age;
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Student Age: ";
    cin >> age;
    Student *student = new Student(name, age, id);
    student->save(data, index);
    Utility::print_success_message("Student data modified successfully!");
    getch();
}

void modify_teacher_data()
{
    Utility::print_header("MODIFY TEACHER DATA");

    int id;
    cout << "Enter ID to modify: ";
    cin >> id;
    int index = Teacher::get_by_id(id, data);
    if (index == -1)
    {
        cout << "No Teacher found with ID: " << id << endl;
        return;
    }
    cout << "================================\n";
    string name, subject;
    int age;
    cout << "Enter Teacher Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Teacher Age: ";
    cin >> age;
    cout << "Enter Subject: ";
    cin.ignore();
    getline(cin, subject);
    Teacher *teacher = new Teacher(name, age, subject, id);
    teacher->save(data, index);
    Utility::print_success_message("Student data modified successfully!");
    getch();
}

void modify_staff_data()
{
    Utility::print_header("MODIFY STAFF DATA");

    int id;
    cout << "Enter ID to modify: ";
    cin >> id;
    int index = Staff::get_by_id(id, data);
    if (index == -1)
    {
        cout << "No Teacher found with ID: " << id << endl;
        return;
    }
    cout << "================================\n";
    string name, designation;
    int age;
    cout << "Enter Staff Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Staff Age: ";
    cin >> age;
    cout << "Enter Designation: ";
    cin.ignore();
    getline(cin, designation);
    Staff *staff = new Staff(name, age, designation, id);
    staff->save(data, index);
    getch();
}

// SUB-MENU FOR ENTER DATA
void enter_data_menu()
{
    char choice;
    do
    {
        vector<string> options = {
            "Add Student",
            "Add Teacher",
            "Add Staff",
            "Back to Main Menu"};        Utility::print_menu_box("ENTER DATA MENU", options);
        setConsoleColor("yellow");
        cout << "Enter your choice (1-4): ";
        resetConsoleColor();
        cin >> choice;

        switch (choice)
        {
        case '1':
            add_student();
            break;
        case '2':
            add_teacher();
            break;
        case '3':
            add_staff();
            break;
        case '4':
            Utility::print_info_box("Returning to main menu...");
            break;
        default:
            Utility::print_error_message("Invalid choice! Please select 1-4.");
            cout << "\nPress any key to continue...";
            getch();
        }
    } while (choice != '4');
}

// SUB-MENU FOR GET DATA
void get_data_menu()
{
    char choice;
    do
    {
        vector<string> options = {
            "Student by ID",
            "Teacher by ID",
            "Staff by ID",
            "Back to Main Menu"};        Utility::print_menu_box("VIEW DATA MENU", options);
        setConsoleColor("yellow");
        cout << "Enter your choice (1-4): ";
        resetConsoleColor();
        cin >> choice;

        switch (choice)
        {
        case '1':
            get_student_data();
            break;
        case '2':
            get_teacher_data();
            break;
        case '3':
            get_staff_data();
            break;
        case '4':
            Utility::print_info_box("Returning to main menu...");
            break;
        default:
            Utility::print_error_message("Invalid choice! Please select 1-4.");
            cout << "\nPress any key to continue...";
            getch();
        }
    } while (choice != '4');
}

// SUB-MENU FOR MODIFY DATA
void modify_data_menu()
{
    char choice;
    do
    {
        vector<string> options = {
            "Modify Student",
            "Modify Teacher",
            "Modify Staff",
            "Back to Main Menu"};        Utility::print_menu_box("MODIFY DATA MENU", options);
        setConsoleColor("yellow");
        cout << "Enter your choice (1-4): ";
        resetConsoleColor();
        cin >> choice;

        switch (choice)
        {
        case '1':
            modify_student_data();
            break;
        case '2':
            modify_teacher_data();
            break;
        case '3':
            modify_staff_data();
            break;
        case '4':
            Utility::print_info_box("Returning to main menu...");
            break;
        default:
            Utility::print_error_message("Invalid choice! Please select 1-4.");
            cout << "\nPress any key to continue...";
            getch();
        }
    } while (choice != '4');
}

void display_system_stats()
{
    Utility::print_header("SYSTEM STATISTICS");

    setConsoleColor("lightgreen");
    cout << "Database Status:" << endl;
    resetConsoleColor();
    Utility::print_dashed_line(20);
    setConsoleColor("white");
    cout << "Total Records: ";
    setConsoleColor("lightcyan");
    cout << Person::getCount() << "/100" << endl;
    setConsoleColor("white");
    cout << "Available Slots: ";
    setConsoleColor("lightcyan");
    cout << (100 - Person::getCount()) << endl;
    setConsoleColor("white");
    cout << "Memory Usage: ";
    setConsoleColor("lightcyan");
    cout << (Person::getCount() * 100.0 / 100) << "%" << endl;

    setConsoleColor("lightgreen");
    cout << "\nRecord Distribution:" << endl;
    resetConsoleColor();
    Utility::print_dashed_line(25);
    setConsoleColor("white");
    cout << "Students: ";
    setConsoleColor("lightcyan");
    cout << Student::getCount() << endl;
    setConsoleColor("white");
    cout << "Teachers: ";
    setConsoleColor("lightcyan");
    cout << Teacher::getCount() << endl;
    setConsoleColor("white");
    cout << "Staff: ";
    setConsoleColor("lightcyan");
    cout << Staff::getCount() << endl;
    setConsoleColor("white");
    cout << "Total People: ";
    setConsoleColor("lightcyan");
    cout << Person::getCount() << endl;
    resetConsoleColor();

    Utility::print_success_message("Press any key to continue...");
    getch();
}

// MAIN MENU
void main_menu()
{
    char choice;
    do
    {
        vector<string> options = {
            "Enter Data",
            "View Data",
            "Modify Data",
            "System Statistics",
            "Exit Program"};        Utility::print_menu_box("SCHOOL MANAGEMENT SYSTEM", options);
        setConsoleColor("yellow");
        cout << "Enter your choice (1-5): ";
        resetConsoleColor();
        cin >> choice;

        switch (choice)
        {
        case '1':
            enter_data_menu();
            break;
        case '2':
            get_data_menu();
            break;
        case '3':
            modify_data_menu();
            break;
        case '4':
            display_system_stats();
            break;        case '5':
            Utility::print_header("PROGRAM EXIT");
            setConsoleColor("lightcyan");
            cout << "Thank you for using School Management System!" << endl;
            resetConsoleColor();
            Utility::print_success_message("Program terminated successfully!");
            getch();
            break;        default:
            Utility::print_error_message("Invalid choice! Please select 1-5.");
            setConsoleColor("yellow");
            cout << "\nPress any key to continue...";
            resetConsoleColor();
            getch();
        }
    } while (choice != '5');
}

int main()
{
    system("cls");
    for (int i = 0; i < 100; i++)
    {
        data[i] = nullptr;
    }
    main_menu();

    for (int i = 0; i < 100; i++)
    {
        delete data[i];
    }
    delete[] data;
}