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

struct Node* rotateRight(struct Node* head, int k){
    if(head == NULL || head->next == NULL || k == 0)
        return head;
    
    int length = 1;
    struct Node* temp = head;
    
    while(temp->next != NULL){
        temp = temp->next;
        length++;
    }
    
    temp->next = head;
    
    k = k % length;
    int steps = length - k;
    
    while(steps--){
        temp = temp->next;
    }
    
    head = temp->next;
    temp->next = NULL;
    
    return head;
}

void display(struct Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    int n, k;
    
    scanf("%d", &n);
    struct Node* head = createList(n);
    
    scanf("%d", &k);
    
    head = rotateRight(head, k);
    display(head);
    
    return 0;
}