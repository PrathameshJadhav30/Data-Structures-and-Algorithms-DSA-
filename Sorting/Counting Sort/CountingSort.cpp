#include<iostream>
#define MAX 255 // Define the maximum possible value for array elements
using namespace std;

// Function to perform Counting Sort
void countSort(int array[], int size) {
    int output[MAX]; // Array to store sorted elements
    int count[MAX]; // Array to store counts of each element
    int max = array[0]; // Variable to find the largest element in the array

    // Find the largest element in the array
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Initialize the count array with 0
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Store the count of each element in the input array
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Update the count array to store the cumulative count
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array by placing elements at their correct positions
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements from output array back to the input array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

// Function to print an array
void display(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// Driver code to test the Counting Sort implementation
int main() {
    int array[] = {2, 5, 2, 8, 1, 4, 1}; // Input array
    int n = sizeof(array) / sizeof(array[0]); // Calculate the size of the array
  
    countSort(array, n); // Call the counting sort function
  
    display(array, n); // Display the sorted array

    return 0;
}
