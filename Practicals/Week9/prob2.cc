#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> weight(N);
    vector<int> value(N);

    vector<int> knapsack(N);
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> value[i];
        knapsack[i] = i;
    }

    int W;
    cin >> W;
    sort(knapsack.begin(), knapsack.end(), [&](int a, int b)
         { return (double)value[a] / weight[a] > (double)value[b] / weight[b]; });

    double ans = 0;
    vector<pair<int, int>> choice;
    for (auto it : knapsack)
    {
        double val = (double)value[it] / weight[it];
        double amt = min(W, weight[it]);
        ans += val * amt;
        choice.push_back({it + 1, amt});
        W -= min(W, weight[it]);
        if (W == 0)
            break;
    }

    cout << "Maximum value: " << ans << endl;
    cout << "Item-Weight\n";
    for (auto it : choice)
    {
        cout << it.first << "-" << it.second << "\n";
    }
    return 0;
}