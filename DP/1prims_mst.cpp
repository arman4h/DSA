#include <bits/stdc++.h>
using namespace std;

// g stores: ((u, v), weight)
vector<pair<pair<int,int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int,int>, int>> &g) {
    // Build adjacency list: adj[u] = {(v, weight)}
    vector<vector<pair<int,int>>> adj(n + 1);
    for (auto &edge : g) {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        adj[u].push_back({v, w});
        // Don't add reverse here since input already has both directions
    }

    // Min-heap: (weight, from, to)
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    vector<bool> visited(n + 1, false);
    vector<pair<pair<int,int>, int>> mst;

    // Start from node 1
    visited[1] = true;
    for (auto &[v, w] : adj[1])
        pq.push({w, 1, v});

    while (!pq.empty() && mst.size() < n - 1) {
        auto [wt, u, v] = pq.top(); pq.pop();
        if (visited[v]) continue;

        visited[v] = true;
        mst.push_back({{u, v}, wt});

        for (auto &[nv, nw] : adj[v])
            if (!visited[nv])
                pq.push({nw, v, nv});
    }
    return mst;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<pair<int,int>, int>> g(m);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g[i] = {{u, v}, w};
        }
        auto result = calculatePrimsMST(n, m, g);
        for (auto &edge : result)
            cout << edge.first.first << " " << edge.first.second << " " << edge.second << "\n";
    }
    return 0;
}