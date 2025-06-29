#include "../include/Person.h"
#include "../include/Student.h"
#include "../include/Teacher.h"
#include "../include/Staff.h"
#include "../include/Utility.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>  // For getch()

using namespace std;

// Global settings
bool pauseAfterEachTest = false;
int testsRun = 0;
int testsPassed = 0;
int testsFailed = 0;

// Test framework functions
void pauseIfRequested() {
    if (pauseAfterEachTest) {
        cout << "\nPress any key to continue...";
        getch();
        cout << "\n" << endl;
    }
}

void printTestHeader(const string& testName) {
    cout << "\n" << string(60, '=') << endl;
    cout << "UNIT TEST: " << testName << endl;
    cout << string(60, '=') << endl;
    cout << "What this test will do: Testing " << testName << " functionality" << endl;
    cout << "Starting test..." << endl;
}

void printTestResult(const string& testName, bool passed, const string& details = "") {
    testsRun++;
    if (passed) {
        testsPassed++;
        cout << "[PASSED]: " << testName;
        if (!details.empty()) cout << " - " << details;
        cout << endl;
    } else {
        testsFailed++;
        cout << "[FAILED]: " << testName;
        if (!details.empty()) cout << " - " << details;
        cout << endl;
    }
    pauseIfRequested();
}

void printSubTest(const string& action, bool result, const string& expected = "") {
    cout << "  -> " << action << ": ";
    if (result) {
        cout << "[SUCCESS]";
        if (!expected.empty()) cout << " (Got: " << expected << ")";
    } else {
        cout << "[FAIL]";
        if (!expected.empty()) cout << " (Expected: " << expected << ")";
    }
    cout << endl;
}

// Unit Tests
bool testPersonBasicFunctionality() {
    printTestHeader("Person Basic Functionality");
    cout << "Testing Person class setters and getters using Student implementation..." << endl;
    
    bool allPassed = true;
    Student testStudent;
    
    // Test name functionality
    cout << "\n1. Testing name setter/getter:" << endl;
    testStudent.setName("John Doe");
    bool nameTest = (testStudent.getName() == "John Doe");
    printSubTest("Set name to 'John Doe'", nameTest, testStudent.getName());
    allPassed &= nameTest;
    
    // Test age functionality
    cout << "\n2. Testing age setter/getter:" << endl;
    testStudent.setAge(20);
    bool ageTest = (testStudent.getAge() == 20);
    printSubTest("Set age to 20", ageTest, to_string(testStudent.getAge()));
    allPassed &= ageTest;
    
    // Test phone functionality
    cout << "\n3. Testing phone setter/getter:" << endl;
    testStudent.setPhone("123-456-7890");
    bool phoneTest = (testStudent.getPhone() == "123-456-7890");
    printSubTest("Set phone to '123-456-7890'", phoneTest, testStudent.getPhone());
    allPassed &= phoneTest;
    
    // Test address functionality
    cout << "\n4. Testing address setter/getter:" << endl;
    testStudent.setAddress("123 Main St");
    bool addressTest = (testStudent.getAddress() == "123 Main St");
    printSubTest("Set address to '123 Main St'", addressTest, testStudent.getAddress());
    allPassed &= addressTest;
    
    printTestResult("Person Basic Functionality", allPassed);
    return allPassed;
}

bool testStudentSpecificFunctionality() {
    printTestHeader("Student Specific Functionality");
    cout << "Testing Student class specific methods and polymorphism..." << endl;
    
    bool allPassed = true;
    Student testStudent;
    
    // Test student ID
    cout << "\n1. Testing Student ID functionality:" << endl;
    testStudent.setStudentId(12345);
    bool idTest = (testStudent.getStudentId() == 12345);
    printSubTest("Set student ID to 12345", idTest, to_string(testStudent.getStudentId()));
    allPassed &= idTest;
    
    // Test polymorphic ID getter
    cout << "\n2. Testing polymorphic ID getter:" << endl;
    bool polymorphicIdTest = (testStudent.getId() == 12345);
    printSubTest("Get ID through base class method", polymorphicIdTest, to_string(testStudent.getId()));
    allPassed &= polymorphicIdTest;
    
    // Test type identification
    cout << "\n3. Testing type identification:" << endl;
    bool typeTest = (testStudent.printType() == "Student");
    printSubTest("Check if type is 'Student'", typeTest, testStudent.printType());
    allPassed &= typeTest;
    
    // Test static count
    cout << "\n4. Testing static count functionality:" << endl;
    int initialCount = Student::getCount();
    Student* tempStudent = new Student();
    bool countTest = (Student::getCount() == initialCount + 1);
    printSubTest("Create new student and check count increase", countTest, 
                 "Count: " + to_string(Student::getCount()));
    delete tempStudent;
    allPassed &= countTest;
    
    printTestResult("Student Specific Functionality", allPassed);
    return allPassed;
}

