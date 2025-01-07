#include <bits/stdc++.h>
using namespace std;

// Function to print the indexes of zeros that should be flipped 
// to get the longest sequence of 1s
void zeroesIndexes(int arr[], int zeroes, int n) {
    int start = 0, end = 0; // Start and end pointers for the sliding window
    int count = 0;          // Number of zeros in the current window
    int bestWindow = 0;     // Size of the best window found
    int bestWindowStart = 0; // Starting index of the best window

    // Sliding window approach to find the best window
    while (end < n) {
        // Expand the window if the number of zeros is within the allowed limit
        if (count <= zeroes) {
            if (arr[end] == 0) {
                count++;
            }
            end++;
        }

        // Shrink the window if the number of zeros exceeds the allowed limit
        if (count > zeroes) {
            if (arr[start] == 0) {
                count--;
            }
            start++;
        }

        // Update the best window if the current window is larger
        if (end - start > bestWindow) {
            bestWindow = end - start;
            bestWindowStart = start;
        }
    }

    // Output the results
    cout << "The indexes of zeros to be flipped are: ";
    for (int i = bestWindowStart; i < bestWindowStart + bestWindow; i++) {
        if (arr[i] == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int arr[] = {0, 1, 0, 1, 1, 0, 1}; // Input array
    int zeroes = 2;                    // Number of zeros that can be flipped
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array

    // Find and print the indexes of zeros to flip
    zeroesIndexes(arr, zeroes, n);

    return 0;
}
