#include <iostream> // Include iostream for input and output operations
using namespace std;

int main() {
    // Declare and initialize a 2D array with 2 rows and 3 columns
    int x[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // Loop through each row
    for (int i = 0; i < 2; i++) {
        // Loop through each column in the current row
        for (int j = 0; j < 3; j++) {
            // Output the value of the current array element
            cout << "Element at x[" << i << "][" << j << "]: ";
            cout << x[i][j] << endl; // Corrected variable name from 'a' to 'x'
        }
    }

    return 0; // Exit the program successfully
}
