#include <iostream>
#include <vector>

using namespace std;

// Function to find the majority element in a vector
int majorityElement(vector<int>& nums) {
    int candidate = 0; // Potential majority element
    int count = 0;     // Count to track the majority element

    // Step 1: Find the potential majority element
    for (int num : nums) {
        if (count == 0) {
            candidate = num; // Set the current number as the candidate
        }
        count += (num == candidate) ? 1 : -1; // Increment or decrement count
    }

    // Step 2: Verify if the candidate is the majority element
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++; // Count occurrences of the candidate
        }
    }

    // Check if the candidate occurs more than half the size of the array
    if (count > nums.size() / 2) {
        return candidate;
    }
    return -1; // No majority element found
}

int main() {
    // Example usage of the Boyer-Moore Majority Vote Algorithm
    vector<int> nums = {1, 2, 2, 2, 3, 2, 4, 2, 5}; // Example input array

    int majority = majorityElement(nums); // Find the majority element

    if (majority != -1) {
        cout << "The majority element is: " << majority << endl;
    } else {
        cout << "There is no majority element." << endl;
    }

    return 0;
}
