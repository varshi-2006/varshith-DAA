
#include <iostream>    // For input and output
#include <vector>      // For storing array elements
#include <algorithm>   // For swap function
#include <ctime>       // For time()
#include <chrono>      // For measuring execution time

using namespace std;
using namespace chrono;

// Bubble Sort
void bubble(vector<int>& a){

    // Repeat passes through the array
    for(int i=0; i<a.size()-1; i++)

        // Compare adjacent elements
        for(int j=0; j<a.size()-i-1; j++)

            // Swap if elements are in wrong order
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
}

// Selection Sort
void selection(vector<int>& a){

    // Move through each array position
    for(int i=0; i<a.size()-1; i++){

        int m = i; // Assume current element is minimum

        // Find the smallest element in remaining array
        for(int j=i+1; j<a.size(); j++)

            if(a[j] < a[m])
                m = j;

        // Place minimum element at correct position
        swap(a[i], a[m]);
    }
}

// Insertion Sort
void insertion(vector<int>& a){

    // Start from second element
    for(int i=1; i<a.size(); i++){

        int key = a[i]; // Store current element
        int j = i-1;

        // Shift larger elements one position right
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }

        // Insert key at its correct position
        a[j+1] = key;
    }
}

// Merge Sort - Merge two sorted parts
void merge(vector<int>& a, int l, int m, int r){

    // Create temporary left and right arrays
    vector<int> L(a.begin()+l, a.begin()+m+1);
    vector<int> R(a.begin()+m+1, a.begin()+r+1);

    int i=0, j=0, k=l;

    // Compare and merge elements from both arrays
    while(i<L.size() && j<R.size())
        a[k++] = (L[i]<R[j]) ? L[i++] : R[j++];

    // Copy remaining left elements
    while(i<L.size())
        a[k++] = L[i++];

    // Copy remaining right elements
    while(j<R.size())
        a[k++] = R[j++];
}

// Recursive Merge Sort function
void mergeSort(vector<int>& a, int l, int r){

    // Check whether the array has more than one element
    if(l<r){

        int m = (l+r)/2; // Find middle position

        mergeSort(a, l, m);   // Sort left half
        mergeSort(a, m+1, r); // Sort right half

        merge(a, l, m, r);    // Merge both sorted halves
    }
}

// Quick Sort - Partition function
int part(vector<int>& a, int l, int h){

    int p = a[h]; // Select last element as pivot
    int i = l-1;  // Index of smaller element

    // Place smaller elements before the pivot
    for(int j=l; j<h; j++)

        if(a[j]<p)
            swap(a[++i], a[j]);

    // Place pivot in its correct position
    swap(a[i+1], a[h]);

    return i+1; // Return pivot position
}

// Recursive Quick Sort function
void quick(vector<int>& a, int l, int h){

    // Continue if more than one element exists
    if(l<h){

        int p = part(a, l, h); // Partition the array

        quick(a, l, p-1); // Sort left part
        quick(a, p+1, h); // Sort right part
    }
}

// Main function
int main(){

    const int n = 100; // Number of elements

    vector<int> a(n), b; // Create original and temporary arrays

    srand(time(0)); // Initialize random number generator

    // Generate random numbers
    for(int &x : a)
        x = rand()%1000;

    // Function to test sorting algorithm execution time
    auto test = [&](string name, auto sortFun){

        b = a; // Copy original array for fair comparison

        // Start measuring execution time
        auto s = high_resolution_clock::now();

        sortFun(b); // Execute sorting algorithm

        // Stop measuring execution time
        auto e = high_resolution_clock::now();

        // Display algorithm name and execution time
        cout << name << " : "
             << duration_cast<microseconds>(e-s).count()
             << " us\n";
    };

    // Test Bubble Sort
    test("Bubble", [](vector<int>& x){
        bubble(x);
    });

    // Test Selection Sort
    test("Selection", [](vector<int>& x){
        selection(x);
    });

    // Test Insertion Sort
    test("Insertion", [](vector<int>& x){
        insertion(x);
    });

    // Test Merge Sort
    test("Merge", [](vector<int>& x){
        mergeSort(x, 0, x.size()-1);
    });

    // Test Quick Sort
    test("Quick", [](vector<int>& x){
        quick(x, 0, x.size()-1);
    });

    return 0; // End program
}
