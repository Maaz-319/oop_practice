#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"

class Teacher : public Person {
private:
    string subject;
    int teacher_id;
    static int count;
    string type;
public:
    Teacher(string name, int age, string subject, int teacher_id);
    void printDetails() override;
    static int get_by_id(int id, Person **data);
    bool save(Person **data, int index = -1);
    string get_subject();
    string printType() override;
    static int getCount();
    int getId() override;
    virtual ~Teacher();
};
#endif
