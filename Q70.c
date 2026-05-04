#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    void bellmanFord(int n, int m, vector<vector<int>>& edges, int src) {
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Step 1: Relax edges n-1 times
        for(int i = 0; i < n - 1; i++) {
            for(auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];

                if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Step 2: Detect negative cycle
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                cout << "NEGATIVE CYCLE\n";
                return;
            }
        }

        // Step 3: Print distances
        cout << "Shortest distances from source:\n";
        for(int i = 0; i < n; i++) {
            if(dist[i] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
        cout << endl;
    }
};