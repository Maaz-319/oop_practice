# School Management System

A comprehensive C++ console application for managing student, teacher, and staff records in educational institutions. Built with object-oriented programming principles, featuring polymorphism, inheritance, and file-based data persistence.

## 🌐 Connect & Follow

<div align="center">

### 📱 Social Media & Professional Networks

[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/maaz-319)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://linkedin.com/in/maazbinasif)
[![Instagram](https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://instagram.com/maaz.binasif)

### 💬 Get in Touch

**💼 Portfolio**: [portfolio.maaz.me](https://portfolio.maaz.me)  
**🌐 Website**: [maaz.me](https://maaz.me)
</div>

## 🎯 Overview

The School Management System is a robust console application that allows educational institutions to efficiently manage their personnel records. The system supports three types of users: Students, Teachers, and Staff members, each with their specific attributes and functionalities.

### Key Features

- **Multi-User Management**: Handle Students, Teachers, and Staff with dedicated workflows
- **Object-Oriented Design**: Built using C++ classes with inheritance and polymorphism
- **Data Persistence**: File-based storage system for permanent data retention
- **Interactive Console Interface**: User-friendly menu-driven navigation
- **Data Validation**: Input validation and error handling
- **Search & Modify**: Find and update records by unique ID
- **System Statistics**: Real-time database status and record distribution
- **Memory Management**: Efficient dynamic memory allocation and cleanup

### Technical Highlights

- **Inheritance Hierarchy**: Abstract `Person` base class with `Student`, `Teacher`, and `Staff` derived classes
- **Polymorphism**: Virtual functions for type-specific behavior
- **Static Counting**: Track object instances across all classes
- **File I/O**: Separate data files for each entity type
- **Utility System**: Formatted console output with professional styling

## 📋 System Requirements

### Runtime Requirements (Pre-built Executable)
- **OS**: Windows 7/10/11 (64-bit)
- **RAM**: 128 MB minimum
- **Storage**: 10 MB free space
- **Display**: Console/Terminal support

### Development Requirements (Source Compilation)
- **Compiler**: GCC 7.0+ / MSVC 2017+ / Clang 6.0+
- **C++ Standard**: C++11 or higher
- **OS**: Windows, Linux, or macOS
- **RAM**: 512 MB minimum (for compilation)

## 🚀 Quick Start

### Option 1: Run Pre-built Executable (Recommended)

If you don't have a C++ compiler installed, you can run the program directly:

```bash
# Navigate to build directory
cd build

# Run the application
.\sms.exe
```

### Option 2: Compile from Source

```bash
# Create build directory (if not exists)
mkdir build

# Compile the application
g++ -std=c++11 -Iinclude src/*.cpp -o build/sms.exe

# Run the application
cd build
.\sms.exe
```

### Option 3: Compile and Run Tests

```bash
# Compile unit tests
g++ -std=c++11 -Iinclude tests/UnitTest.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp src/Database_handler.cpp -o build/UnitTest.exe

# Compile integration tests
g++ -std=c++11 -Iinclude tests/IntegrationTest.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp src/Database_handler.cpp -o build/IntegrationTest.exe

# Run tests
cd build
.\UnitTest.exe
.\IntegrationTest.exe

# Or Run through a Testing Suite I created
cd build
RunTests.bat
```

## 📖 Usage Guide

### Main Menu Options

The system provides five main functions accessible through a menu-driven interface:

```
SCHOOL MANAGEMENT SYSTEM
========================
1. Enter Data
2. View Data  
3. Modify Data
4. System Statistics
5. Exit Program
```

### 1. Enter Data
Add new records to the system:

**Add Student**
- Student Name (Full name)
- Student Age (Numeric)
- Phone Number (Text format)
- Address (Complete address)
- Student ID (Unique identifier)

**Add Teacher**  
- Teacher Name (Full name)
- Teacher Age (Numeric)
- Phone Number (Text format)
- Address (Complete address)
- Subject (Teaching subject)
- Teacher ID (Unique identifier)

**Add Staff**
- Staff Name (Full name)
- Staff Age (Numeric)  
- Phone Number (Text format)
- Address (Complete address)
- Designation (Job title)
- Staff ID (Unique identifier)

### 2. View Data
Search and display existing records:

- **Student by ID**: Find and display student information
- **Teacher by ID**: Find and display teacher information  
- **Staff by ID**: Find and display staff information

### 3. Modify Data
Update existing records:

- **Modify Student**: Update student information by ID
- **Modify Teacher**: Update teacher information by ID
- **Modify Staff**: Update staff information by ID

### 4. System Statistics
View comprehensive system information:

- **Database Status**: Current capacity and usage
- **Available Slots**: Remaining storage capacity
- **Memory Usage**: System resource utilization
- **Record Distribution**: Count by entity type

### 5. Exit Program
Safely exit the application with automatic data saving.

## 🗂️ Data Storage

The system uses file-based storage with separate files for each entity type. The data directory is located in the project root, while executables are in the `build/` folder:

```
project-root/
├── data/                    # Data storage (project root)
│   ├── students.txt         # Student records
│   ├── teachers.txt         # Teacher records
│   └── staff.txt            # Staff records
└── build/                   # Compiled executables
    ├── sms.exe              # Main application
    ├── UnitTest.exe         # Unit tests
    └── IntegrationTest.exe  # Integration tests
```

### Data Persistence Features
- **Automatic Loading**: Data loaded on program start from `../data/` (relative to executable)
- **Automatic Saving**: Data saved on program exit to `../data/` directory
- **Directory Auto-Creation**: Data directory created automatically if missing
- **Data Integrity**: File validation and error handling
- **Capacity Management**: Maximum 100 total records
- **Cross-Platform Paths**: Works on Windows, Linux, and macOS

### Important Notes
- **Run from build/ directory**: `cd build && ./sms.exe` (recommended)
- **Run from project root**: `./build/sms.exe` (also works)
- **Data files**: Always stored in project-root/data/ regardless of execution location

## 🧪 Testing

The system includes comprehensive test suites for quality assurance. For detailed testing information, see [tests/README.md](tests/README.md).

### Available Test Executables
- **UnitTest.exe**: Component and class testing
- **IntegrationTest.exe**: System workflow and integration testing

### Quick Test Commands
```bash
cd build
.\UnitTest.exe      # Run unit tests
.\IntegrationTest.exe   # Run integration tests
```

## 📁 Project Structure

```
school-management-system/
├── 📄 README.md                     # Project documentation
├── 📄 .gitignore                    # Git exclusions
│
├── 📁 include/                      # Header files
│   ├── Person.h                     # Abstract base class
│   ├── Student.h                    # Student class declaration
│   ├── Teacher.h                    # Teacher class declaration
│   ├── Staff.h                      # Staff class declaration
│   ├── Database_handler.h           # File I/O operations
│   └── Utility.h                    # Console formatting utilities
│
├── 📁 src/                          # Source implementation
│   ├── start.cpp                    # Main application entry point
│   ├── Person.cpp                   # Person class implementation
│   ├── Student.cpp                  # Student class implementation
│   ├── Teacher.cpp                  # Teacher class implementation
│   ├── Staff.cpp                    # Staff class implementation
│   ├── Database_handler.cpp         # Database operations
│   └── Utility.cpp                  # Utility functions
│
├── 📁 build/                        # Compiled executables
│   ├── sms.exe                      # Main application
│   ├── UnitTest.exe                 # Unit test executable
│   ├── IntegrationTest.exe          # Integration test executable
│   └── RunTests.bat                 # Test automation script
│
├── 📁 data/                         # Data storage
│   ├── students.txt                 # Student records
│   ├── teachers.txt                 # Teacher records
│   └── staff.txt                    # Staff records
│
├── 📁 tests/                        # Test suites
│   ├── README.md                    # Testing documentation
│   ├── UnitTest.cpp                 # Unit test source
│   └── IntegrationTest.cpp          # Integration test source
│
└── 📁 docs/                         # Additional documentation
    ├── API.md                       # Class and method reference
    ├── UserManual.md                # Detailed user guide
    └── DeveloperGuide.md            # Development documentation
```

## 🔧 Development

### Code Architecture
- **Abstract Base Class**: `Person` with pure virtual functions
- **Derived Classes**: `Student`, `Teacher`, `Staff` with specific implementations
- **Polymorphism**: Virtual function overriding for type-specific behavior
- **Static Counting**: Class-level instance tracking
- **Memory Management**: RAII principles and proper cleanup

### Compilation Commands
```bash
# Debug build with all warnings
g++ -g -std=c++11 -Wall -Wextra -Iinclude src/*.cpp -o build/sms.exe

# Release build with optimizations  
g++ -O3 -DNDEBUG -std=c++11 -Iinclude src/*.cpp -o build/sms.exe

# Clean build
rm -rf build/*
mkdir build
```

## 🐛 Troubleshooting

### Common Issues

**Program Not Starting**
- Ensure `data/` directory exists
- Check file permissions for data files
- Verify executable permissions on `sms.exe`

**Data Not Saving**
- Check write permissions in `data/` directory  
- Ensure sufficient disk space
- Verify data files are not corrupted

**Compilation Errors**
- Ensure C++11 compiler support
- Check include path is correct (`-Iinclude`)
- Verify all source files are present

**Runtime Errors**
- Check system capacity (max 100 records)
- Validate input data format
- Ensure proper program termination

---

## 🤝 Support

For technical support, bug reports, or feature requests:
- Review the documentation in the `docs/` directory
- Check the testing guide in `tests/README.md`
- Examine the source code for implementation details

**Version**: 2.0.0  
**Last Updated**: June 2025  
**Compatibility**: C++11 and later

---

## Contributions
Contributions are welcome! Please follow these steps:
1. Fork the repository
2. Create a new branch for your feature or fix
3. Make your changes and commit them
4. Push to your fork
5. Create a pull request with a clear description of your changes
6. Wait for review and feedback
7. Address any comments or suggestions
8. Once approved, your changes will be merged into the main branch

Thank you for your interest in improving the School Management System! Your contributions help make this project better for everyone.
