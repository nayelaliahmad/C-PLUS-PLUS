#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** realMat;  // Real matrix (original matrix)
    int** sparseMat;  // Sparse matrix representation

public:
    // Default constructor
    Matrix() : rows(0), cols(0), realMat(nullptr), sparseMat(nullptr) {}

    // Parameterized constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        // Allocate memory for real matrix
        realMat = new int* [rows];
        for (int i = 0; i < rows; i++) {
            realMat[i] = new int[cols]();
        }

        // Allocate memory for sparse matrix
        sparseMat = new int* [rows];
        for (int i = 0; i < rows; i++) {
            sparseMat[i] = nullptr;
        }
    }

    // Destructor to free memory
    ~Matrix() {
        for (int i = 0; i < rows; i++) delete[] realMat[i];
        delete[] realMat;

        for (int i = 0; i < rows; i++) delete[] sparseMat[i];
        delete[] sparseMat;
    }

    // Input matrix values
    void input() {
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> realMat[i][j];
            }
        }
    }

    // Convert to sparse matrix
    void convertToSparse() {
        for (int i = 0; i < rows; i++) {
            int nonZeroCount = 0;
            for (int j = 0; j < cols; j++) {
                if (realMat[i][j] != 0) nonZeroCount++;
            }

            sparseMat[i] = new int[1 + (2 * nonZeroCount)];
            sparseMat[i][0] = nonZeroCount;  // Store count of non-zero elements

            int index = 1;
            for (int j = 0; j < cols; j++) {
                if (realMat[i][j] != 0) {
                    sparseMat[i][index] = j;         // Column index
                    sparseMat[i][index + 1] = realMat[i][j]; // Value
                    index += 2;
                }
            }
        }
    }

    // Display matrices
    void display() {
        cout << "Real Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << realMat[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Sparse Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < 1 + (2 * sparseMat[i][0]); j++) {
                cout << sparseMat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Matrix addition
    void add() {
        Matrix mat1(rows, cols), mat2(rows, cols);
        cout << "Enter first matrix:\n";
        mat1.input();
        cout << "Enter second matrix:\n";
        mat2.input();

        if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
            cout << "Matrices must have same size.\n";
            return;
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.realMat[i][j] = mat1.realMat[i][j] + mat2.realMat[i][j];
            }
        }

        result.convertToSparse();
        result.display();
    }

    // Matrix subtraction
    void subtract() {
        Matrix mat1(rows, cols), mat2(rows, cols);
        cout << "Enter first matrix:\n";
        mat1.input();
        cout << "Enter second matrix:\n";
        mat2.input();

        if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
            cout << "Matrices must have same size.\n";
            return;
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.realMat[i][j] = mat1.realMat[i][j] - mat2.realMat[i][j];
            }
        }

        result.convertToSparse();
        result.display();
    }

    // Matrix multiplication
    void multiply() {
        int newCols;
        cout << "Enter second matrix's column count: ";
        cin >> newCols;

        Matrix mat1(rows, cols), mat2(cols, newCols);
        cout << "Enter first matrix:\n";
        mat1.input();
        cout << "Enter second matrix:\n";
        mat2.input();

        if (mat1.cols != mat2.rows) {
            cout << "Invalid dimensions for multiplication.\n";
            return;
        }

        Matrix result(mat1.rows, newCols);
        for (int i = 0; i < mat1.rows; i++) {
            for (int j = 0; j < mat2.cols; j++) {
                result.realMat[i][j] = 0;
                for (int k = 0; k < mat1.cols; k++) {
                    result.realMat[i][j] += mat1.realMat[i][k] * mat2.realMat[k][j];
                }
            }
        }

        result.convertToSparse();
        result.display();
    }

    // Transpose matrix
    void transpose() {
        Matrix transposed(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposed.realMat[j][i] = realMat[i][j];
            }
        }

        transposed.convertToSparse();
        cout << "Transposed Matrix:\n";
        transposed.display();
    }
};


