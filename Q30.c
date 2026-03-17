#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createPolynomial(int n){
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int c, e;
    
    for(int i = 0; i < n; i++){
        scanf("%d %d", &c, &e);
        
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->exp = e;
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

void displayPolynomial(struct Node* head){
    while(head != NULL){
        if(head->exp == 0)
            printf("%d", head->coeff);
        else if(head->exp == 1)
            printf("%dx", head->coeff);
        else
            printf("%dx^%d", head->coeff, head->exp);
        
        if(head->next != NULL)
            printf(" + ");
            
        head = head->next;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    struct Node* poly = createPolynomial(n);
    displayPolynomial(poly);
    
    return 0;
}