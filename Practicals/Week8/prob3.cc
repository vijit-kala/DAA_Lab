#include <bits/stdc++.h>
using namespace std;

// Use kruskal's algo to find maximum spanning tree of
// a given graph.

int findParent(vector<int> parent, int v) {
    if (parent[v] < 0)
        return v;
    return findParent(parent, parent[v]);
}

bool unionByWeight(vector<int> &parent, int u, int v) {
    int pU = findParent(parent, u);
    int pV = findParent(parent, v);

    if (pU != pV) {
        if (pU <= pV) {
            parent[pU] += parent[pV];
            parent[pV] = pU;
        } else {
            parent[pV] += parent[pU];
            parent[pU] = pV;
        }
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    freopen("input3.txt", "r", stdin);
    freopen("output3.txt", "w", stdout);

    int N;
    cin >> N;

    vector<vector<int>> adj(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }

    function<int()> kruskal = [&] {
        int cost = 0;
        vector<pair<int, pair<int, int>>> g;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (adj[i][j]) {
                    g.push_back(make_pair(adj[i][j], make_pair(i, j)));
                }
            }
        }

        sort(g.begin(), g.end(), greater<pair<int, pair<int, int>>>());

        vector<int> parent(N, -1);
        for (auto it : g) {
            int u = it.second.first, v = it.second.second;
            int wt = it.first;

            if (unionByWeight(parent, u, v))
                cost += wt;
        }
        return cost;
    };

    cout << "Maximum Spanning Weight: " << kruskal() << endl;
    return 0;
}