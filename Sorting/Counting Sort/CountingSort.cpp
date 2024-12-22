#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Counting Sort function
void countingSort(vector<int>& arr) {
    // Step 1: Find the maximum value in the array
    int maxElement = *max_element(arr.begin(), arr.end());
    
    // Step 2: Create a count array of size maxElement + 1, initialized to 0
    vector<int> count(maxElement + 1, 0);

    // Step 3: Count occurrences of each element in the input array
    for (int num : arr) {
        count[num]++;
    }

    // Step 4: Reconstruct the sorted array using the count array
    int index = 0;
    for (int i = 0; i <= maxElement; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    // Example usage
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    countingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
