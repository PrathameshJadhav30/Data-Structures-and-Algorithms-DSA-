#include <bits/stdc++.h>
using namespace std;

int main() {
    // Input array and its size
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Variables to track the maximum sum and current subarray sum
    int max_sum = INT_MIN; // Initialize to the smallest possible integer
    int curr_sum = 0;      // Tracks the sum of the current subarray

    // Traverse the array
    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];           // Add the current element to the subarray sum
        max_sum = max(max_sum, curr_sum); // Update the maximum sum if needed

        // If the current sum becomes negative, reset it to 0
        if (curr_sum < 0) {
            curr_sum = 0;
        }
    }

    // Output the maximum subarray sum
    cout << max_sum;

    return 0;
}
