#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool isEmpty(Queue* q) {
    return q->size == 0;
}

bool isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

bool enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return false;
    }

    //enqueue는 (rear + 1)%MAX_SIZE에 추가
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size++;
    return true;
}

bool dequeue(Queue* q, int* value) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return false;
    }
    *value = q->data[q->front];
    //enqueue는 (rear + 1)%MAX_SIZE에 추출
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return true;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_SIZE;
        printf("%d ", q->data[index]);
    }
    printf("\n");
}

int main() {
    Queue q;
    int value;

    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(&q);

    dequeue(&q, &value);
    printf("Dequeued: %d\n", value);

    printQueue(&q);

    return 0;
}