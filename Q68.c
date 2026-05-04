#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];

void topologicalSort(int n) {
    int queue[MAX], front = 0, rear = 0;
    int result[MAX], index = 0;

    // Step 1: Calculate indegree
    for(int i = 0; i < n; i++) {
        indegree[i] = 0;
        for(int j = 0; j < n; j++) {
            if(adj[j][i]) {
                indegree[i]++;
            }
        }
    }

    // Step 2: Add nodes with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 3: Process queue
    while(front < rear) {
        int u = queue[front++];
        result[index++] = u;

        for(int v = 0; v < n; v++) {
            if(adj[u][v]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // Step 4: Check cycle
    if(index != n) {
        printf("Cycle exists! No Topological Ordering.\n");
        return;
    }

    // Print result
    printf("Topological Order: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
}

int main() {
    int n = 6;

    // Initialize graph
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Example DAG
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(n);

    return 0;
}