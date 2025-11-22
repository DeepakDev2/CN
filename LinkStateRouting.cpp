#include <bits/stdc++.h>
using namespace std;

/*
   OSPF Simulation:
   ----------------
   1. Each router generates an LSA listing its neighbors and costs
   2. All LSAs are flooded to all routers → LSDB built
   3. Each router runs Dijkstra to compute shortest paths
*/

class OSPF {
public:
    int n;   // number of routers
    vector<vector<int>> cost; // adjacency matrix (link costs)

    OSPF(int n) {
        this->n = n;
        cost.assign(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++)
            cost[i][i] = 0;
    }

    // Add a link (LSA entry)
    void addLink(int u, int v, int w) {
        cost[u][v] = w;
        cost[v][u] = w;
    }

    // Dijkstra's algorithm (OSPF SPF computation)
    void dijkstra(int src) {
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);

        dist[src] = 0;

        for (int i = 0; i < n - 1; i++) {
            int u = -1;

            // pick unvisited node with smallest distance
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;
            }

            visited[u] = true;

            // relax edges
            for (int v = 0; v < n; v++) {
                if (cost[u][v] != INT_MAX &&
                    dist[u] + cost[u][v] < dist[v]) {

                    dist[v] = dist[u] + cost[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "\n--- Shortest Paths from Router " << src << " ---\n";
        for (int i = 0; i < n; i++) {
            if (i == src) continue;

            cout << "To Router " << i << " : Cost = " << dist[i] << " | Path = ";

            printPath(parent, i);
            cout << "\n";
        }
        cout << "-------------------------------------------\n";
    }

    void printPath(vector<int> &parent, int node) {
        if (parent[node] == -1) {
            cout << node;
            return;
        }
        printPath(parent, parent[node]);
        cout << " -> " << node;
    }

    void runOSPF() {
        cout << "\n=== OSPF Shortest Path First (SPF) Computation ===\n";
        for (int i = 0; i < n; i++) {
            dijkstra(i);
        }
    }
};

int main() {
    int routers;
    cout << "Enter number of routers: ";
    cin >> routers;

    OSPF ospf(routers);

    int links;
    cout << "Enter number of links: ";
    cin >> links;

    cout << "Enter links (u v cost):\n";
    for (int i = 0; i < links; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ospf.addLink(u, v, w);
    }

    // Run OSPF SPF (Dijkstra)
    ospf.runOSPF();

    return 0;
}
