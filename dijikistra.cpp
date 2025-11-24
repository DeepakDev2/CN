// DIJKSTRA ALGO


#include <iostream>
#include <vector>
using namespace std;

int findMinVertex(vector<int>& dist, vector<bool>& visited, int n) {
    int minVertex = -1;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, 1e9);
    vector<bool> visited(n, false);

    dist[start] = 0;

    for(int i = 0; i < n - 1; i++) {

        int u = findMinVertex(dist, visited, n);
        visited[u] = true;

        for(int v = 0; v < n; v++) {
            if(graph[u][v] && !visited[v]) {
                int newDist = dist[u] + graph[u][v];
                if(newDist < dist[v]) {
                    dist[v] = newDist;
                }
            }
        }
    }

    cout << "\nShortest distance from node " << start << ":\n";
    for(int i = 0; i < n; i++) {
        cout << "To " << i << " -> " << dist[i] << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);
}