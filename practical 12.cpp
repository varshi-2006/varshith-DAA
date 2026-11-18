
#include <iostream>   // For input and output
#include <vector>     // For using vectors
#include <algorithm>  // For min() function
#include <climits>    // For INT_MAX

using namespace std;

// Function to calculate minimum travelling cost
int tsp(int mask, int pos, vector<vector<int>>& cost,
        vector<vector<int>>& dp, int n) {

    // Check if all cities are visited
    if (mask == (1 << n) - 1)

        // Return to starting city (city 0)
        return cost[pos][0];

    // Check if result is already calculated
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX; // Initialize minimum cost to infinity

    // Visit every unvisited city
    for (int city = 0; city < n; city++) {

        // Check whether the city is not visited
        if ((mask & (1 << city)) == 0) {

            // Calculate cost of visiting the next city
            int newCost = cost[pos][city]
                        + tsp(mask | (1 << city), city,
                              cost, dp, n);

            // Find minimum travelling cost
            ans = min(ans, newCost);
        }
    }

    // Store result in DP table and return it
    return dp[mask][pos] = ans;
}

// Main function
int main() {

    int n;

    // Get number of cities
    cout << "Enter number of cities: ";
    cin >> n;

    // Create cost matrix
    vector<vector<int>> cost(n, vector<int>(n));

    // Read travelling costs between cities
    cout << "Enter the cost matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    // Create DP table and initialize with -1
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    // Start from city 0 with only city 0 visited
    int minCost = tsp(1, 0, cost, dp, n);

    // Display minimum travelling cost
    cout << "Minimum travelling cost: " << minCost << endl;

    return 0; // End program
}
