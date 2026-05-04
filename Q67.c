#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

// DFS function
void dfs(int v, int n) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }

    // push to stack
    stack[++top] = v;
}

// Topological Sort
void topoSort(int n) {
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, n);
        }
    }

    printf("Topological Order: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
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

    topoSort(n);

    return 0;
}