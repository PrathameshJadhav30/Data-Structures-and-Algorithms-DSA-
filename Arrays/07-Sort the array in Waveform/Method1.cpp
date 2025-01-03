#include <iostream>
#include <algorithm> // For sorting

using namespace std;

int main() {
    // Define and initialize the array
    int array[] = {10, 49, 2, 1, 5, 23};
    int n = sizeof(array) / sizeof(array[0]); // Calculate the size of the array
    int temp; // Temporary variable for swapping

    // Step 1: Sort the array in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                // Swap elements if they are out of order
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // Step 2: Convert sorted array to waveform pattern
    for (int i = 0; i < n - 1; i += 2) {
        // Swap adjacent elements to create waveform pattern
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }

    // Step 3: Print the array in waveform pattern
    cout << "Array in Waveform Pattern: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " "; // Print each element
    }
    cout << endl;

    return 0;
}
