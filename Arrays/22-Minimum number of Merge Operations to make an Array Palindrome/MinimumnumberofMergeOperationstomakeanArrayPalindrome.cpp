#include <iostream>
using namespace std;

// Function to calculate the minimum number of merge operations 
// required to make the array a palindrome
int minOperations(int arr[], int n) {
    int ops = 0;       // Counter for the number of operations
    int i = 0;         // Pointer to the start of the array
    int j = n - 1;     // Pointer to the end of the array

    while (i <= j) {
        if (arr[i] == arr[j]) {
            // If the left and right elements are equal, move both pointers
            i++;
            j--;
        } else if (arr[i] > arr[j]) {
            // If the left element is greater, merge the two rightmost elements
            arr[j - 1] += arr[j];
            j--;
            ops++; // Increment the operation counter
        } else {
            // If the right element is greater, merge the two leftmost elements
            arr[i + 1] += arr[i];
            i++;
            ops++; // Increment the operation counter
        }
    }
    return ops;
}

int main() {
    int arr[] = {1, 3, 8, 6, 1}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Get the minimum number of operations to make the array a palindrome
    int ans = minOperations(arr, n);

    // Display the result based on the number of operations
    if (ans == 0) {
        cout << "The array is already a palindrome." << endl;
    } else if (ans == n - 1) {
        cout << "Merging all elements to get a palindrome." << endl;
    }
    cout << "Minimum number of merge operations required: " << ans << endl;

    return 0;
}
