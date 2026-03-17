#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop(){
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main(){
    char s[100];
    scanf("%[^\n]", s);

    int i = 0;
    while(s[i] != '\0'){
        if(isdigit(s[i])){
            push(s[i] - '0');
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            int b = pop();
            int a = pop();
            int res;

            if(s[i] == '+') res = a + b;
            else if(s[i] == '-') res = a - b;
            else if(s[i] == '*') res = a * b;
            else res = a / b;

            push(res);
        }
        i++;
    }

    printf("%d", pop());

    return 0;
}