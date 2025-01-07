#include <bits/stdc++.h>
#define ABSENT INT_MAX // Define a constant to represent "absent" values
using namespace std;

// Function to shift non-ABSENT elements to the rightmost part of the array
// Returns the index of the first non-ABSENT element after transformation
int transform(int M[], int n) {
    int j = n - 1; // Start from the last position
    // Traverse the array backward
    for (int i = n - 1; i >= 0; i--) {
        if (M[i] != ABSENT) { // If the element is not ABSENT
            M[j] = M[i];      // Move it to the end
            j--;
        }
    }
    return (j + 1); // Return the index where valid data starts
}

int main() {
    // Input arrays
    int M[] = {1, 7, ABSENT, ABSENT, 124, 132, ABSENT, 155, 200};
    int N[] = {2, 4, 152, 360};

    // Calculate the sizes of arrays
    int sizeM = sizeof(M) / sizeof(M[0]);
    int sizeN = sizeof(N) / sizeof(N[0]);

    // Remove ABSENT elements from M and get the number of valid elements
    int no_absent = transform(M, sizeM);

    int m = no_absent; // Start of valid elements in M
    int n = 0;         // Start of N
    int l = 0;         // Start of merged array

    // Merge the two arrays in sorted order
    while (n < sizeN && m < sizeM) {
        if (M[m] <= N[n]) {
            M[l++] = M[m++]; // Take element from M
        } else {
            M[l++] = N[n++]; // Take element from N
        }
    }

    // Copy remaining elements from M, if any
    while (m < sizeM) {
        M[l++] = M[m++];
    }

    // Copy remaining elements from N, if any
    while (n < sizeN) {
        M[l++] = N[n++];
    }

    // Print the merged array
    for (int i = 0; i < sizeM; i++) {
        cout << M[i] << " ";
    }

    return 0;
}
