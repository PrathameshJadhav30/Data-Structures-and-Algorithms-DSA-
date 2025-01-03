#include <iostream>
using namespace std;

// Function to find the majority element in an array
int findMajorityElement(int arr[], int n) {
    int candidate = 0; // Candidate for the majority element
    int count = 0;     // Count of occurrences of the candidate element

    // Phase 1: Candidate selection using the Boyer-Moore Voting Algorithm
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            // Set the current element as the candidate
            candidate = arr[i];
            count = 1;
        } else if (arr[i] == candidate) {
            count++; // Increment count if the current element matches the candidate
        } else {
            count--; // Decrement count if the current element does not match
        }
    }

    // Phase 2: Verify if the candidate is indeed the majority element
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++; // Count occurrences of the candidate in the array
        }
    }

    // Check if the candidate occurs more than n/2 times
    if (count > n / 2) {
        return candidate;
    } else {
        return -1; // Return -1 if no majority element exists
    }
}

int main() {
    // Example array
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Find the majority element
    int majorityElement = findMajorityElement(arr, n);

    // Output the result
    if (majorityElement != -1) {
        cout << "Majority element is: " << majorityElement << endl;
    } else {
        cout << "No majority element found" << endl;
    }

    return 0;
}
