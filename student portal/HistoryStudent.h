#ifndef HISTORYSTUDENT_H
#define HISTORYSTUDENT_H
#include<string>

#include "Student.h"

class HistoryStudent : public Student {
public:
    float termPaper, midterm, finalExam;

    HistoryStudent(string f, string l, float tp, float m, float fe) {
        firstName = f;
        lastName = l;
        courseType = "History";
        termPaper = tp;
        midterm = m;
        finalExam = fe;
    }

    float calculateGrade() {
        return termPaper * 0.25 + midterm * 0.35 + finalExam * 0.4;
    }

    void printReport() {
        cout << firstName << " " << lastName << " (History) - Final Grade: " << calculateGrade() << endl;
    }
};

#endif
