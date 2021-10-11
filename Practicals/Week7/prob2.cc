#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX 100000

void bellman_ford(vector<vector<int>> &adj, int src, vector<int> &dist, vector<int> &pre) {
    int V = adj.size();
    dist.assign(V, INT_MAX);
    pre.assign(V, -1);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (adj[u][v]) {
                    if (dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]) {
                        dist[v] = dist[u] + adj[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

vector<int> return_path(int src, int to, vector<int> const &pre) {
    vector<int> path;
    for (int v = to; v != src; v = pre[v]) {
        path.push_back(v + 1);
    }
    path.push_back(src + 1);
    return path;
}

int main() {
    int V;
    cin >> V;
    vector<vector<int>> adj;
    for (int i = 0; i < V; i++) {
        int k;
        vector<int> val(V);
        for (int j = 0; j < V; j++) {
            cin >> k;
            val.push_back(k);
        }
        adj.push_back(val);
    }
    int src;
    cin >> src;
    --src;

    vector<int> dist(V), pre(V);
    bellman_ford(adj, src, dist, pre);

    for (int i = 0; i < V; i++) {
        vector<int> curr_path = return_path(src, i, pre);
        for (int x : curr_path)
            cout << x << " ";
        (dist[i] == INT_MAX) ? cout << ": INF\n" : cout << ": " << dist[i] << endl;
    }
    return 0;
}