#include <bits/stdc++.h>
using namespace std;

// Function to find the starting index of the subarray with the maximum average of length 'k'
int findMaxAverage(int arr[], int n, int k) {
    // Check if 'k' is greater than the size of the array
    if (k > n)
        return -1;

    // Create and fill cumulative sum array
    // csum[i] stores the sum of arr[0] to arr[i]
    int* csum = new int[n];
    csum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        csum[i] = csum[i - 1] + arr[i];
    }

    // Initialize variables for maximum sum and its ending index
    int max_sum = csum[k - 1]; // Sum of the first 'k' elements
    int max_end = k - 1;       // Ending index of the maximum sum subarray

    // Iterate to find the subarray with the maximum sum of length 'k'
    for (int i = k; i < n; i++) {
        // Calculate the sum of the subarray ending at index 'i'
        int curr_sum = csum[i] - csum[i - k];

        // Update the maximum sum and ending index if the current sum is greater
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            max_end = i;
        }
    }

    // Free allocated memory to avoid memory leaks
    delete[] csum;

    // Return the starting index of the subarray with the maximum average
    return max_end - k + 1;
}

// Driver program
int main() {
    int arr[] = {-1, 10, -15, -6, 50, 3}; // Input array
    int k = 4;                            // Length of the subarray
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array

    // Print the result
    cout << "The maximum average subarray of length " << k
         << " begins at index " << findMaxAverage(arr, n, k);

    return 0;
}
