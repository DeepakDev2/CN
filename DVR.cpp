#include <bits/stdc++.h>
using namespace std;

#define INF 9999

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    vector<vector<int>> dist(n, vector<int>(n));
    vector<vector<int>> nextHop(n, vector<int>(n));

    cout << "Enter cost adjacency matrix (9999 for INF):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            dist[i][j] = cost[i][j];
            if (cost[i][j] != INF && i != j)
                nextHop[i][j] = j;
            else
                nextHop[i][j] = -1;
        }
    }

    // Distance Vector / Bellman-Ford updates
    bool changed;
    do {
        changed = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[i][k] + cost[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + cost[k][j];
                        nextHop[i][j] = nextHop[i][k];
                        changed = true;
                    }
                }
            }
        }
    
    } while (changed);

    cout << "\n--- FINAL ROUTING TABLES ---\n";
    for (int i = 0; i < n; i++) {
        cout << "\nRouter " << i << ":\n";
        cout << "Destination\tCost\tNextHop\n";
        for (int j = 0; j < n; j++) {
            cout << j << "\t\t" << dist[i][j] << "\t\t";
            if (i == j) cout << "-";
            else cout << nextHop[i][j];
            cout << "\n";
        }
    }

    return 0;
}
