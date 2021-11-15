#include <bits/stdc++.h>
using namespace std;

#define INF 1e6

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int N;
    cin >> N;

    // Let no direct edge be taken as -1.
    vector<vector<int>> adj(N, vector<int>(N, 0));

    vector<vector<int>> dist(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] < 0)
                adj[i][j] = INF;
            dist[i][j] = adj[i][j];
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF) && (dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    cout << "Shortest Distance Matrix:\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            (dist[i][j] == INF) ? cout << "INF " : cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}