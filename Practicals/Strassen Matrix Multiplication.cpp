#include <iostream>

using namespace std;

int** add(int** A, int** B, int n) {
    int** C = new int*[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

int** subtract(int** A, int** B, int n) {
    int** C = new int*[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

int** strassen(int** A, int** B, int n) {
    if (n == 1) {
        int** C = new int*[1];
        C[0] = new int[1];
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int newSize = n / 2;
    int** a11 = new int*[newSize];
    int** a12 = new int*[newSize];
    int** a21 = new int*[newSize];
    int** a22 = new int*[newSize];

    int** b11 = new int*[newSize];
    int** b12 = new int*[newSize];
    int** b21 = new int*[newSize];
    int** b22 = new int*[newSize];

    for (int i = 0; i < newSize; ++i) {
        a11[i] = new int[newSize];
        a12[i] = new int[newSize];
        a21[i] = new int[newSize];
        a22[i] = new int[newSize];

        b11[i] = new int[newSize];
        b12[i] = new int[newSize];
        b21[i] = new int[newSize];
        b22[i] = new int[newSize];

        for (int j = 0; j < newSize; ++j) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + newSize];
            a21[i][j] = A[i + newSize][j];
            a22[i][j] = A[i + newSize][j + newSize];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + newSize];
            b21[i][j] = B[i + newSize][j];
            b22[i][j] = B[i + newSize][j + newSize];
        }
    }

    int** p1 = strassen(add(a11, a22, newSize), add(b11, b22, newSize), newSize);
    int** p2 = strassen(add(a21, a22, newSize), b11, newSize);
    int** p3 = strassen(a11, subtract(b12, b22, newSize), newSize);
    int** p4 = strassen(a22, subtract(b21, b11, newSize), newSize);
    int** p5 = strassen(add(a11, a12, newSize), b22, newSize);
    int** p6 = strassen(subtract(a21, a11, newSize), add(b11, b12, newSize), newSize);
    int** p7 = strassen(subtract(a12, a22, newSize), add(b21, b22, newSize), newSize);

    int** c11 = add(subtract(add(p1, p4, newSize), p5, newSize), p7, newSize);
    int** c12 = add(p3, p5, newSize);
    int** c21 = add(p2, p4, newSize);
    int** c22 = add(subtract(add(p1, p3, newSize), p2, newSize), p6, newSize);

    int** C = new int*[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            if (i < newSize && j < newSize) {
                C[i][j] = c11[i][j];
            } else if (i < newSize && j >= newSize) {
                C[i][j] = c12[i][j - newSize];
            } else if (i >= newSize && j < newSize) {
                C[i][j] = c21[i - newSize][j];
            } else {
                C[i][j] = c22[i - newSize][j - newSize];
            }
        }
    }

    for (int i = 0; i < newSize; ++i) {
        delete[] a11[i];
        delete[] a12[i];
        delete[] a21[i];
        delete[] a22[i];
        delete[] b11[i];
        delete[] b12[i];
        delete[] b21[i];
        delete[] b22[i];
        delete[] p1[i];
        delete[] p2[i];
        delete[] p3[i];
        delete[] p4[i];
        delete[] p5[i];
        delete[] p6[i];
        delete[] p7[i];
        delete[] c11[i];
        delete[] c12[i];
        delete[] c21[i];
        delete[] c22[i];
    }
    delete[] a11;
    delete[] a12;
    delete[] a21;
    delete[] a22;
    delete[] b11;
    delete[] b12;
    delete[] b21;
    delete[] b22;
    delete[] p1;
    delete[] p2;
    delete[] p3;
    delete[] p4;
    delete[] p5;
    delete[] p6;
    delete[] p7;
    delete[] c11;
    delete[] c12;
    delete[] c21;
    delete[] c22;

    return C;
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrices: ";
    cin >> n;

    cout << "Enter elements of matrix A:" << endl;
    int** A = new int*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of matrix B:" << endl;
    int** B = new int*[n];
    for (int i = 0; i < n; ++i) {
        B[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> B[i][j];
        }
    }

    int** C = strassen(A, B, n);

    cout << "Result:" << endl;
    printMatrix(C, n);

    for (int i = 0; i < n; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}


