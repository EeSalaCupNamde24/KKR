#include <iostream>

using namespace std;

struct Interval {
    int start;
    int finish;
};

void intervalScheduling(Interval arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].finish > arr[j + 1].finish) {
                Interval temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Selected interval: " << arr[0].start << " - " << arr[0].finish << endl;

    int prevFinish = arr[0].finish;
    for (int i = 1; i < n; ++i) {
        if (arr[i].start >= prevFinish) {
            cout << "Selected interval: " << arr[i].start << " - " << arr[i].finish << endl;
            prevFinish = arr[i].finish;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    Interval* arr = new Interval[n];

    for (int i = 0; i < n; ++i) {
        cout << "Enter start time of interval " << i + 1 << ": ";
        cin >> arr[i].start;
        cout << "Enter finish time of interval " << i + 1 << ": ";
        cin >> arr[i].finish;
    }
    
    cout << "Maximum number of non-overlapping intervals:\n";
    intervalScheduling(arr, n);

    delete[] arr;

    return 0;
}

