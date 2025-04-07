#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string firstName;
    string lastName;
    string courseType;
    virtual float calculateGrade() = 0;
    virtual void printReport() = 0;
    virtual ~Student() {}
};

#endif
