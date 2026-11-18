
#include <iostream>  // For input and output
#include <vector>    // For using vector
using namespace std;

// Function to find minimum number of coins
int minCoins(vector<int> coins, int amount)
{
    // Create DP array and initialize all values to 9999
    vector<int> dp(amount + 1, 9999);

    dp[0] = 0; // Zero coins are needed to make amount 0

    // Check all amounts from 1 to given amount
    for (int i = 1; i <= amount; i++)
    {
        // Check every coin denomination
        for (int coin : coins)
        {
            // Check if coin value is less than or equal to amount
            if (coin <= i)
            {
                // Update minimum number of coins
                if (dp[i - coin] + 1 < dp[i])
                {
                    dp[i] = dp[i - coin] + 1;
                }
            }
        }
    }

    // Check if the amount can be formed
    if (dp[amount] == 9999)
        return -1;

    return dp[amount]; // Return minimum number of coins
}

// Main function
int main()
{
    int n, amount;

    // Read number of coin denominations
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n); // Create vector to store coins

    // Read coin denominations
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    // Read target amount
    cout << "Enter amount: ";
    cin >> amount;

    // Call function to calculate minimum coins
    int answer = minCoins(coins, amount);

    // Display the result
    if (answer == -1)
        cout << "Amount cannot be formed.";
    else
        cout << "Minimum coins = " << answer;

    return 0; // End program
}
