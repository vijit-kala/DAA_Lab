#include <bits/stdc++.h>
using namespace std;

int prims(vector<vector<int>> &adj, int N) {
    int parent[N];
    int key[N];
    bool mstSet[N];

    for (int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;
    int totalWeight = 0;

    for (int i = 0; i < N; i++) {
        int mini = INT_MAX, u; // u is min index.
        for (int i = 0; i < N; i++) {
            if (mstSet[i] == false and key[i] < mini)
                mini = key[i], u = i;
        }

        mstSet[u] = true;
        totalWeight += mini;
        for (int v = 0; v < N; v++) {
            if (adj[u][v] && mstSet[v] == false && adj[u][v] < key[v])
                parent[v] = u, key[v] = adj[u][v];
        }
    }
    return totalWeight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int N;
    cin >> N;

    vector<vector<int>> adj(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }

    cout << "Minimum Spanning Weight : " << prims(adj, N) << endl;
    return 0;
}