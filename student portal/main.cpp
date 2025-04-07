#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "EnglishStudent.h"
#include "HistoryStudent.h"
#include "MathStudent.h"
using namespace std;

int main() {
    ifstream inFile("student_data.txt");
    ofstream outFile("student_report.txt");

    if (!inFile || !outFile) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    string firstName, lastName, courseType;
    float grade1, grade2, grade3, grade4, grade5, grade6;
    
    while (inFile >> firstName >> lastName >> courseType) {
        if (courseType == "English") {
            inFile >> grade1 >> grade2 >> grade3 >> grade4;
            EnglishStudent student(firstName, lastName, grade1, grade2, grade3, grade4);
            outFile << firstName << " " << lastName << " (English) - Final Grade: " 
                    << student.calculateGrade() << endl;
        } else if (courseType == "History") {
            inFile >> grade1 >> grade2 >> grade3;
            HistoryStudent student(firstName, lastName, grade1, grade2, grade3);
            outFile << firstName << " " << lastName << " (History) - Final Grade: " 
                    << student.calculateGrade() << endl;
        } else if (courseType == "Math") {
            inFile >> grade1 >> grade2 >> grade3 >> grade4 >> grade5 >> grade6;
            MathStudent student(firstName, lastName, grade1, grade2, grade3, grade4, grade5, grade6);
            outFile << firstName << " " << lastName << " (Math) - Final Grade: " 
                    << student.calculateGrade() << endl;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Report has been generated." << endl;

    return 0;
}
