#include <bits/stdc++.h>
using namespace std;

// DFS to find if path exists.
// Time Complexity: O(V^2).
// Space Complexity: O(V).
bool path_exists(vector<vector<int>> &adj, int src, int dest) {
    // Base case.
    if (src == dest)
        return true;

    bool visited[adj.size()] = {false};
    visited[src] = true;
    stack<int> s;
    s.push(src);

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        for (int i = 0; i < adj[v].size(); i++) {
            if (adj[v][i] == 0)
                continue;
            else {
                if (i == dest)
                    return true;
                if (!visited[i]) {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    // If no path exists.
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        adj.push_back(row);
    }
    int src, dest;
    cin >> src >> dest;

    path_exists(adj, src - 1, dest - 1) ? cout << "Path exists\n" : cout << "No Path exists\n";
    return 0;
}