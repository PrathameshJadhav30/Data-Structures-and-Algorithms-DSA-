#include <iostream>
#include <vector>
#include <utility> // For pair
#include <algorithm> // For sort

using namespace std;

// Function to find K pairs with the smallest sums
vector<pair<int, int>> kSmallestPairs(int arr1[], int n1, int arr2[], int n2, int k) {
    vector<pair<int, int>> result;

    // Generate all possible pairs and calculate their sums
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            result.push_back({arr1[i], arr2[j]}); // Store the pair
        }
    }

    // Sort the pairs based on their sums
    sort(result.begin(), result.end(), [](pair<int, int> a, pair<int, int> b) {
        return (a.first + a.second) < (b.first + b.second);
    });

    // Keep only the first K pairs
    vector<pair<int, int>> kPairs;
    for (int i = 0; i < min(k, (int)result.size()); i++) {
        kPairs.push_back(result[i]);
    }

    return kPairs;
}

int main() {
    // Example arrays
    int arr1[] = {1, 7, 11};
    int arr2[] = {2, 4, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k = 3; // Number of pairs to find

    // Find the K pairs with the smallest sums
    vector<pair<int, int>> result = kSmallestPairs(arr1, n1, arr2, n2, k);

    // Output the result
    cout << "K pairs with the smallest sums:" << endl;
    for (const auto& pair : result) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }

    return 0;
}
