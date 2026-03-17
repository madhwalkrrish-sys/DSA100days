#include <stdio.h>
#include <string.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int empty(){
    return front == -1;
}

int size(){
    if(empty()) return 0;
    return rear - front + 1;
}

void push_front(int x){
    if(front == -1){
        front = rear = 0;
        dq[front] = x;
    }else if(front > 0){
        dq[--front] = x;
    }
}

void push_back(int x){
    if(front == -1){
        front = rear = 0;
        dq[rear] = x;
    }else{
        dq[++rear] = x;
    }
}

void pop_front(){
    if(empty()) return;
    if(front == rear) front = rear = -1;
    else front++;
}

void pop_back(){
    if(empty()) return;
    if(front == rear) front = rear = -1;
    else rear--;
}

int getFront(){
    if(empty()) return -1;
    return dq[front];
}

int getBack(){
    if(empty()) return -1;
    return dq[rear];
}

void display(){
    if(empty()) return;
    for(int i = front; i <= rear; i++)
        printf("%d ", dq[i]);
    printf("\n");
}

int main(){
    int n, val;
    char op[20];

    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%s", op);

        if(strcmp(op,"push_front")==0){
            scanf("%d",&val);
            push_front(val);
        }
        else if(strcmp(op,"push_back")==0){
            scanf("%d",&val);
            push_back(val);
        }
        else if(strcmp(op,"pop_front")==0){
            pop_front();
        }
        else if(strcmp(op,"pop_back")==0){
            pop_back();
        }
        else if(strcmp(op,"front")==0){
            printf("%d\n", getFront());
        }
        else if(strcmp(op,"back")==0){
            printf("%d\n", getBack());
        }
        else if(strcmp(op,"size")==0){
            printf("%d\n", size());
        }
        else if(strcmp(op,"empty")==0){
            printf("%d\n", empty());
        }
    }

    display();
    return 0;
}