#include <iostream>
#include <vector>
using namespace std;

int minCoins(vector<int> coins, int amount)
{
    vector<int> dp(amount + 1, 9999);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i)
            {
                if (dp[i - coin] + 1 < dp[i])
                {
                    dp[i] = dp[i - coin] + 1;
                }
            }
        }
    }

    if (dp[amount] == 9999)
        return -1;

    return dp[amount];
}

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    int answer = minCoins(coins, amount);

    if (answer == -1)
        cout << "Amount cannot be formed.";
    else
        cout << "Minimum coins = " << answer;

    return 0;
}