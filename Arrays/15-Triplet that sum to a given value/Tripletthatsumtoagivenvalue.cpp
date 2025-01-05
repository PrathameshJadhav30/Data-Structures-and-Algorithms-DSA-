// sorting approach
#include <iostream>
#include <algorithm> // For using built-in algorithms 

using namespace std;

// Function to perform Insertion Sort
void sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int element = arr[i]; // Current element to be positioned
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than 'element'
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > element) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place the current element at its correct position
        arr[j + 1] = element;
    }
}

// Function to find and print all unique triplets in the array 
// that sum up to the given value
void findTriplets(int arr[], int n, int sum) {
    // Sort the array to make it easier to find triplets
    sort(arr, n);

    // Iterate through the array to fix the first element of the triplet
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;     // Second pointer
        int k = n - 1;     // Third pointer (starts from the end)

        // Use two-pointer technique to find pairs with the desired sum
        while (j < k) {
            int currentSum = arr[i] + arr[j] + arr[k];
            if (currentSum == sum) {
                // If the triplet is found, print it
                cout << "(" << arr[i] << ", " << arr[j] << ", " << arr[k] << ")" << endl;
                j++; // Move the second pointer forward
                k--; // Move the third pointer backward
            } else if (currentSum < sum) {
                // If current sum is less than the desired sum, 
                // move the second pointer forward to increase the sum
                j++;
            } else {
                // If current sum is greater than the desired sum, 
                // move the third pointer backward to decrease the sum
                k--;
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Input array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int sum = 9; // Target sum for triplets

    // Print the original array
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nSum: " << sum << endl;

    // Find and print triplets
    cout << "Triplets:" << endl;
    findTriplets(arr, n, sum);

    return 0;
}
