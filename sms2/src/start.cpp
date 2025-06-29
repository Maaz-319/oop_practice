#include <iostream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <string>

#include "Utility.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Database_handler.h"

using namespace std;

Person **data = new Person *[100];

// FUNCTIONS FOR ENTER DATA
void add_student()
{
    Utility::print_header("ADD NEW STUDENT");
    string name, address, phone;
    int age, id;
    cout << "Student Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Student Age: ";
    cin >> age;
    cout << "Phone: ";
    cin.ignore();
    getline(cin, phone);
    cout << "Address: ";
    getline(cin, address);
    cout << "Student ID: ";
    cin >> id;
    
    Student *student = new Student();
    student->setName(name);
    student->setAge(age);
    student->setPhone(phone);
    student->setAddress(address);
    student->setStudentId(id);
    
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
    string name, subject, address, phone;
    int age, id;
    cout << "Teacher Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Teacher Age: ";
    cin >> age;
    cout << "Phone: ";
    cin.ignore();
    getline(cin, phone);
    cout << "Address: ";
    getline(cin, address);
    cout << "Subject: ";
    getline(cin, subject);
    cout << "Teacher ID: ";
    cin >> id;
    
    Teacher *teacher = new Teacher();
    teacher->setName(name);
    teacher->setAge(age);
    teacher->setPhone(phone);
    teacher->setAddress(address);
    teacher->setSubject(subject);
    teacher->setTeacherId(id);
    
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
    string designation, name, address, phone;
    int age, id;
    cout << "Staff Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Staff Age: ";
    cin >> age;
    cout << "Phone: ";
    cin.ignore();
    getline(cin, phone);
    cout << "Address: ";
    getline(cin, address);
    cout << "Designation: ";
    getline(cin, designation);
    cout << "Staff ID: ";
    cin >> id;
    
    Staff *staff = new Staff();
    staff->setName(name);
    staff->setAge(age);
    staff->setPhone(phone);
    staff->setAddress(address);
    staff->setDesignation(designation);
    staff->setStaffId(id);
    
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
    cout << "Enter ID to find: ";
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
    cout << "Enter ID to find: ";
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
    cout << "Enter ID to find: ";
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
    string name, address, phone;
    int age;
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Student Age: ";
    cin >> age;
    cout << "Enter Phone: ";
    cin.ignore();
    getline(cin, phone);
    cout << "Enter Address: ";
    getline(cin, address);
    
    Student *student = new Student();
    student->setName(name);
    student->setAge(age);
    student->setPhone(phone);
    student->setAddress(address);
    student->setStudentId(id);
    
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
    string name, subject, address, phone;
    int age;
    cout << "Enter Teacher Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Teacher Age: ";
    cin >> age;
    cout << "Enter Phone: ";
    cin.ignore();
    getline(cin, phone);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Subject: ";
    getline(cin, subject);
    
    Teacher *teacher = new Teacher();
    teacher->setName(name);
    teacher->setAge(age);
    teacher->setPhone(phone);
    teacher->setAddress(address);
    teacher->setSubject(subject);
    teacher->setTeacherId(id);
    
    teacher->save(data, index);
    Utility::print_success_message("Teacher data modified successfully!");
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
    string name, designation, address, phone;
    int age;
    cout << "Enter Staff Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Staff Age: ";
    cin >> age;
    cout << "Enter Phone: ";
    cin.ignore();
    getline(cin, phone);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Designation: ";
    getline(cin, designation);
    
    Staff *staff = new Staff();
    staff->setName(name);
    staff->setAge(age);
    staff->setPhone(phone);
    staff->setAddress(address);
    staff->setDesignation(designation);
    staff->setStaffId(id);
    
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
            "Back to Main Menu"};

        Utility::print_menu_box("ENTER DATA MENU", options);
        cout << "Enter your choice (1-4): ";
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
            "Back to Main Menu"};

        Utility::print_menu_box("VIEW DATA MENU", options);
        cout << "Enter your choice (1-4): ";
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
            "Back to Main Menu"};

        Utility::print_menu_box("MODIFY DATA MENU", options);
        cout << "Enter your choice (1-4): ";
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

    cout << "Database Status:" << endl;
    Utility::print_dashed_line(20);
    cout << "Total Records: " << Person::getCount() << "/100" << endl;
    cout << "Available Slots: " << (100 - Person::getCount()) << endl;
    cout << "Memory Usage: " << (Person::getCount() * 100.0 / 100) << "%" << endl;

    cout << "\nRecord Distribution:" << endl;
    Utility::print_dashed_line(25);
    cout << "Students: " << Student::getCount() << endl;
    cout << "Teachers: " << Teacher::getCount() << endl;
    cout << "Staff: " << Staff::getCount() << endl;
    cout << "Total People: " << Person::getCount() << endl;

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
            "Exit Program"};

        Utility::print_menu_box("SCHOOL MANAGEMENT SYSTEM", options);
        cout << "Enter your choice (1-5): ";
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
            break;
        case '5':
            Utility::print_header("PROGRAM EXIT");
            cout << "Thank you for using School Management System!" << endl;
            Utility::print_success_message("Program terminated successfully!");
            save_person(data);
            getch();
            break;
        default:
            Utility::print_error_message("Invalid choice! Please select 1-5.");
            cout << "\nPress any key to continue...";
            getch();
        }
    } while (choice != '5');
}

int main()
{
    // getch();
    system("cls");

    data = read_person();
    main_menu();

    for (int i = 0; i < 100 && data[i] != nullptr; i++)
    {
        delete data[i];
    }
    delete[] data;

    return 0;
}