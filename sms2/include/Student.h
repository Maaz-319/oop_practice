#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

class Student : public Person {
private:
    int stud_id;
    static int count;
    string type;
public:
    Student();
    void printDetails() override;
    static int get_by_id(int id, Person **data);
    bool save(Person **data, int index = -1);
    string printType() override;
    static int getCount();
    int getId() override;
    
    // Getter for student-specific attribute
    int getStudentId() const;
    
    // Setter for student-specific attribute
    void setStudentId(int id) override;
    virtual ~Student();
};
#endif
