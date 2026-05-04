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
    scanf("%d", &s);  // source vertex

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Queue
    int queue[1000];
    int front = 0, rear = 0;

    // Start BFS
    queue[rear++] = s;
    visited[s] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        struct Node* temp = adj[node];

        while (temp) {
            int v = temp->data;

            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }

            temp = temp->next;
        }
    }

    return 0;
}