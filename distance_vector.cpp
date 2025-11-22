// distance_vector.cpp
// Compile: g++ -std=c++17 distance_vector.cpp -o distance_vector
// Usage: provide adjacency matrix (0 for self, -1 for no direct link, positive for cost)
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main(){
    cout << "Distance Vector (RIP-like) simulator\nEnter N (nodes): ";
    int N; if(!(cin >> N)) return 0;
    vector<vector<int>> cost(N, vector<int>(N, INF));
    cout << "Enter adjacency matrix (use -1 for no link). Rows: " << N << "\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int x; cin >> x;
            if(x==-1) cost[i][j]=INF; else cost[i][j]=x;
        }
    }
    // initial distance tables: dist[node][dest]
    vector<vector<int>> dist(N, vector<int>(N, INF));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) dist[i][j]=0;
            else if(cost[i][j] < INF) dist[i][j] = cost[i][j];
        }
    }
    // iterative exchange until convergence or max rounds
    int rounds = 0;
    bool changed = true;
    while(changed && rounds < 100) {
        changed = false;
        rounds++;
        // for each router, receive neighbors' tables and update
        vector<vector<int>> newdist = dist;
        for(int u=0;u<N;u++){
            for(int v=0;v<N;v++){
                if(cost[u][v] >= INF) continue; // not neighbor
                for(int dest=0; dest<N; dest++){
                    // apply RIP hop-count rule: if neighbor says unreachable, skip
                    int via = dist[v][dest];
                    if(via >= INF) continue;
                    long long candidate = (long long)cost[u][v] + via;
                    // RIP: if candidate > 15 => unreachable (infinite)
                    if(candidate > 15) candidate = INF;
                    if(candidate < newdist[u][dest]){
                        newdist[u][dest] = (int)candidate;
                        changed = true;
                    }
                }
            }
        }
        dist.swap(newdist);
    }
    cout << "\nConverged in " << rounds << " rounds\n";
    cout << "Routing tables (costs; unreachable shown as INF or >15):\n";
    for(int i=0;i<N;i++){
        cout << "Router " << i << ":\n";
        for(int d=0; d<N; d++){
            if(dist[i][d] >= INF) cout << "  to " << d << " : INF\n";
            else cout << "  to " << d << " : " << dist[i][d] << "\n";
        }
    }
    return 0;
}