bool testTeacherSpecificFunctionality() {
    printTestHeader("Teacher Specific Functionality");
    cout << "Testing Teacher class specific methods..." << endl;
    
    bool allPassed = true;
    Teacher testTeacher;
    
    // Test inherited functionality
    cout << "\n1. Testing inherited Person functionality:" << endl;
    testTeacher.setName("Dr. Smith");
    testTeacher.setAge(45);
    bool inheritedTest = (testTeacher.getName() == "Dr. Smith" && testTeacher.getAge() == 45);
    printSubTest("Set name and age through inheritance", inheritedTest, 
                 testTeacher.getName() + ", age " + to_string(testTeacher.getAge()));
    allPassed &= inheritedTest;
    
    // Test teacher ID
    cout << "\n2. Testing Teacher ID functionality:" << endl;
    testTeacher.setTeacherId(67890);
    bool idTest = (testTeacher.getTeacherId() == 67890);
    printSubTest("Set teacher ID to 67890", idTest, to_string(testTeacher.getTeacherId()));
    allPassed &= idTest;
    
    // Test subject
    cout << "\n3. Testing subject functionality:" << endl;
    testTeacher.setSubject("Computer Science");
    bool subjectTest = (testTeacher.getSubject() == "Computer Science");
    printSubTest("Set subject to 'Computer Science'", subjectTest, testTeacher.getSubject());
    allPassed &= subjectTest;
    
    // Test type identification
    cout << "\n4. Testing type identification:" << endl;
    bool typeTest = (testTeacher.printType() == "Teacher");
    printSubTest("Check if type is 'Teacher'", typeTest, testTeacher.printType());
    allPassed &= typeTest;
    
    printTestResult("Teacher Specific Functionality", allPassed);
    return allPassed;
}

bool testStaffSpecificFunctionality() {
    printTestHeader("Staff Specific Functionality");
    cout << "Testing Staff class specific methods..." << endl;
    
    bool allPassed = true;
    Staff testStaff;
    
    // Test inherited functionality
    cout << "\n1. Testing inherited Person functionality:" << endl;
    testStaff.setName("Maria Garcia");
    testStaff.setAge(35);
    bool inheritedTest = (testStaff.getName() == "Maria Garcia" && testStaff.getAge() == 35);
    printSubTest("Set name and age through inheritance", inheritedTest, 
                 testStaff.getName() + ", age " + to_string(testStaff.getAge()));
    allPassed &= inheritedTest;
    
    // Test staff ID
    cout << "\n2. Testing Staff ID functionality:" << endl;
    testStaff.setStaffId(11111);
    bool idTest = (testStaff.getStaffId() == 11111);
    printSubTest("Set staff ID to 11111", idTest, to_string(testStaff.getStaffId()));
    allPassed &= idTest;
    
    // Test designation
    cout << "\n3. Testing designation functionality:" << endl;
    testStaff.setDesignation("Administrator");
    bool designationTest = (testStaff.getDesignation() == "Administrator");
    printSubTest("Set designation to 'Administrator'", designationTest, testStaff.getDesignation());
    allPassed &= designationTest;
    
    // Test type identification
    cout << "\n4. Testing type identification:" << endl;
    bool typeTest = (testStaff.printType() == "Staff");
    printSubTest("Check if type is 'Staff'", typeTest, testStaff.printType());
    allPassed &= typeTest;
    
    printTestResult("Staff Specific Functionality", allPassed);
    return allPassed;
}

bool testPolymorphism() {
    printTestHeader("Polymorphism Testing");
    cout << "Testing virtual function calls through base class pointers..." << endl;
    
    bool allPassed = true;
    
    cout << "\n1. Creating objects through base pointers:" << endl;
    Person* student = new Student();
    Person* teacher = new Teacher();
    Person* staff = new Staff();
    printSubTest("Create Student, Teacher, Staff through Person pointers", true);
    
    cout << "\n2. Testing virtual function calls:" << endl;
    student->setName("Alice");
    teacher->setName("Bob");
    staff->setName("Charlie");
    
    bool nameTest = (student->getName() == "Alice" && 
                     teacher->getName() == "Bob" && 
                     staff->getName() == "Charlie");
    printSubTest("Set names through base pointers", nameTest);
    allPassed &= nameTest;
    
    cout << "\n3. Testing virtual type identification:" << endl;
    bool typeTest = (student->printType() == "Student" && 
                     teacher->printType() == "Teacher" && 
                     staff->printType() == "Staff");
    printSubTest("Get types through base pointers", typeTest);
    allPassed &= typeTest;
    
    cout << "\n4. Cleaning up polymorphic objects:" << endl;
    delete student;
    delete teacher;
    delete staff;
    printSubTest("Delete objects through base pointers", true);
    
    printTestResult("Polymorphism Testing", allPassed);
    return allPassed;
}

