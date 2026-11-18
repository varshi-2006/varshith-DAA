
#include <iostream>    // For input and output
#include <vector>      // For storing array elements
#include <cstdlib>     // For rand() and srand()
#include <ctime>       // For time()
#include <chrono>      // For measuring execution time
#include <algorithm>   // For swap() and reverse()

using namespace std;
using namespace chrono;

// Function to maintain the heap property
void heapify(vector<int>& a, int n, int i, bool isMax) {

    int l = 2*i + 1; // Left child index
    int r = 2*i + 2; // Right child index
    int idx = i;     // Assume current node is largest or smallest

    // Check left child according to heap type
    if(l < n && (isMax ? a[l] > a[idx] : a[l] < a[idx]))
        idx = l;

    // Check right child according to heap type
    if(r < n && (isMax ? a[r] > a[idx] : a[r] < a[idx]))
        idx = r;

    // If parent is not in the correct position
    if(idx != i) {
        swap(a[i], a[idx]);       // Swap parent and child
        heapify(a, n, idx, isMax); // Heapify the affected subtree
    }
}

// Function to perform Heap Sort
void heapSort(vector<int>& a, bool isMax) {

    int n = a.size(); // Get array size

    // Build Max Heap or Min Heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i, isMax);

    // Extract elements one by one
    for(int i = n-1; i > 0; i--) {
        swap(a[0], a[i]);       // Move root to the end
        heapify(a, i, 0, isMax); // Restore heap property
    }

    // Reverse result for Min Heap to get ascending order
    if(!isMax)
        reverse(a.begin(), a.end());
}

// Function to display execution time
void showTime(string name,
              high_resolution_clock::time_point s,
              high_resolution_clock::time_point e) {

    cout << "\n==== " << name << " ====\n";

    // Display time in nanoseconds
    cout << "Nanoseconds  : "
         << duration_cast<nanoseconds>(e-s).count() << " ns\n";

    // Display time in microseconds
    cout << "Microseconds : "
         << duration_cast<microseconds>(e-s).count() << " us\n";

    // Display time in milliseconds
    cout << "Milliseconds : "
         << duration_cast<milliseconds>(e-s).count() << " ms\n";

    // Display time in seconds
    cout << "Seconds      : "
         << duration<double>(e-s).count() << " s\n";
}

// Main function
int main() {

    int n;

    // Get array size from user
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n); // Create array

    srand(time(0)); // Initialize random number generator

    // Generate random array elements
    for(int& x : arr)
        x = rand() % 100000;

    // Create two copies of original array
    auto a1 = arr;
    auto a2 = arr;

    // Measure Max Heap Sort execution time
    auto s1 = high_resolution_clock::now();

    heapSort(a1, true); // Perform Max Heap Sort

    auto e1 = high_resolution_clock::now();

    // Measure Min Heap Sort execution time
    auto s2 = high_resolution_clock::now();

    heapSort(a2, false); // Perform Min Heap Sort

    auto e2 = high_resolution_clock::now();

    // Display Max Heap Sort execution time
    showTime("MAX HEAP SORT", s1, e1);

    // Display Min Heap Sort execution time
    showTime("MIN HEAP SORT", s2, e2);

    return 0; // End program
}
