#include <iostream>
using namespace std;

int main() {
    // Initialize an array with some elements
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    int start = 0;         // Start index
    int end = n - 1;       // End index

    // Reverse the array by swapping elements from the start and end
    while (start < end) {
        int temp = arr[start]; // Temporary variable to hold the value of the current start element
        arr[start] = arr[end]; // Swap the start element with the end element
        arr[end] = temp;       // Assign the temporary value to the end element

        start++; // Move start pointer forward
        end--;   // Move end pointer backward
    }

    // Print the reversed array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0; // Exit the program
}
