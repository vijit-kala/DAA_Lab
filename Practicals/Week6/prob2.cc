#include <bits/stdc++.h>
using namespace std;

// Main logic to check if graph is bipartite,
// using BFS.
// Time Complexity: O(V^2) as we used adjacency matrix.
// Space Complexity: O(V).
bool isBipartite(vector<vector<int>> &adj, int src) {
    int n = adj.size();

    vector<int> color_arr(n, -1);

    // Assigning first color to source.
    color_arr[src] = 1;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int val = q.front();
        q.pop();

        // Checking for self loops.
        if (adj[val][val] == 1)
            return false;

        for (int it = 0; it < n; it++) {
            if (adj[val][it] and color_arr[it] == -1) {
                color_arr[it] = 1 - color_arr[val];
                q.push(it);
            }
            // If edge between val and x node exists and their both of
            // the same color.
            else if (adj[val][it] and color_arr[it] == color_arr[val])
                return false;
        }
    }

    // If we reach here,
    // the graph is bipartite.
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj; // Adjacency matrix.
    // Taking input in graph.
    for (int i = 0; i < n; i++) {
        vector<int> row(n);
        for (auto &e : row)
            cin >> e;
        adj.push_back(row);
    }

    (isBipartite(adj, 0)) ? cout << "Yes Bipartite\n" : cout << "Not Bipartite\n";
    return 0;
}