#include <algorithm>
#include <iostream>
#include <vector>

#define INT_MAX 1000000

using namespace std;

void print_dist(vector<int> &dist) {
    for (int i : dist)
        cout << i << " ";
}

void dijkstra(int n, vector<vector<int>> &graph, int src, vector<int> &dist, vector<int> &pre) {
    dist.assign(n, INT_MAX);
    pre.assign(n, -1);
    vector<bool> vis(n, false);

    dist[src] = 0;
    for (int i = 0; i < n; i++) {
        int index, min_dist = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!vis[j] and dist[j] <= min_dist) {
                min_dist = dist[j], index = j;
            }
        }

        vis[index] = true;
        for (int v = 0; v < n; v++) {
            if (!vis[v] and graph[index][v] and dist[index] != INT_MAX and (dist[index] + graph[index][v] < dist[v])) {
                dist[v] = dist[index] + graph[index][v];
                pre[v] = index;
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
    int n;
    cin >> n;
    vector<vector<int>> graph;
    int k;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            cin >> k;
            row.push_back(k);
        }
        graph.push_back(row);
    }
    int src;
    cin >> src;
    --src;

    vector<int> dist(n), pre(n);
    dijkstra(n, graph, src, dist, pre);

    for (int i = 0; i < n; i++) {
        vector<int> curr_path = return_path(src, i, pre);
        for (int x : curr_path)
            cout << x << " ";
        cout << ": " << dist[i] << endl;
    }

    //print_dist(dist);
    return 0;
}