#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function
void dfs(struct Node* adj[], int visited[], int s) {
    printf("%d ", s);
    visited[s] = 1;

    struct Node* temp = adj[s];

    while (temp) {
        int v = temp->data;

        if (!visited[v]) {
            dfs(adj, visited, v);
        }

        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    // Initialize adjacency list
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Undirected graph
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int s;
    scanf("%d", &s);  // starting vertex

    int visited[n];

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    dfs(adj, visited, s);

    return 0;
}