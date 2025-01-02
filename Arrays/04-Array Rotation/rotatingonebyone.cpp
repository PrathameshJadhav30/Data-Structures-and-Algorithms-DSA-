#include <iostream>
using namespace std;

// Function to left rotate an array by 'd' positions
void leftRotate(int arr[], int n, int d) {
    // Perform 'd' rotations
    for (int i = 0; i < d; i++) {
        int temp = arr[0]; // Store the first element temporarily
        // Shift all elements to the left
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp; // Place the first element at the end
    }
}

// Function to right rotate an array by 'd' positions
void rightRotate(int arr[], int n, int d) {
    // Perform 'd' rotations
    for (int i = 0; i < d; i++) {
        int temp = arr[n - 1]; // Store the last element temporarily
        // Shift all elements to the right
        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp; // Place the last element at the beginning
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
