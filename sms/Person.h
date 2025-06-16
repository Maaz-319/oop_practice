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
public:
    Person(string name, int age);
    virtual void printDetails() = 0;
    virtual string getName();
    virtual int getAge();
    virtual string printType();
    static int getCount();
    virtual int getId();
    virtual ~Person();
};
#endif