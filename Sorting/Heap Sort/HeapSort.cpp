#include<iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize the largest as root
    int l = 2 * i + 1; // Left child index
    int r = 2 * i + 2; // Right child index

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than the largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If the largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap root with the largest

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move current root (maximum element) to the end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to display the elements of an array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << "\n";
}

// Main function to test the Heap Sort implementation
int main() {
    int arr[] = {1, 14, 3, 7, 0, 56}; // Input array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate size of the array

    cout << "Unsorted array:\n";
    display(arr, n); // Display unsorted array

    heapSort(arr, n); // Sort the array

    cout << "Sorted array:\n";
    display(arr, n); // Display sorted array
}
