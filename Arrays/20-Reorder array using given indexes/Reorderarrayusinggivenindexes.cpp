#include <bits/stdc++.h>
using namespace std;

// Function to reorder elements in the array based on the index array
void Reorder(int array[], int index[], int N) {
    int temp[N]; // Auxiliary array to store reordered elements

    // Place elements in their target positions as per the index array
    for (int i = 0; i < N; i++) {
        temp[index[i]] = array[i];
    }

    // Copy reordered elements back to the original array
    for (int i = 0; i < N; i++) {
        array[i] = temp[i];
        index[i] = i; // Update index array to reflect the natural order
    }
}

// Function to print the contents of an array
void PrintArray(int array[], int N) {
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl; // Add a newline for better formatting
}

// Main function
int main() {
    // Input arrays
    int array[] = {50, 40, 70, 60, 90};
    int index[] = {3, 0, 4, 1, 2};
    int N = sizeof(array) / sizeof(array[0]); // Calculate the size of the array

    // Print input arrays
    cout << "Input array:\n";
    PrintArray(array, N);
    cout << "Input index array:\n";
    PrintArray(index, N);

    // Reorder the array based on the index array
    Reorder(array, index, N);

    // Print output arrays
    cout << "Output array:\n";
    PrintArray(array, N);
    cout << "Output index array:\n";
    PrintArray(index, N);

    return 0;
}
