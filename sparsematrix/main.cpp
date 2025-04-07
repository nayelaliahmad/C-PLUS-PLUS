#include "sparse.h"
#include<iostream>
using namespace std;

int main() {
    Matrix mat(3, 3);  // 3x3 matrix
    mat.input();  // Input values
    mat.convertToSparse();  // Convert to sparse
    mat.display();  // Display matrices

    mat.add();  // Addition
    mat.subtract();  // Subtraction
    mat.multiply();  // Multiplication
    mat.transpose();  // Transpose

    return 0;
}