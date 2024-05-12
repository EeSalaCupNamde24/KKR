#include <iostream>

using namespace std;

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Count_Sort(int *A, int size, int pos) {
    int output[size] = {0};
    int freq[10] = {0};

    for (int i = 0; i < size; i++) {
        freq[(A[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        freq[i] += freq[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[freq[(A[i] / pos) % 10] - 1] = A[i];
        freq[(A[i] / pos) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        A[i] = output[i];
    }
}

void Radix(int *A, int size) {
    int pos;
    int M = A[0];
    for (int i = 1; i < size; i++) {
        M = max(M, A[i]);
    }

    for (pos = 1; M / pos > 0; pos *= 10) {
        Count_Sort(A, size, pos);
    }
}

int main() {
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter the " << i << "th element : ";
        cin >> arr[i];
    }

    cout << "Array before sorting " << endl;
    display(arr, size);

    Radix(arr, size);

    cout << "Array after sorting " << endl;
    display(arr, size);

    delete[] arr;

    return 0;
}

