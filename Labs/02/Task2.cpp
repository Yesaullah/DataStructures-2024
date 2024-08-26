#include <iostream>
#include "Matrix_Multiply.h"

using namespace std;

void multiplyMatrices(const int** matrixA, const int** matrixB, int** matrixC, int m, int n, int p) {
    // Initialize the result matrixC with zeroes
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            matrixC[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int m = 2; // Number of rows in A
    int n = 3; // Number of columns in A and rows in B
    int p = 2; // Number of columns in B

    // Allocate memory for matrices
    int** A = new int*[m];
    int** B = new int*[n];
    int** C = new int*[m];
    for (int i = 0; i < m; ++i) {
        A[i] = new int[n];
        C[i] = new int[p];
    }
    for (int i = 0; i < n; ++i) {
        B[i] = new int[p];
    }

    // Input for matrix A
    cout << "Enter elements for matrix A (" << m << "x" << n << "):" << endl;
    for (int i = 0; i < m; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    // Input for matrix B
    cout << "Enter elements for matrix B (" << n << "x" << p << "):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < p; ++j) {
            cin >> B[i][j];
        }
    }

    // Perform matrix multiplication
    multiplyMatrices(const_cast<const int**>(A), const_cast<const int**>(B), C, m, n, p);

    // Output the result matrix C
    cout << "Resultant matrix C (" << m << "x" << p << "):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // Free allocated memory
    for (int i = 0; i < m; ++i) {
        delete[] A[i];
        delete[] C[i];
    }
    for (int i = 0; i < n; ++i) {
        delete[] B[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
