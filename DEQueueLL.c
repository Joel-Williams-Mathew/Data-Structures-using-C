#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 2  // Set max size to 2

int dq[N], front = -1, rear = -1;

bool isFull(int size) {
    return (front == (rear + 1) % size);
}

bool isEmpty() {
    return (front == -1);
}

void enqueue_rear(int size, int x) {
    if (isFull(size)) {
        printf("Deque is full, cannot insert %d\n", x);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    dq[rear] = x;
}

void dequeue_front(int size) {
    if (isEmpty()) {
        printf("Deque is empty, underflow condition\n");
        return;
    }
    int x = dq[front];
    printf("%d successfully deleted from front\n", x);
    if (front == rear) {
        front = rear = -1;  // Deque becomes empty
    } else {
        front = (front + 1) % size;
    }
}

void enqueue_front(int size, int x) {
    if (isFull(size)) {
        printf("Deque is full, cannot insert %d\n", x);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + size) % size;
    }
    dq[front] = x;
}

void dequeue_rear(int size) {
    if (isEmpty()) {
        printf("Deque is empty, underflow condition\n");
        return;
    }
    int x = dq[rear];
    printf("%d successfully deleted from rear\n", x);
    if (front == rear) {
        front = rear = -1;  // Deque becomes empty
    } else {
        rear = (rear - 1 + size) % size;
    }
}

void display(int size) {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements:\n");
    int i = front;
    while (true) {
        printf("%d\t", dq[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int size = N; // Use the defined max size
    int x, choice;

    do {
        printf("\n1. Insertion at FRONT\n2. Deletion from FRONT\n3. Insertion at REAR\n4. Deletion from REAR\n5. Display elements\n6. Exit\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &x);
                enqueue_front(size, x);
                break;
            case 2:
                dequeue_front(size);
                break;
            case 3:
                printf("Enter element to be inserted: ");
                scanf("%d", &x);
                enqueue_rear(size, x);
                break;
            case 4:
                dequeue_rear(size);
                break;
            case 5:
                display(size);
                break;
            case 6:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (true);

    return 0;
}
