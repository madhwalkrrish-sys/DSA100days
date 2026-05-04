#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function
int dfs(int node, int visited[], int recStack[], struct Node* adj[]) {
    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];

    while (temp) {
        int v = temp->data;

        if (!visited[v]) {
            if (dfs(v, visited, recStack, adj))
                return 1;
        }
        else if (recStack[v]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[node] = 0; // remove from recursion stack
    return 0;
}

// Function to detect cycle
int hasCycle(int V, struct Node* adj[]) {
    int visited[V], recStack[V];

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    // Check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj))
                return 1;
        }
    }

    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];

    // Initialize
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    int u, v;

    // Input edges (DIRECTED)
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    if (hasCycle(V, adj))
        printf("YES");
    else
        printf("NO");

    return 0;
}