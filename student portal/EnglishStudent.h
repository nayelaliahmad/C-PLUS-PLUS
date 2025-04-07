#ifndef ENGLISHSTUDENT_H
#define ENGLISHSTUDENT_H

#include <string>
#include <iostream>
#include "Student.h"

using namespace std;

class EnglishStudent : public Student {
public:
    float attendance, project, midterm, finalExam;

    EnglishStudent(string f, string l, float a, float p, float m, float fe) {
        firstName = f;
        lastName = l;
        courseType = "English";
        attendance = a;
        project = p;
        midterm = m;
        finalExam = fe;
    }

    float calculateGrade() {
        return attendance * 0.1 + project * 0.3 + midterm * 0.3 + finalExam * 0.3;
    }

    void printReport() {
        cout << firstName << " " << lastName << " (English) - Final Grade: " << calculateGrade() << endl;
    }
};

#endif
