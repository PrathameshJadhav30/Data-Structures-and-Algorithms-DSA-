#include <iostream>
using namespace std;

// Function to left rotate an array by 'd' positions
void leftRotate(int arr[], int n, int d) {
    int temp[d]; // Temporary array to store the first 'd' elements

    // Store the first 'd' elements in temp
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // Shift the remaining elements to the left
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // Copy the elements from temp to the end of the array
    for (int i = n - d, j = 0; i < n; i++, j++) {
        arr[i] = temp[j];
    }
}

// Function to right rotate an array by 'd' positions
void rightRotate(int arr[], int n, int d) {
    int temp[d]; // Temporary array to store the last 'd' elements

    // Store the last 'd' elements in temp
    for (int i = n - d, j = 0; i < n; i++, j++) {
        temp[j] = arr[i];
    }

    // Shift the remaining elements to the right
    for (int i = n - d - 1; i >= 0; i--) {
        arr[i + d] = arr[i];
    }

    // Copy the elements from temp to the beginning of the array
    for (int i = 0; i < d; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array
    int d = 2; // Number of positions to rotate

    // Display the original array
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform left rotation
    leftRotate(arr, n, d);
    cout << "Left Rotated Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform right rotation
    rightRotate(arr, n, d);
    cout << "Right Rotated Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
