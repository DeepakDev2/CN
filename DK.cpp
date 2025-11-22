#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> g(n+1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});   // Remove this line if graph is directed
    }

    int s, t;
    cin >> s >> t;

    vector<int> dist(n+1, 1e9), parent(n+1, -1);
    dist[s] = 0;

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto &p : g[u]) {
            int v = p.first;
            int w = p.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // If no path
    if (dist[t] == 1e9) {
        cout << "No path\n";
        return 0;
    }

    // Reconstructing path
    vector<int> path;
    for (int cur = t; cur != -1; cur = parent[cur])
        path.push_back(cur);

    reverse(path.begin(), path.end());

    cout << "Shortest distance: " << dist[t] << "\n";
    cout << "Path: ";
    for (int x : path) cout << x << " ";
    cout << "\n";

    return 0;
}