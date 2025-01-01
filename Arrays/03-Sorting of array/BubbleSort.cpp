#include <bits/stdc++.h> // Include all standard libraries
using namespace std;

int main() {
    // Declare a variable to store the size of the array
    int n;

    // Prompt the user to enter the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Declare an array of size n
    int a[n];

    // Prompt the user to enter the elements of the array
    cout << "\nEnter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort the array using a nested loop (Bubble Sort logic)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Swap elements if they are in the wrong order
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Print the sorted array
    cout << "\nArray after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0; // Exit the program successfully
}
//Use all Sorting methods for array sort