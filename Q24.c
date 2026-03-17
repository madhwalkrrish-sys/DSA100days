#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createList(int n){
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int x;
    
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;
        
        if(head == NULL){
            head = newNode;
            temp = newNode;
        }else{
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

struct Node* deleteKey(struct Node* head, int key){
    if(head == NULL)
        return head;
        
    if(head->data == key){
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    struct Node *curr = head, *prev = NULL;
    
    while(curr != NULL && curr->data != key){
        prev = curr;
        curr = curr->next;
    }
    
    if(curr != NULL){
        prev->next = curr->next;
        free(curr);
    }
    
    return head;
}

void display(struct Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    int n, key;
    
    scanf("%d", &n);
    struct Node* head = createList(n);
    
    scanf("%d", &key);
    
    head = deleteKey(head, key);
    display(head);
    
    return 0;
}