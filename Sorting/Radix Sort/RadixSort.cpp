#include <iostream>
using namespace std;

// Function to get the largest element from an array
int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

// Counting sort function to sort elements based on the digit represented by `place`
void countSort(int array[], int size, int place) {
    const int base = 10; // Base of the number system (decimal)
    int output[size];    // Output array to store sorted elements
    int count[base] = {0}; // Initialize count array to zero

    // Count occurrences of each digit at the given place value
    for (int i = 0; i < size; i++) {
        int digit = (array[i] / place) % base;
        count[digit]++;
    }

    // Calculate cumulative count to determine the position of each digit
    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array by placing elements in sorted order
    for (int i = size - 1; i >= 0; i--) {
        int digit = (array[i] / place) % base;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

// Main function to implement Radix Sort
void radixSort(int array[], int size) {
    // Get the maximum number to determine the number of digits
    int max = getMax(array, size);

    // Perform counting sort for each digit, moving from least significant to most significant
    for (int place = 1; max / place > 0; place *= 10) {
        countSort(array, size, place);
    }
}

// Function to display the elements of an array
void display(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << "\t";
    }
    cout << endl;
}

// Driver code
int main() {
    int array[] = {112, 400, 543, 441, 678, 675, 9, 777};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Before sorting:" << endl;
    display(array, n);

    radixSort(array, n);

    cout << "After sorting:" << endl;
    display(array, n);

    return 0;
}
