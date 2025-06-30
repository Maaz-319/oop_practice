#ifndef STAFF_H
#define STAFF_H
#include "Person.h"

class Staff : public Person
{
private:
    string designation;
    int staff_id;
    static int count;

public:
    Staff();
    void printDetails() override;
    static int get_by_id(int id, Person **data);
    bool save(Person **data, int index = -1);
    string printType() override;
    static int getCount();
    int getId() override;
    
    // Getters for staff-specific attributes
    int getStaffId() const;
    virtual string getDesignation();
    
    // Setters for staff-specific attributes
    void setStaffId(int staff_id) override;
    void setDesignation(const string& designation) override;
    virtual ~Staff();
};
#endif
