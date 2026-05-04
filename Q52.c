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

struct Node* LCA(struct Node* root, int p, int q){
    if(root == NULL)
        return NULL;

    if(root->data == p || root->data == q)
        return root;

    struct Node* left = LCA(root->left, p, q);
    struct Node* right = LCA(root->right, p, q);

    if(left != NULL && right != NULL)
        return root;

    return left != NULL ? left : right;
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int p, q;
    scanf("%d %d",&p,&q);

    struct Node* root = buildTree(arr, n);

    struct Node* res = LCA(root, p, q);

    if(res != NULL)
        printf("%d", res->data);

    return 0;
}