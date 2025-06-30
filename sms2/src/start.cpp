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
#include <limits>

using namespace std;

Person **data = new Person *[100];
int *ids = new int[100];
int current_id;

int give_id()
{
    // Find the next available ID that's not already in use
    int next_id = current_id + 1;
    bool id_exists = true;
    
    while (id_exists) {
        id_exists = false;
        // Check if this ID already exists in data
        for (int i = 0; i < 100; i++) {
            if (data[i] != nullptr && data[i]->getId() == next_id) {
                id_exists = true;
                next_id++;
                break;
            }
        }
    }
    
    // Find first available slot in ids array
    for (int i = 0; i < 100; i++) {
        if (ids[i] == 0) {
            ids[i] = next_id;
            current_id = next_id;
            break;
        }
    }
    return current_id;
}

// FUNCTIONS FOR ENTER DATA
void add_student()
{
    Utility::print_header("ADD NEW STUDENT");
    string name, address, phone;
    int age, id;
    name = Utility::take_string_input("Student Name");
    age = Utility::take_integer_input(18, 25, "Student Age: ");
    phone = Utility::take_phone_input();
    address = Utility::take_string_input("Address: ");
    id = give_id();

    Student *student = new Student();
    student->setName(name);
    student->setAge(age);
    student->setPhone(phone);
    student->setAddress(address);
    student->setStudentId(id);

    if (student->save(data))
    {
        system("cls");
        student->printDetails();
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
    name = Utility::take_string_input("Teacher Name");
    age = Utility::take_integer_input(18, 25, "Teacher Age");
    phone = Utility::take_phone_input();
    address = Utility::take_string_input("Address");
    subject = Utility::take_string_input("Subject");
    id = give_id();

    Teacher *teacher = new Teacher();
    teacher->setName(name);
    teacher->setAge(age);
    teacher->setPhone(phone);
    teacher->setAddress(address);
    teacher->setSubject(subject);
    teacher->setTeacherId(id);

    if (teacher->save(data))
    {
        system("cls");
        teacher->printDetails();
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
    name = Utility::take_string_input("Staff Name");
    age = Utility::take_integer_input(18, 25, "Staff Age");
    phone = Utility::take_phone_input();
    address = Utility::take_string_input("Address");
    designation = Utility::take_string_input("Designation");
    id = give_id();

    Staff *staff = new Staff();
    staff->setName(name);
    staff->setAge(age);
    staff->setPhone(phone);
    staff->setAddress(address);
    staff->setDesignation(designation);
    staff->setStaffId(id);

    if (staff->save(data))
    {
        system("cls");
        staff->printDetails();
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
    id = Utility::take_integer_input(1, 10000, "ID to find");
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
    id = Utility::take_integer_input(1, 10000, "ID to find");
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
    id = Utility::take_integer_input(1, 10000, "ID to find");
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
    id = Utility::take_integer_input(1, 10000, "ID to modify");
    int index = Student::get_by_id(id, data);
    if (index == -1)
    {
        Utility::print_error_message("No student found with ID: " + to_string(id));
        return;
    }
    cout << "================================\n";
    string name, address, phone;
    int age;
    name = Utility::take_string_input("Student Name");
    age = Utility::take_integer_input(5, 100, "Student Age");
    phone = Utility::take_phone_input();
    address = Utility::take_string_input("Address");

    Student *student = new Student();
    student->setName(name);
    student->setAge(age);
    student->setPhone(phone);
    student->setAddress(address);
    student->setStudentId(id);

    // Delete old object to prevent memory leak
    delete data[index];
    student->save(data, index);
    Utility::print_success_message("Student data modified successfully!");
    getch();
}

void modify_teacher_data()
{
    Utility::print_header("MODIFY TEACHER DATA");

    int id;
    id = Utility::take_integer_input(1, 10000, "ID to modify");
    int index = Teacher::get_by_id(id, data);
    if (index == -1)
    {
        cout << "No Teacher found with ID: " << id << endl;
        return;
    }
    cout << "================================\n";
    string name, subject, address, phone;
    int age;
    name = Utility::take_string_input("Teacher Name");
    age = Utility::take_integer_input(5, 100, "Teacher Age");
    phone = Utility::take_phone_input();
    address = Utility::take_string_input("Address");
    subject = Utility::take_string_input("Subject");

    Teacher *teacher = new Teacher();
    teacher->setName(name);
    teacher->setAge(age);
    teacher->setPhone(phone);
    teacher->setAddress(address);
    teacher->setSubject(subject);
    teacher->setTeacherId(id);

    // Delete old object to prevent memory leak
    delete data[index];
    teacher->save(data, index);
    Utility::print_success_message("Teacher data modified successfully!");
    getch();
}

void modify_staff_data()
{
    Utility::print_header("MODIFY STAFF DATA");

    int id;
    id = Utility::take_integer_input(1, 10000, "ID to modify");
    int index = Staff::get_by_id(id, data);
    if (index == -1)
    {
        Utility::print_error_message("No Staff found with ID: " + to_string(id));
        return;
    }
    cout << "================================\n";
    string name, designation, address, phone;
    int age;
    name = Utility::take_string_input("Staff Name");
    age = Utility::take_integer_input(5, 100, "Staff Age");
    phone = Utility::take_phone_input();
    address = Utility::take_string_input("Address");
    designation = Utility::take_string_input("Designation");

    Staff *staff = new Staff();
    staff->setName(name);
    staff->setAge(age);
    staff->setPhone(phone);
    staff->setAddress(address);
    staff->setDesignation(designation);
    staff->setStaffId(id);

    // Delete old object to prevent memory leak
    delete data[index];
    staff->save(data, index);
    Utility::print_success_message("Staff data modified successfully!");
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

void delete_data()
{
    int type, id;
    string prompt;
    vector<string> options = {
        "Delete Student",
        "Delete Teacher",
        "Delete Staff"};

    Utility::print_menu_box("DELETE DATA", options);
    type = Utility::take_integer_input(1, 3, "Choice");

    if (type == 1)
    {
        prompt = "Student";
    }
    else if (type == 2)
    {
        prompt = "Teacher";
    }
    else if (type == 3)
    {
        prompt = "Staff";
    }
    else
    {
        Utility::print_error_message("Unable to Delete Data");
        return;
    }

    id = Utility::take_integer_input(1, 10000, prompt + " ID");
    bool found = false;

    for (int i = 0; i < 100; i++)
    {
        if (data[i] != nullptr && data[i]->getId() == id && data[i]->printType() == prompt)
        {
            found = true;
            char choice = 'a';
            Utility::print_success_message("FOUND " + to_string(id));
            getch();
            data[i]->printDetails();

            cout << "\nConfirm Deletion (y/n): ";
            while (!(cin >> choice) || (choice != 'y' && choice != 'n' && choice != 'N' && choice != 'Y'))
            {
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Confirm Deletion (y/n): ";
            }

            if (choice == 'y' || choice == 'Y')
            {
                delete data[i];
                data[i] = nullptr;
                Utility::print_success_message("Data Deleted Successfully!");
                getch();
            }
            else
            {
                Utility::print_success_message("Deletion Cancelled by User!");
                getch();
            }
            break;
        }
    }
    if (!found)
    {
        Utility::print_error_message("No " + prompt + " Found with ID: " + to_string(id));
        getch();
    }
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
            "Delete Data",
            "System Statistics",
            "Exit Program"};

        Utility::print_menu_box("SCHOOL MANAGEMENT SYSTEM", options);
        cout << "Enter your choice (1-6): ";
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
            delete_data();
            break;
        case '5':
            display_system_stats();
            break;
        case '6':
            Utility::print_header("PROGRAM EXIT");
            cout << "Thank you for using School Management System!" << endl;
            Utility::print_success_message("Program terminated successfully!");
            save_person(data);
            getch();
            break;
        default:
            Utility::print_error_message("Invalid choice! Please select 1-6.");
            cout << "\nPress any key to continue...";
            getch();
        }
    } while (choice != '6');
}

int main()
{
    // getch();
    system("cls");

    data = read_person(ids, current_id);
    main_menu();

    for (int i = 0; i < 100 && data[i] != nullptr; i++)
    {
        delete data[i];
    }
    delete[] data;

    return 0;
}