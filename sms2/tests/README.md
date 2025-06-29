# Test Documentation

## Running Tests

Two comprehensive test suites have been created for the School Management System:

### 1. UnitTest.exe
- **Purpose**: Tests individual components and classes
- **Features**: 
  - Tests Person, Student, Teacher, Staff classes
  - Tests polymorphism and inheritance
  - Tests utility functions
  - Tests edge cases and boundary conditions
  - Interactive pause option after each test
- **Location**: `build/UnitTest.exe`
- **Run**: `.\UnitTest.exe` (from build directory)

### 2. IntegrationTest.exe  
- **Purpose**: Tests complete system workflow and component integration
- **Features**:
  - Complete person workflow testing
  - Utility system integration
  - File system and database integration
  - Complete system simulation
  - Stress and performance testing
  - Interactive pause option after each test
- **Location**: `build/IntegrationTest.exe`
- **Run**: `.\IntegrationTest.exe` (from build directory)

### 3. Test Runner (Optional)
- **Purpose**: Easy way to run tests with a menu
- **Location**: `build/RunTests.bat`
- **Run**: `.\RunTests.bat` (from build directory)

## Test Features

Both test suites include:

1. **Interactive Mode**: Ask user if they want to pause after each test
2. **Detailed Output**: Shows what each test will do before executing
3. **Step-by-step Execution**: Shows progress of each test operation
4. **Success/Failure Reporting**: Clear indication of test results
5. **Summary Statistics**: Total tests run, passed, failed, success rate
6. **Color-coded Results**: ✓ for success, ✗ for failure

## Compilation

Tests were compiled with:

> Unit Test
```bash
g++ -std=c++17 -I include -o build/UnitTest.exe tests/UnitTest.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp
```
> Integration Test
```bash
g++ -std=c++17 -I include -o build/IntegrationTest.exe tests/IntegrationTest.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp src/Database_handler.cpp
```

## Quick Start

1. Navigate to build directory: `cd build`
2. Run unit tests: `.\UnitTest.exe`
3. Run integration tests: `.\IntegrationTest.exe`
4. Or use the test runner: `.\RunTests.bat`

Both test executables will ask if you want to pause after each test - answer 'y' for yes or 'n' for no.