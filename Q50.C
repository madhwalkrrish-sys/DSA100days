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

struct Node* insert(struct Node* root, int val){
    if(root == NULL)
        return newNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

struct Node* search(struct Node* root, int key){
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

void inorder(struct Node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    int n, x, key;
    scanf("%d",&n);

    struct Node* root = NULL;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        root = insert(root, x);
    }

    scanf("%d",&key);

    struct Node* res = search(root, key);

    if(res == NULL)
        printf("Not Found");
    else
        inorder(res);

    return 0;
}