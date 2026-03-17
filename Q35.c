#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val){
    if(front == -1) front = 0;
    queue[++rear] = val;
}

void display(){
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
}

int main(){
    int n, x;

    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%d",&x);
        enqueue(x);
    }

    display();

    return 0;
}