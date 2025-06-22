#include <iostream>
#include "Database_handler.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"

using namespace std;

int main() {
    cout << "Loading data..." << endl;
    Person **data = read_person();
    
    cout << "Checking loaded data:" << endl;
    for (int i = 0; i < 10 && data[i] != nullptr; i++) {
        cout << "Index " << i << ": " << data[i]->printType() 
             << " - " << data[i]->getName() 
             << " (ID: " << data[i]->getId() << ")" << endl;
    }
    
    cout << "\nTesting search for student 1001:" << endl;
    int index = Student::get_by_id(1001, data);
    cout << "Result: " << index << endl;
    
    cout << "\nTesting search for student 9999:" << endl;
    index = Student::get_by_id(9999, data);
    cout << "Result: " << index << endl;
    
    // Clean up
    for (int i = 0; i < 100 && data[i] != nullptr; i++) {
        delete data[i];
    }
    delete[] data;
    
    return 0;
}
