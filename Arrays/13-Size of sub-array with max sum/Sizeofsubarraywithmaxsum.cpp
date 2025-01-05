#include <iostream>
#include <vector>
#include <limits.h> // For INT_MIN
using namespace std;

// Function to find the size of the subarray with the maximum sum
int maxSizeSubarrayWithMaxSum(vector<int> &nums) {
    int max_sum = INT_MIN; // Initialize max_sum to the smallest possible integer
    int current_sum = 0;   // Initialize the current running sum to 0
    int start = 0;         // Start index of the current subarray
    int end = 0;           // End index of the subarray with the maximum sum
    int temp_start = 0;    // Temporary start index for tracking potential new subarray

    for (int i = 0; i < nums.size(); i++) {
        // Check if starting a new subarray is more beneficial
        if (current_sum + nums[i] < nums[i]) {
            current_sum = nums[i]; // Start a new subarray
            temp_start = i;        // Update temporary start index
        } else {
            current_sum += nums[i]; // Extend the current subarray
        }

        // Update max_sum and indices if a new maximum sum is found
        if (current_sum > max_sum) {
            max_sum = current_sum; // Update the maximum sum
            start = temp_start;    // Update the start index of the max sum subarray
            end = i;               // Update the end index of the max sum subarray
        }
    }

    // Return the size of the subarray with the maximum sum
    return end - start + 1;
}

int main() {
    // Example input array
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Calculate the size of the subarray with the maximum sum
    int max_size = maxSizeSubarrayWithMaxSum(nums);

    // Output the result
    cout << "Size of subarray with maximum sum: " << max_size << endl;

    return 0;
}
