#include <iostream>
#include <cassert>
#include "Database_handler.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Utility.h"

using namespace std;

void test_data_loading() {
    cout << "=== Testing Data Loading ===" << endl;
    
    Person **data = read_person();
    
    // Test that data was loaded
    int studentCount = 0, teacherCount = 0, staffCount = 0;
    
    for (int i = 0; i < 100 && data[i] != nullptr; i++) {
        if (data[i]->printType() == "Student") studentCount++;
        else if (data[i]->printType() == "Teacher") teacherCount++;
        else if (data[i]->printType() == "Staff") staffCount++;
    }
    
    cout << "Students loaded: " << studentCount << endl;
    cout << "Teachers loaded: " << teacherCount << endl;
    cout << "Staff loaded: " << staffCount << endl;
    
    // Test searching functionality
    cout << "\n=== Testing Search Functionality ===" << endl;
    
    // Test finding existing student
    int index = Student::get_by_id(1001, data);
    cout << "Student 1001 found at index: " << index << endl;
    
    // Test finding non-existent student
    index = Student::get_by_id(9999, data);
    cout << "Student 9999 found at index: " << index << " (should be -1)" << endl;
    
    // Test finding existing teacher
    index = Teacher::get_by_id(2001, data);
    cout << "Teacher 2001 found at index: " << index << endl;
    
    // Test finding existing staff
    index = Staff::get_by_id(3001, data);
    cout << "Staff 3001 found at index: " << index << endl;
    
    // Test adding new records
    cout << "\n=== Testing Add Functionality ===" << endl;
    
    Student *newStudent = new Student("Test Student", 22, 1004);
    bool saved = newStudent->save(data);
    cout << "New student saved: " << (saved ? "YES" : "NO") << endl;
    
    Teacher *newTeacher = new Teacher("Test Teacher", 40, "Biology", 2004);
    saved = newTeacher->save(data);
    cout << "New teacher saved: " << (saved ? "YES" : "NO") << endl;
    
    Staff *newStaff = new Staff("Test Staff", 30, "Janitor", 3004);
    saved = newStaff->save(data);
    cout << "New staff saved: " << (saved ? "YES" : "NO") << endl;
    
    // Test saving to file
    cout << "\n=== Testing Save to File ===" << endl;
    save_person(data);
    cout << "Data saved to files." << endl;
    
    // Test counts
    cout << "\n=== Testing Static Counts ===" << endl;
    cout << "Total Person count: " << Person::getCount() << endl;
    cout << "Student count: " << Student::getCount() << endl;
    cout << "Teacher count: " << Teacher::getCount() << endl;
    cout << "Staff count: " << Staff::getCount() << endl;
    
    // Clean up
    for (int i = 0; i < 100 && data[i] != nullptr; i++) {
        delete data[i];
    }
    delete[] data;
    
    cout << "\n=== All Tests Completed ===" << endl;
}

int main() {
    test_data_loading();
    return 0;
}
