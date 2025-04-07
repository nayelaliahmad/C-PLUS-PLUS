#ifndef MATHSTUDENT_H
#define MATHSTUDENT_H

#include "Student.h"

class MathStudent : public Student {
public:
    float quiz1, quiz2, quiz3, test1, test2, finalExam;

    MathStudent(string f, string l, float q1, float q2, float q3, float t1, float t2, float fe) {
        firstName = f;
        lastName = l;
        courseType = "Math";
        quiz1 = q1;
        quiz2 = q2;
        quiz3 = q3;
        test1 = t1;
        test2 = t2;
        finalExam = fe;
    }

    float calculateGrade() {
        float quizAvg = (quiz1 + quiz2 + quiz3) / 3;
        return quizAvg * 0.1 + test1 * 0.25 + test2 * 0.25 + finalExam * 0.4;
    }

    void printReport() {
        cout << firstName << " " << lastName << " (Math) - Final Grade: " << calculateGrade() << endl;
    }
};

#endif
