#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int front, rear;
    int items[MAX];
} Queue;

void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (q->front > q->rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->items[q->front++];
}

int main() {
    Queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued: %d\n", dequeue(&q)); // 10
    printf("Dequeued: %d\n", dequeue(&q)); // 20
}
