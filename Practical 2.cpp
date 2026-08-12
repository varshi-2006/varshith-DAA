#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int linear(vector<int> &a, int x) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] == x) return i;
    return -1;
}

int binary(vector<int> &a, int x) {
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) return m;
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    vector<int> a(100000);
    for (int i = 0; i < 100000; i++) a[i] = i + 1;

    int x;
    cout << "Enter element: ";
    cin >> x;

    auto s = high_resolution_clock::now();
    int p = linear(a, x);
    auto e = high_resolution_clock::now();
    cout << "Linear Search: " << p << "\nTime: "
         << duration_cast<microseconds>(e - s).count() << " us\n";

    s = high_resolution_clock::now();
    p = binary(a, x);
    e = high_resolution_clock::now();
    cout << "Binary Search: " << p << "\nTime: "
         << duration_cast<microseconds>(e - s).count() << " us\n";

    return 0;
}