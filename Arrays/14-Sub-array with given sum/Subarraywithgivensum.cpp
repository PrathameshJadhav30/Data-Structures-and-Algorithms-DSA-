// sliding window approach
#include <iostream>
using namespace std;

// Function to find a subarray with the given sum
void findSubarray(int arr[], int n, int sum) {
    int curr_sum = arr[0]; // Initialize current sum with the first element
    int start = 0;         // Initialize the starting index of the subarray

    // Iterate through the array
    for (int i = 1; i <= n; i++) {
        // Adjust the current sum if it exceeds the target sum
        while (curr_sum > sum && start < i - 1) {
            curr_sum -= arr[start]; // Subtract the element at 'start' from current sum
            start++;                // Move the starting index forward
        }

        // Check if the current sum equals the target sum
        if (curr_sum == sum) {
            cout << "Subarray found between indexes " << start << " and " << i - 1 << endl;
            return; // Exit the function after finding the subarray
        }

        // Add the next element to the current sum if within bounds
        if (i < n) {
            curr_sum += arr[i];
        }
    }

    // If no subarray is found with the given sum
    cout << "No subarray found" << endl;
}

int main() {
    // Example input array
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int sum = 23;                         // Target sum to find

    // Call the function to find the subarray
    findSubarray(arr, n, sum);

    return 0;
}
