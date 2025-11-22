// link_state.cpp
// Compile: g++ -std=c++17 link_state.cpp -o link_state
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main()
{
    cout << "Link-State (OSPF-like) simulator\nEnter N (nodes): ";
    int N;
    if (!(cin >> N))
        return 0;
    vector<vector<pair<int, int>>> adj(N);
    cout << "Enter number of links: ";
    int L;
    cin >> L;
    cout << "Then enter L lines: u v cost (0-based nodes)\n";
    for (int i = 0; i < L; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    auto dijkstra = [&](int src)
    {
        vector<int> dist(N, INF), parent(N, -1);
        dist[src] = 0;
        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src});
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u])
                continue;
            for (auto &e : adj[u])
            {
                int v = e.first, w = e.second;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        // build routing table: for each dest, find next hop
        vector<int> nextHop(N, -1);
        for (int v = 0; v < N; v++)
        {
            if (v == src || dist[v] >= INF)
                continue;
            int cur = v, prev = parent[v];
            if (prev == -1)
            { // direct neighbor?
                // find direct neighbor
                nextHop[v] = v;
                continue;
            }
            // walk back to find node whose parent is src (next hop)
            while (parent[cur] != src && parent[cur] != -1)
            {
                cur = parent[cur];
            }
            if (parent[cur] == src)
                nextHop[v] = cur;
            else
                nextHop[v] = v; // direct or same
        }
        return tuple(dist, nextHop);
    };

    for (int src = 0; src < N; src++)
    {
        auto [dist, nextHop] = dijkstra(src);
        cout << "\nRouting table for router " << src << ":\n";
        cout << "Destination\tCost\tNextHop\n";
        for (int d = 0; d < N; d++)
        {
            if (dist[d] >= INF)
                cout << d << "\t\tINF\t-\n";
            else
            {
                cout << d << "\t\t" << dist[d] << "\t";
                if (d == src)
                    cout << "-\n";
                else if (nextHop[d] == -1)
                    cout << d << "\n";
                else
                    cout << nextHop[d] << "\n";
            }
        }
    }
    return 0;
}
