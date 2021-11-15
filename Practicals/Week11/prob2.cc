#include <bits/stdc++.h>
using namespace std;

// Given a set of available types of coins. Lets suppose you have infinite supply
// of each type of coin. For a given value N, design an algo and implement a program
// to find number of ways in which these coins can be added to make sum value equals N.
// (Coin change problem)
// Time Complexity: O(NK)

int coinChange(vector<int> &coins, int N, int K)
{
    int dp[K + 1][N];

    for (int i = 0; i < N; i++)
        dp[0][i] = 1;

    for (int i = 1; i < K + 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // No of solutions including arr[j].
            int x = (i - coins[j] >= 0) ? dp[i - coins[j]][j] : 0;

            // No of solutions excluding arr[j].
            int y = (j >= 1) ? dp[i][j - 1] : 0;

            // Total.
            dp[i][j] = x + y;
        }
    }
    return dp[K][N - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int N, K;
    cin >> N;

    vector<int> coins(N);
    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }
    cin >> K;

    cout << coinChange(coins, N, K);
    return 0;
}