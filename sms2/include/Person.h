#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person {
private:
    static int count;
protected:
    string name;
    int age;
    string type;
    string phone;
    string address;
public:
    Person();  // Default constructor
    virtual void printDetails() = 0;
    
    // Getters
    virtual string getName();
    virtual int getAge();
    virtual string printType();
    virtual string getPhone();
    virtual string getAddress();
    static int getCount();
    virtual int getId();
    
    // Setters for Person attributes
    virtual void setName(const string& name);
    virtual void setAge(int age);
    virtual void setType(const string& type);
    virtual void setPhone(const string& phone);
    virtual void setAddress(const string& address);
    
    // Setters for derived class attributes
    virtual void setStudentId(int id) {}  // For Student
    virtual void setTeacherId(int id) {}  // For Teacher
    virtual void setSubject(const string& subject) {}  // For Teacher
    virtual void setStaffId(int id) {}  // For Staff
    virtual void setDesignation(const string& designation) {}  // For Staff
    
    virtual ~Person();
};
#endif