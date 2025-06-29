#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"

class Teacher : public Person {
private:
    string subject;
    int teacher_id;
    static int count;
public:
    Teacher();  // Default constructor
    void printDetails() override;
    static int get_by_id(int id, Person **data);
    bool save(Person **data, int index = -1);
    string printType() override;
    static int getCount();
    int getId() override;
    
    // Getters for teacher-specific attributes
    int getTeacherId() const;
    string getSubject() const;
    
    // Setters for teacher-specific attributes
    void setTeacherId(int id) override;
    void setSubject(const string& subject) override;
    
    virtual ~Teacher();
};
#endif
