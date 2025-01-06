// Using Hash-map and then sorting
#include <bits/stdc++.h>
using namespace std;

// Custom compare function to sort elements
// 1. Sort by frequency in descending order.
// 2. If frequencies are the same, sort by the first occurrence in ascending order.
bool compare(pair<int, pair<int, int>> p, pair<int, pair<int, int>> p1) {
    if (p.second.second != p1.second.second) {
        // Compare by frequency (higher frequency comes first)
        return (p.second.second > p1.second.second);
    } else {
        // Compare by first occurrence (lower index comes first)
        return (p.second.first < p1.second.first);
    }
}

// Function to sort array elements by frequency and first occurrence
void sortByFrequency(int arr[], int n) {
    // Map to store element as key, and a pair of first occurrence index and frequency as value
    unordered_map<int, pair<int, int>> mp;

    // Populate the map with element frequency and first occurrence
    for (int i = 0; i < n; i++) {
        if (mp.find(arr[i]) != mp.end()) {
            // Increment frequency if element already exists in map
            mp[arr[i]].second++;
        } else {
            // Initialize first occurrence and frequency
            mp[arr[i]] = make_pair(i, 1);
        }
    }

    // Convert the map to a vector of pairs for sorting
    vector<pair<int, pair<int, int>>> elements;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        elements.push_back(make_pair(it->first, it->second));
    }

    // Sort the vector using the custom compare function
    sort(elements.begin(), elements.end(), compare);

    // Print the sorted elements based on frequency and first occurrence
    for (size_t i = 0; i < elements.size(); i++) {
        int count = elements[i].second.second; // Frequency of the element
        while (count--) {
            cout << elements[i].first << " "; // Print the element multiple times
        }
    }
}

// Driver function
int main() {
    int arr[] = {10, 20, 10, 10, 20, 30, 30, 30, 30, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort and print the array elements by frequency
    sortByFrequency(arr, n);

    return 0;
}
