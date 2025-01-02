#include <iostream>
#include <algorithm> // For the sort function
using namespace std;

// Function to find all pairs in the array that sum up to the targetSum
void findPairs(int arr[], int n, int targetSum) {
    // Step 1: Sort the array to use the two-pointer technique
    sort(arr, arr + n);

    int left = 0;          // Pointer starting from the beginning
    int right = n - 1;     // Pointer starting from the end

    // Step 2: Use the two-pointer technique to find pairs
    while (left < right) {
        int currSum = arr[left] + arr[right]; // Calculate the sum of elements at the left and right pointers

        if (currSum == targetSum) { // If the current sum matches the target sum
            cout << "Pair found: " << arr[left] << " and " << arr[right] << endl;
            left++;  // Move the left pointer forward
            right--; // Move the right pointer backward
        } else if (currSum < targetSum) {
            left++; // Increase the sum by moving the left pointer forward
        } else {
            right--; // Decrease the sum by moving the right pointer backward
        }
    }
}

int main() {
    // Input array and target sum
    int arr[] = {5, 8, 1, 4, 6, 3, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int targetSum = 10;                   // Target sum to find pairs

    // Call the function to find pairs
    findPairs(arr, n, targetSum);

    return 0; // Exit the program
}
