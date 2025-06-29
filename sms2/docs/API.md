# School Management System - API Documentation

## Overview
This document provides detailed API documentation for the School Management System classes and their methods. The system uses an object-oriented design with inheritance and polymorphism.

## Core Classes

### Person Class (Abstract Base Class)
Base class for all person entities in the system. This is an abstract class with pure virtual functions.

#### Private Attributes
- `static int count`: Static counter tracking total Person objects created

#### Protected Attributes  
- `string name`: Person's full name
- `int age`: Person's age
- `string type`: Type identifier for the person
- `string phone`: Phone number (flexible format)
- `string address`: Complete physical address

#### Methods

##### Constructors & Destructors
```cpp
Person();                    // Default constructor (increments count)
virtual ~Person();           // Virtual destructor for proper cleanup
```

##### Pure Virtual Methods
```cpp
virtual void printDetails() = 0;  // Must be implemented by derived classes
```

##### Virtual Getters
```cpp
virtual string getName();         // Get person's name
virtual int getAge();            // Get person's age  
virtual string printType();      // Get person type ("Student", "Teacher", "Staff")
virtual string getPhone();       // Get phone number
virtual string getAddress();     // Get address
virtual int getId();             // Get ID (implementation varies by derived class)
```

##### Static Methods
```cpp
static int getCount();           // Get total count of Person objects created
```

##### Virtual Setters (Person Attributes)
```cpp
virtual void setName(const string& name);      // Set person's name
virtual void setAge(int age);                  // Set person's age
virtual void setType(const string& type);      // Set person type
virtual void setPhone(const string& phone);    // Set phone number
virtual void setAddress(const string& address); // Set address
```

##### Virtual Setters (Derived Class Attributes - Empty Implementations)
```cpp
virtual void setStudentId(int id) {}                        // For Student class
virtual void setTeacherId(int id) {}                        // For Teacher class
virtual void setSubject(const string& subject) {}           // For Teacher class
virtual void setStaffId(int id) {}                          // For Staff class
virtual void setDesignation(const string& designation) {}   // For Staff class
```

---

### Student Class
Inherits from Person. Represents a student in the system.

#### Private Attributes
- `int stud_id`: Unique student ID number
- `static int count`: Static counter for Student objects
- `string type`: Type identifier (set to "Student")

#### Methods

##### Constructors & Destructors
```cpp
Student();                   // Default constructor
virtual ~Student();          // Virtual destructor
```

##### Overridden Virtual Methods
```cpp
void printDetails() override;    // Display student information to console
string printType() override;     // Returns "Student"
int getId() override;           // Returns student ID
```

##### Student-Specific Getters
```cpp
int getStudentId() const;       // Get student ID number
```

##### Student-Specific Setters
```cpp
void setStudentId(int id) override;  // Set student ID number
```

##### Static Methods
```cpp
static int getCount();          // Get count of Student objects created
```

##### Database Operations
```cpp
static int get_by_id(int id, Person **data);  // Find student by ID in data array
bool save(Person **data, int index = -1);     // Save student to data array
```

---

### Teacher Class
Inherits from Person. Represents a teacher in the system.

#### Private Attributes
- `string subject`: Subject taught by the teacher
- `int teacher_id`: Unique teacher ID number
- `static int count`: Static counter for Teacher objects

#### Methods

##### Constructors & Destructors
```cpp
Teacher();                   // Default constructor
virtual ~Teacher();          // Virtual destructor
```

##### Overridden Virtual Methods
```cpp
void printDetails() override;    // Display teacher information to console
string printType() override;     // Returns "Teacher"
int getId() override;           // Returns teacher ID
```

##### Teacher-Specific Getters
```cpp
int getTeacherId() const;       // Get teacher ID number
string getSubject() const;      // Get subject taught
```

##### Teacher-Specific Setters
```cpp
void setTeacherId(int id) override;              // Set teacher ID number
void setSubject(const string& subject) override; // Set subject taught
```

##### Static Methods
```cpp
static int getCount();          // Get count of Teacher objects created
```

##### Database Operations
```cpp
static int get_by_id(int id, Person **data);  // Find teacher by ID in data array
bool save(Person **data, int index = -1);     // Save teacher to data array
```

