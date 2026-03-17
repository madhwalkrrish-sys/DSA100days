#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

void enqueue(int val){
    rear = (rear + 1) % MAX;
    queue[rear] = val;
    size++;
}

int dequeue(){
    int val = queue[front];
    front = (front + 1) % MAX;
    size--;
    return val;
}

int main(){
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        int val = dequeue();
        enqueue(val);
    }

    for(int i = 0; i < n; i++){
        printf("%d ", queue[(front + i) % MAX]);
    }

    return 0;
}