bool testUtilityFunctions() {
    printTestHeader("Utility Functions Testing");
    cout << "Testing Utility class static methods..." << endl;
    
    bool allPassed = true;
    
    cout << "\n1. Testing print functions (should not crash):" << endl;
    try {
        Utility::print_line(30);
        printSubTest("print_line(30)", true);
        
        Utility::print_dashed_line(25);
        printSubTest("print_dashed_line(25)", true);
        
        Utility::print_header("Test Header");
        printSubTest("print_header with test message", true);
        
        Utility::print_success_message("Test success");
        printSubTest("print_success_message", true);
        
        Utility::print_error_message("Test error");
        printSubTest("print_error_message", true);
        
        Utility::print_info_box("Test info");
        printSubTest("print_info_box", true);
        
        vector<string> testOptions = {"Option 1", "Option 2", "Exit"};
        Utility::print_menu_box("Test Menu", testOptions);
        printSubTest("print_menu_box with options", true);
        
    } catch (...) {
        printSubTest("Utility functions execution", false, "Exception occurred");
        allPassed = false;
    }
    
    printTestResult("Utility Functions Testing", allPassed);
    return allPassed;
}

bool testEdgeCases() {
    printTestHeader("Edge Cases Testing");
    cout << "Testing edge cases and boundary conditions..." << endl;
    
    bool allPassed = true;
    Student testStudent;
    
    cout << "\n1. Testing empty string handling:" << endl;
    testStudent.setName("");
    testStudent.setPhone("");
    testStudent.setAddress("");
    bool emptyStringTest = (testStudent.getName() == "" && 
                           testStudent.getPhone() == "" && 
                           testStudent.getAddress() == "");
    printSubTest("Set empty strings", emptyStringTest);
    allPassed &= emptyStringTest;
    
    cout << "\n2. Testing zero value handling:" << endl;
    testStudent.setAge(0);
    testStudent.setStudentId(0);
    bool zeroValueTest = (testStudent.getAge() == 0 && testStudent.getStudentId() == 0);
    printSubTest("Set zero values", zeroValueTest);
    allPassed &= zeroValueTest;
    
    cout << "\n3. Testing large values:" << endl;
    testStudent.setAge(999);
    testStudent.setStudentId(999999);
    bool largeValueTest = (testStudent.getAge() == 999 && testStudent.getStudentId() == 999999);
    printSubTest("Set large values", largeValueTest);
    allPassed &= largeValueTest;
    
    cout << "\n4. Testing special characters in strings:" << endl;
    testStudent.setName("John O'Connor-Smith");
    testStudent.setPhone("+1 (555) 123-4567 ext.890");
    bool specialCharTest = (testStudent.getName() == "John O'Connor-Smith" && 
                           testStudent.getPhone() == "+1 (555) 123-4567 ext.890");
    printSubTest("Set strings with special characters", specialCharTest);
    allPassed &= specialCharTest;
    
    printTestResult("Edge Cases Testing", allPassed);
    return allPassed;
}

int main() {
    cout << string(80, '=') << endl;
    cout << "         SCHOOL MANAGEMENT SYSTEM - UNIT TEST SUITE" << endl;
    cout << string(80, '=') << endl;
    cout << "This test suite will perform comprehensive unit testing of all classes." << endl;
    cout << "Each test will show what it's going to do, perform the test, and report results." << endl;
    
    // Ask user about pause preference
    cout << "\nDo you want to pause after each test? (y/n): ";
    char choice;
    cin >> choice;
    pauseAfterEachTest = (choice == 'y' || choice == 'Y');
    
    cout << "\nStarting unit tests..." << endl;
    if (pauseAfterEachTest) {
        cout << "Note: You will be prompted to press a key after each test." << endl;
    }
    
    // Run all unit tests
    testPersonBasicFunctionality();
    testStudentSpecificFunctionality();
    testTeacherSpecificFunctionality();
    testStaffSpecificFunctionality();
    testPolymorphism();
    testUtilityFunctions();
    testEdgeCases();
    
    // Print final summary
    cout << "\n" << string(80, '=') << endl;
    cout << "                        UNIT TEST SUMMARY" << endl;
    cout << string(80, '=') << endl;
    cout << "Total tests run: " << testsRun << endl;
    cout << "Tests passed: " << testsPassed << " [PASS]" << endl;
    cout << "Tests failed: " << testsFailed << " [FAIL]" << endl;
    cout << "Success rate: " << (testsRun > 0 ? (testsPassed * 100 / testsRun) : 0) << "%" << endl;
    
    if (testsFailed == 0) {
        cout << "\n*** ALL UNIT TESTS PASSED! The system components are working correctly. ***" << endl;
        return 0;
    } else {
        cout << "\n*** Some unit tests failed. Please review the failed components. ***" << endl;
        return 1;
    }
}
