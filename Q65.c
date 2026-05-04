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
int dfs(int node, int parent, int visited[], struct Node* adj[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while (temp) {
        int v = temp->data;

        if (!visited[v]) {
            if (dfs(v, node, visited, adj))
                return 1;
        }
        else if (v != parent) {
            return 1;  // cycle found
        }

        temp = temp->next;
    }

    return 0;
}

// Function to check cycle
int hasCycle(int V, struct Node* adj[]) {
    int visited[V];

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj))
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

    // Input edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);

        // Undirected graph
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    if (hasCycle(V, adj))
        printf("YES");
    else
        printf("NO");

    return 0;
}