// dutch national flag method 
#include <iostream>
using namespace std;

// Function to sort an array of 0s, 1s, and 2s using the Dutch National Flag algorithm
void dutchNationalFlag(int arr[], int n) {
    int low = 0;         // Pointer to the low end of the array (for 0s)
    int mid = 0;         // Pointer to the current element being processed
    int high = n - 1;    // Pointer to the high end of the array (for 2s)

    // Loop until mid pointer crosses the high pointer
    while (mid <= high) {
        if (arr[mid] == 0) {
            // Case 1: Current element is 0
            // Swap the element at mid with the element at low
            swap(arr[mid], arr[low]);
            mid++;      // Move mid to the next element
            low++;      // Increment low pointer
        } else if (arr[mid] == 1) {
            // Case 2: Current element is 1
            // Just move the mid pointer to the next element
            mid++;
        } else {
            // Case 3: Current element is 2
            // Swap the element at mid with the element at high
            swap(arr[mid], arr[high]);
            high--;     // Decrement high pointer
        }
    }
}

int main() {
    // Input array
    int arr[] = { 2, 0, 1, 2, 0, 1, 0, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Print the original array
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array using the Dutch National Flag algorithm
    dutchNationalFlag(arr, n);

    // Print the segregated array
    cout << "Segregated array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
