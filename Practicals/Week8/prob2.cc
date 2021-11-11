#include <bits/stdc++.h>
using namespace std;

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

    //freopen("input2.txt", "r", stdin);
    //freopen("output2.txt", "w", stdout);

    int N;
    cin >> N;

    vector<vector<int>> adj(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }

    function<int(vector<vector<int>> &, int)>
        kruskal = [&](vector<vector<int>> &adj, int N) {
            vector<pair<int, pair<int, int>>> g;
            int cost = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (adj[i][j]) {
                        g.push_back(make_pair(adj[i][j], make_pair(i, j)));
                    }
                }
            }

            sort(g.begin(), g.end());

            vector<int> parent(N, -1);
            for (auto it : g) {
                int u = it.second.first;
                int v = it.second.second;
                int wt = it.first;

                if (unionByWeight(parent, u, v))
                    cost += wt;
            }
            return cost;
        };

    int cost = kruskal(adj, N);
    cout << "Minimum Spanning Weight: " << cost << endl;
    return 0;
}