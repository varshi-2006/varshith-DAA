
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// Function for Linear Search
int linear(vector<int> &a, int x) {
    // Check each element one by one
    for (int i = 0; i < a.size(); i++)
        if (a[i] == x)
            return i;  // Return index if element is found

    return -1;  // Return -1 if element is not found
}

// Function for Binary Search
int binary(vector<int> &a, int x) {
    // Set left and right positions
    int l = 0, r = a.size() - 1;

    // Repeat while search range is valid
    while (l <= r) {
        // Find middle position
        int m = (l + r) / 2;

        // Check if middle element is the target
        if (a[m] == x)
            return m;

        // If target is greater, search right half
        if (a[m] < x)
            l = m + 1;

        // If target is smaller, search left half
        else
            r = m - 1;
    }

    return -1;  // Return -1 if element is not found
}

int main() {
    // Create an array of 100000 elements
    vector<int> a(100000);

    // Store values from 1 to 100000
    for (int i = 0; i < 100000; i++)
        a[i] = i + 1;

    int x;
    cout << "Enter element: ";
    cin >> x;

    // Start measuring Linear Search time
    auto s = high_resolution_clock::now();

    // Perform Linear Search
    int p = linear(a, x);

    // Stop measuring Linear Search time
    auto e = high_resolution_clock::now();

    // Display Linear Search result and execution time
    cout << "Linear Search: " << p << "\nTime: "
         << duration_cast<microseconds>(e - s).count() << " us\n";

    // Start measuring Binary Search time
    s = high_resolution_clock::now();

    // Perform Binary Search
    p = binary(a, x);

    // Stop measuring Binary Search time
    e = high_resolution_clock::now();

    // Display Binary Search result and execution time
    cout << "Binary Search: " << p << "\nTime: "
         << duration_cast<microseconds>(e - s).count() << " us\n";

    return 0;  // End the program
}
