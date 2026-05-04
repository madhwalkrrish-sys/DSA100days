#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node{
    int data;
    struct Node *left, *right;
};

struct QNode{
    struct Node* node;
    int hd;
};

struct Node* newNode(int val){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n){
    struct Node* nodes[n];

    for(int i=0;i<n;i++){
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i] != NULL){
            int l = 2*i + 1;
            int r = 2*i + 2;

            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* root = buildTree(arr, n);

    struct QNode queue[MAX];
    int front = 0, rear = 0;

    int map[200][MAX];
    int count[200] = {0};

    int offset = 100;

    queue[rear++] = (struct QNode){root, 0};

    while(front < rear){
        struct QNode temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd;

        map[hd + offset][count[hd + offset]++] = node->data;

        if(node->left)
            queue[rear++] = (struct QNode){node->left, hd - 1};
        if(node->right)
            queue[rear++] = (struct QNode){node->right, hd + 1};
    }

    for(int i = 0; i < 200; i++){
        if(count[i] > 0){
            for(int j = 0; j < count[i]; j++)
                printf("%d ", map[i][j]);
            printf("\n");
        }
    }

    return 0;
}