#include<iostream>
using namespace std;

// Function to swap two elements
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* 
Partition function:
Divides the array into two parts based on the pivot. 
Elements smaller than the pivot are moved to its left, 
and elements larger are moved to its right.
*/
int partition(int array[], int low, int high) {
    int pivot = array[high]; // Choose the last element as the pivot
    int swapIndex = low - 1; // Initialize the swapping index

    for (int j = low; j < high; j++) {
        // If the current element is smaller than the pivot
        if (array[j] < pivot) {
            swapIndex++; // Move the swapping index forward
            swap(&array[swapIndex], &array[j]); // Swap elements
        }
    }
    // Place the pivot in its correct position
    swap(&array[swapIndex + 1], &array[high]);
    return swapIndex + 1; // Return the partition index
}

/*
Recursive quickSort function:
Sorts the elements before and after the partition.
*/
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // Get the partition index
        int partitionIndex = partition(array, low, high);

        // Recursively sort the left and right partitions
        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

// Function to display the elements of the array
void display(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    int array[] = {7, 9, 1, 3, 5, 2, 6, 0, 4, 8};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Before Sorting:\n";
    display(array, size);

    // Apply quicksort
    quickSort(array, 0, size - 1);

    cout << "After Sorting:\n";
    display(array, size);

    return 0;
}
