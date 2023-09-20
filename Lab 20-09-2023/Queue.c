#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = value;
}

int dequeue() {
    int value;

    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    value = queue[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }

    return value;
}

void displayQueue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    displayQueue();

    printf("Dequeued: %d\n", dequeue());

    displayQueue();

    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    return 0;
}
