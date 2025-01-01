#include <iostream> // Include the iostream library for input and output operations

using namespace std;

int main() {
    // Declare and initialize an array of integers
    int arr[] = {1, 2, 3, 4, 5};

    // Print the memory address of the first element
    cout << "Address of first element: " << &arr[0] << endl;

    // Print the memory address of the second element
    cout << "Address of second element: " << &arr[1] << endl;

    // Print the memory address of the third element
    cout << "Address of third element: " << &arr[2] << endl;

    return 0; // Exit the program successfully
}
