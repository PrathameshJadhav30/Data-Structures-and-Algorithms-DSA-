#include <iostream>

using namespace std;

int main() {
    // Define and initialize the array
    int array[] = {10, 49, 2, 1, 5, 23};
    int n = sizeof(array) / sizeof(array[0]); // Calculate the size of the array
    int temp; // Temporary variable for swapping

    // Rearrange the array to follow a waveform pattern
    for (int i = 0; i < n; i += 2) {
        // Check and swap with the previous element if needed
        if (i > 0 && array[i - 1] > array[i]) {
            temp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = temp;
        }

        // Check and swap with the next element if needed
        if (i < n - 1 && array[i] < array[i + 1]) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }

    // Print the array in waveform pattern
    cout << "Array in Waveform Pattern: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
