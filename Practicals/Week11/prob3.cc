#include <bits/stdc++.h>
using namespace std;

// Given a set of elements, you have to partition the set into two subsets such that the sum of
// elements in both subsets is same. Design an algorithm and implement it using a program to solve
// this problem.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //freopen("input3.txt", "r", stdin);
    //freopen("output3.txt", "w", stdout);

    int N;
    cin >> N;
    vector<int> arr(N);

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    // DP. Using bottom-up approach.
    function<bool(vector<int>, int)> findPartition = [&](vector<int> arr, int N)
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];

        if (sum & 1)
            return false;

        bool part[sum / 2 + 1][N + 1];
        for (int i = 0; i <= N; i++)
            part[0][i] = true;

        int targetSum = sum / 2;
        for (int i = 1; i <= targetSum; i++)
            part[i][0] = false;

        // Filling the partition in bottom-up manner.
        for (int i = 1; i <= targetSum; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                part[i][j] = part[i][j - 1];
                if (i >= arr[j - 1])
                    part[i][j] = part[i][j] || part[i - arr[j - 1]][j - 1];
            }
        }

        // Prints table.
        // for (int i = 0; i <= targetSum; i++)
        // {
        //     for (int j = 0; j <= N; j++)
        //     {
        //         cout << part[i][j] << ' ';
        //     }
        //     cout << "\n";
        // }
        return part[targetSum][N];
    };

    if (sum & 1)
        cout << "No\n";
    else
    {
        bool ans = findPartition(arr, N);
        (ans) ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}