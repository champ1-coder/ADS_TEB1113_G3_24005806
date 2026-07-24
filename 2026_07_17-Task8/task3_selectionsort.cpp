// selectionsort

#include <iostream>
using namespace std;

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        int minVal = arr[i];
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < minVal) {
                minIdx = j;
                minVal = arr[j];
            }
        }
        arr[minIdx] = arr[i];
        arr[i] = minVal;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}