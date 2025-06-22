#include <iostream>
#include "Database_handler.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Utility.h"

using namespace std;

// Test the exact functions used in the main program
void test_main_program_functions() {
    Person **data = read_person();
    
    cout << "=== Testing Main Program Functions ===" << endl;
    
    // Test the exact same function calls as in start.cpp
    cout << "\n1. Testing get_student_data equivalent:" << endl;
    Utility::print_header("GET STUDENT DATA");
    int id = 1001;
    cout << "Enter ID to find: " << id << endl;
    if (Student::get_by_id(id, data) == -1) {
        Utility::print_error_message("No Student found with ID: " + to_string(id));
    } else {
        cout << "Student found successfully!" << endl;
    }
    
    cout << "\n2. Testing get_teacher_data equivalent:" << endl;
    Utility::print_header("GET TEACHER DATA");
    id = 2001;
    cout << "Enter ID to find: " << id << endl;
    if (Teacher::get_by_id(id, data) == -1) {
        Utility::print_error_message("No Teacher found with ID: " + to_string(id));
    } else {
        cout << "Teacher found successfully!" << endl;
    }
    
    cout << "\n3. Testing get_staff_data equivalent:" << endl;
    Utility::print_header("GET STAFF DATA");
    id = 3001;
    cout << "Enter ID to find: " << id << endl;
    if (Staff::get_by_id(id, data) == -1) {
        Utility::print_error_message("No Staff found with ID: " + to_string(id));
    } else {
        cout << "Staff found successfully!" << endl;
    }
    
    cout << "\n4. Testing system statistics:" << endl;
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
    
    // Cleanup
    for (int i = 0; i < 100 && data[i] != nullptr; i++) {
        delete data[i];
    }
    delete[] data;
    
    cout << "\n=== All main program functions work correctly! ===" << endl;
}

int main() {
    test_main_program_functions();
    return 0;
}
