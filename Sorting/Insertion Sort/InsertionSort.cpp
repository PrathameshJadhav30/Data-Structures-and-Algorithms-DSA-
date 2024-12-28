#include<iostream>
using namespace std;

// Function to print array
void display(int arr[], int size) 
{ 
    for (int i = 0; i < size; i++) 
        cout << arr[i] << "\t"; 
    cout << "\n"; 
}

// Function to perform insertion sort
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++) 
    { 
        int key = arr[i]; 
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, one position ahead
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Main function
int main() 
{ 
    int array[] = {5, 3, 1, 9, 8, 2, 4, 7}; 
    int size = sizeof(array) / sizeof(array[0]); 

    cout << "Before Insertion Sort:\n";
    display(array, size);

    insertionSort(array, size);

    cout << "After Insertion Sort:\n";
    display(array, size);

    return 0; 
}
