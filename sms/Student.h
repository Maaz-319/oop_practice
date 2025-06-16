#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

class Student : public Person {
private:
    int stud_id;
    static int count;
    string type;
public:
    Student(string name, int age, int stud_id);
    void printDetails() override;
    static int get_by_id(int id, Person **data);
    bool save(Person **data, int index = -1);
    string printType() override;
    static int getCount();
    int getId() override;
    virtual ~Student();
};
#endif
