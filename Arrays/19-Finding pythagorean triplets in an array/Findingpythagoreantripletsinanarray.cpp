#include <bits/stdc++.h>
using namespace std;

int main() {
    // Array of integers
    int arr[] = {3, 8, 4, 10, 6, 5, 12, 13, 27, 117, 165, 19, 176, 169, 44, 113, 24, 145,
                 143, 51, 149, 52, 173, 181, 125};
    int N = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Variables to hold squared values of the sides of the triangle
    int a, b, c;

    // Step 1: Sort the array in ascending order
    sort(arr, arr + N);

    // Step 2: Square all elements of the array
    for (int i = 0; i < N; i++) {
        arr[i] = arr[i] * arr[i];
    }

    // Step 3: Check for Pythagorean triplets
    for (int i = 0; i < N - 2; i++) { // Iterate over all potential 'a'
        int left = i + 1;   // Pointer to the next element after 'a'
        int right = N - 1;  // Pointer to the largest element (potential 'c')

        a = arr[i]; // Fix 'a'

        // Use two pointers to find 'b' and 'c'
        while (left < right) {
            b = arr[left];
            c = arr[right];

            // Check if the current triplet satisfies the Pythagorean theorem
            if (a + b == c) {
                // If found, print the triplet (square roots of the squared values)
                cout << sqrt(a) << " " << sqrt(b) << " " << sqrt(c) << endl;
                left++;
                right--;
            } else if (a + b < c) {
                // If the sum is less than c, decrease 'right' to reduce 'c'
                right--;
            } else {
                // If the sum is greater than c, increase 'left' to increase 'b'
                left++;
            }
        }
    }

    return 0;
}
