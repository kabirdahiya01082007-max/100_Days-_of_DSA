#include <stdio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1) return;

    if (front == -1) front = 0;
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    if (front == -1) return -1;

    int val = queue[front++];
    if (front > rear)
        front = rear = -1;

    return val;
}

// Push
void push(int x) {
    stack[++top] = x;
}

// Pop
int pop() {
    return stack[top--];
}

int main() {
    int n, x;

    scanf("%d", &n);

    // Input queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Queue → Stack
    while (front != -1) {
        push(dequeue());
    }

    // Step 2: Stack → Queue
    while (top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    while (front != -1) {
        printf("%d ", dequeue());
    }

    return 0;
}