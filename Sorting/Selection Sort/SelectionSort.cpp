#include <iostream>
using namespace std;

// Function to display the elements of the array
void display(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << "\t"; // Print each element followed by a tab
    }
    cout << "\n"; // Move to the next line after displaying all elements
}

// Function to sort the array using the Selection Sort algorithm
void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Find the index of the minimum element in the remaining unsorted part
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }
        // Swap the smallest element with the current element at index i
        swap(array[minIndex], array[i]);
    }
}

// Main function
int main() {
    // Array initialization
    int array[] = {5, 3, 1, 9, 8, 2, 4, 7};
    int size = sizeof(array) / sizeof(array[0]); // Calculate the number of elements in the array

    // Display the array before sorting
    cout << "Before sorting: \n";
    display(array, size);

    // Sort the array
    selectionSort(array, size);

    // Display the array after sorting
    cout << "After sorting: \n";
    display(array, size);

    return 0;
}

/*
Key Notes:
1. The `display` function is used to print the array elements.
2. The `selectionSort` function implements the Selection Sort algorithm:
   - Finds the smallest element in the remaining unsorted part of the array.
   - Swaps it with the first element in the unsorted part.
3. Optimizations:
   - Used `swap()` from the C++ Standard Library for better readability and efficiency.
   - Segregated sorting logic into a separate function for modularity.
4. Time Complexity: O(N^2) (N is the number of elements in the array).
5. Space Complexity: O(1) (Sorting is done in place with no additional memory allocation).
*/
