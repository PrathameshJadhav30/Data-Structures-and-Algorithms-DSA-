#include <iostream>
using namespace std;

// Function to segregate 0s and 1s in the array
void segregate_01(int arr[], int n) {
    // Counters for 0s and 1s
    int count_0 = 0, count_1 = 0;

    // Count the number of 0s and 1s in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            count_0++;
        } else {
            count_1++;
        }
    }

    // Print all the 0s
    for (int i = 0; i < count_0; i++) {
        cout << "0 ";
    }

    // Print all the 1s
    for (int i = 0; i < count_1; i++) {
        cout << "1 ";
    }
}

int main() {
    // Input array
    int arr[] = {0, 1, 0, 0, 1, 1, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Print the original array
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Print the segregated array
    cout << "\nSegregated array: ";
    segregate_01(arr, n);

    return 0;
}
