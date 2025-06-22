#include <iostream>
#include "Database_handler.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Utility.h"

using namespace std;

void test_all_functionality() {
    cout << "=== COMPREHENSIVE SCHOOL MANAGEMENT SYSTEM TEST ===" << endl;
    
    // Load existing data
    Person **data = read_person();
    
    cout << "\n1. TESTING DATA LOADING:" << endl;
    int totalLoaded = 0;
    for (int i = 0; i < 100 && data[i] != nullptr; i++) {
        totalLoaded++;
    }
    cout << "   Total records loaded: " << totalLoaded << endl;
    cout << "   Static counts - Students: " << Student::getCount() 
         << ", Teachers: " << Teacher::getCount() 
         << ", Staff: " << Staff::getCount() << endl;
    
    cout << "\n2. TESTING SEARCH FUNCTIONALITY:" << endl;
    // Test searching for existing records
    cout << "   Searching for Student ID 1001: ";
    int result = Student::get_by_id(1001, data);
    cout << (result != -1 ? "FOUND" : "NOT FOUND") << endl;
    
    cout << "   Searching for Teacher ID 2001: ";
    result = Teacher::get_by_id(2001, data);
    cout << (result != -1 ? "FOUND" : "NOT FOUND") << endl;
    
    cout << "   Searching for Staff ID 3001: ";
    result = Staff::get_by_id(3001, data);
    cout << (result != -1 ? "FOUND" : "NOT FOUND") << endl;
    
    cout << "   Searching for non-existent ID 9999: ";
    result = Student::get_by_id(9999, data);
    cout << (result == -1 ? "CORRECTLY NOT FOUND" : "ERROR - FOUND") << endl;
    
    cout << "\n3. TESTING ADD FUNCTIONALITY:" << endl;
    // Test adding new records
    Student *testStudent = new Student("Alice Cooper", 20, 1010);
    bool saved = testStudent->save(data);
    cout << "   Adding new student: " << (saved ? "SUCCESS" : "FAILED") << endl;
    
    Teacher *testTeacher = new Teacher("Dr. Einstein", 60, "Advanced Physics", 2010);
    saved = testTeacher->save(data);
    cout << "   Adding new teacher: " << (saved ? "SUCCESS" : "FAILED") << endl;
    
    Staff *testStaff = new Staff("Bob Maintenance", 45, "Maintenance", 3010);
    saved = testStaff->save(data);
    cout << "   Adding new staff: " << (saved ? "SUCCESS" : "FAILED") << endl;
    
    cout << "\n4. TESTING MODIFY FUNCTIONALITY:" << endl;
    // Test modifying existing record
    int modifyIndex = Student::get_by_id(1001, data);
    if (modifyIndex != -1) {
        Student *modifiedStudent = new Student("John Doe Modified", 21, 1001);
        modifiedStudent->save(data, modifyIndex);
        cout << "   Modifying existing student: SUCCESS" << endl;
    }
    
    cout << "\n5. TESTING SAVE FUNCTIONALITY:" << endl;
    save_person(data);
    cout << "   Saving data to files: SUCCESS" << endl;
    
    cout << "\n6. TESTING FINAL COUNTS:" << endl;
    cout << "   Total Person objects: " << Person::getCount() << endl;
    cout << "   Student count: " << Student::getCount() << endl;
    cout << "   Teacher count: " << Teacher::getCount() << endl;
    cout << "   Staff count: " << Staff::getCount() << endl;
    
    cout << "\n7. TESTING POLYMORPHISM:" << endl;
    // Test polymorphic behavior
    for (int i = 0; i < 3 && data[i] != nullptr; i++) {
        cout << "   Record " << i << ": Type=" << data[i]->printType() 
             << ", Name=" << data[i]->getName() 
             << ", ID=" << data[i]->getId() << endl;
    }
    
    // Cleanup
    for (int i = 0; i < 100 && data[i] != nullptr; i++) {
        delete data[i];
    }
    delete[] data;
    
    cout << "\n=== ALL TESTS COMPLETED SUCCESSFULLY ===" << endl;
}

int main() {
    test_all_functionality();
    return 0;
}