---

### Staff Class
Inherits from Person. Represents administrative staff.

#### Private Attributes
- `string designation`: Job designation/title
- `int staff_id`: Unique staff ID number
- `string type`: Type identifier (set to "Staff")
- `static int count`: Static counter for Staff objects

#### Methods

##### Constructors & Destructors
```cpp
Staff();                     // Default constructor
virtual ~Staff();            // Virtual destructor
```

##### Overridden Virtual Methods
```cpp
void printDetails() override;    // Display staff information to console
string printType() override;     // Returns "Staff"
int getId() override;           // Returns staff ID
```

##### Staff-Specific Getters
```cpp
int getStaffId() const;         // Get staff ID number
virtual string getDesignation(); // Get job designation
```

##### Staff-Specific Setters
```cpp
void setStaffId(int staff_id) override;                      // Set staff ID number
void setDesignation(const string& designation) override;     // Set job designation
```

##### Static Methods
```cpp
static int getCount();          // Get count of Staff objects created
```

##### Database Operations
```cpp
static int get_by_id(int id, Person **data);  // Find staff by ID in data array
bool save(Person **data, int index = -1);     // Save staff to data array
```

---

## Database Handler

### Database Functions
Simple file-based database operations for Person objects.

#### File Operations
```cpp
void save_person(Person **person);  // Save array of Person objects to respective files
Person **read_person();             // Read Person objects from files into array
```

#### File Structure
- **data/students.txt**: Student records storage
- **data/teachers.txt**: Teacher records storage  
- **data/staff.txt**: Staff records storage

---

## Utility Class

### Utility
Provides static helper functions for console formatting and display.

#### Console Formatting Methods
```cpp
static void print_line(int length);                                          // Print horizontal line
static void print_dashed_line(int length);                                  // Print dashed line
static void print_header(const string& title);                              // Print formatted header
static void print_menu_box(const string& title, const vector<string>& options); // Print menu with options
```

#### Message Display Methods
```cpp
static void print_success_message(const string& message);  // Display success message with formatting
static void print_error_message(const string& message);    // Display error message with formatting
static void print_info_box(const string& message);         // Display info message in box format
```

#### Class Design
```cpp
Utility() = delete;  // Constructor deleted - utility class with only static methods
```

---

## Polymorphism and Inheritance

### Virtual Function Behavior
- **printDetails()**: Each derived class implements its own version
- **printType()**: Returns appropriate type string for each class
- **getId()**: Returns the appropriate ID field for each derived class

### Static Counting System
- Each class maintains its own static count
- Person::getCount() returns total of all Person-derived objects
- Individual class counts available through respective getCount() methods

### Memory Management
- Virtual destructors ensure proper cleanup through base pointers
- Dynamic allocation and deletion fully supported
- RAII principles followed throughout the design

---

## Usage Examples

### Creating Objects
```cpp
// Create objects
Student student;
Teacher teacher; 
Staff staff;

// Set common Person attributes
student.setName("John Doe");
student.setAge(20);
student.setPhone("555-0123");
student.setAddress("123 Main St");

// Set specific attributes
student.setStudentId(12345);
teacher.setTeacherId(67890);
teacher.setSubject("Computer Science");
staff.setStaffId(11111);
staff.setDesignation("Administrator");
```

### Polymorphic Usage
```cpp
// Use base class pointers
Person* people[3];
people[0] = new Student();
people[1] = new Teacher();
people[2] = new Staff();

// Polymorphic method calls
for (int i = 0; i < 3; i++) {
    people[i]->setName("Person " + to_string(i));
    cout << people[i]->printType() << endl;  // Prints correct type
    people[i]->printDetails();               // Calls correct implementation
}

// Proper cleanup
for (int i = 0; i < 3; i++) {
    delete people[i];
}
```

### Database Operations
```cpp
// Create data array
Person** data = new Person*[10];
for (int i = 0; i < 10; i++) data[i] = nullptr;

// Add objects
data[0] = new Student();
data[0]->setName("Alice");
data[0]->setStudentId(1001);

// Save to files
save_person(data);

// Read from files
Person** loaded_data = read_person();
```