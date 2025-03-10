#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5  // Define the maximum size of the queue

// Queue structure
typedef struct {
    int arr[MAX];   // max = 5 
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
bool isEmpty(Queue *q) {
    return (q->front == -1);
}

// Check if the queue is full
bool isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

// Enqueue operation (Insert element)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;  // Set front to 0 if inserting the first element
    }
    q->arr[++q->rear] = value;
    printf("Inserted: %d\n", value);
}

// Dequeue operation (Remove element)
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    int value = q->arr[q->front++];
    
    // Reset queue if empty after dequeuing
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    
    return value;
}

// Get the front element
int front(Queue *q) {
    return isEmpty(q) ? -1 : q->arr[q->front];
}

// Display queue elements
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Main function for testing
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Front element: %d\n", front(&q));

    display(&q);

    return 0;
}
