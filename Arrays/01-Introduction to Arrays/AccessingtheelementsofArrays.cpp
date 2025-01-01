#include <iostream> // Include the iostream library for input and output operations

using namespace std;

int main() {
    // Declare and initialize an array of integers
    int arr[] = {1, 2, 3, 4, 5};

    // Calculate the number of elements in the array
    int arrLen = sizeof(arr) / sizeof(int);

    // Loop through the array to access and display each element
    for (int i = 0; i < arrLen; i++) {
        cout << "Element " << i << " = " << arr[i] << endl;
    }

    return 0; // Exit the program successfully
}
