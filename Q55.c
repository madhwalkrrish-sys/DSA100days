#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
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

void rightView(struct Node* root){
    if(root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear){
        int size = rear - front;

        for(int i=0;i<size;i++){
            struct Node* node = queue[front++];

            if(i == size - 1)
                printf("%d ", node->data);

            if(node->left)
                queue[rear++] = node->left;
            if(node->right)
                queue[rear++] = node->right;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}