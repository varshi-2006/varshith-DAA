#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Iterative Factorial
unsigned long long iterative(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

// Recursive Factorial
unsigned long long recursive(int n) {
    if (n <= 1)
        return 1;
    return n * recursive(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    auto start1 = high_resolution_clock::now();
    unsigned long long ans1 = iterative(n);
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    unsigned long long ans2 = recursive(n);
    auto end2 = high_resolution_clock::now();

    cout << "\nIterative Factorial = " << ans1 << endl;
    cout << "Time = " << duration_cast<nanoseconds>(end1 - start1).count() << " ns\n";

    cout << "\nRecursive Factorial = " << ans2 << endl;
    cout << "Time = " << duration_cast<nanoseconds>(end2 - start2).count() << " ns\n";

    return 0;
}