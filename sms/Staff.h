#ifndef STAFF_H
#define STAFF_H
#include "Person.h"

class Staff : public Person
{
private:
    string designation;
    int staff_id;
    string type;
    static int count;

public:
    Staff(string name, int age, string designation, int staff_id);
    void printDetails() override;
    static int get_by_id(int id, Person **data);
    bool save(Person **data, int index = -1);
    string printType() override;
    static int getCount();
    int getId() override;
    virtual string getDesignation();
    virtual ~Staff();
};
#endif
