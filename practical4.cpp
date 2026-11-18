
#include <iostream>  // For input and output
#include <chrono>    // For measuring execution time

using namespace std;
using namespace std::chrono;

// Iterative Factorial Function
unsigned long long iterative(int n) {
    unsigned long long fact = 1; // Initialize factorial to 1

    // Multiply numbers from 1 to n
    for (int i = 1; i <= n; i++)
        fact *= i;

    return fact; // Return factorial result
}

// Recursive Factorial Function
unsigned long long recursive(int n) {

    // Base condition to stop recursion
    if (n <= 1)
        return 1;

    // Function calls itself with n-1
    return n * recursive(n - 1);
}

// Main Function
int main() {
    int n;

    // Get number from user
    cout << "Enter a number: ";
    cin >> n;

    // Start measuring iterative execution time
    auto start1 = high_resolution_clock::now();

    unsigned long long ans1 = iterative(n); // Calculate factorial

    // Stop measuring iterative execution time
    auto end1 = high_resolution_clock::now();

    // Start measuring recursive execution time
    auto start2 = high_resolution_clock::now();

    unsigned long long ans2 = recursive(n); // Calculate factorial

    // Stop measuring recursive execution time
    auto end2 = high_resolution_clock::now();

    // Display iterative factorial and execution time
    cout << "\nIterative Factorial = " << ans1 << endl;
    cout << "Time = "
         << duration_cast<nanoseconds>(end1 - start1).count()
         << " ns\n";

    // Display recursive factorial and execution time
    cout << "\nRecursive Factorial = " << ans2 << endl;
    cout << "Time = "
         << duration_cast<nanoseconds>(end2 - start2).count()
         << " ns\n";

    return 0; // End program
}
