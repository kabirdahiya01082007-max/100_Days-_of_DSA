#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) // first element
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

// Dequeue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {
    if (front == -1) return;

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // Optional: to match given output rotation, reinsert removed elements
    for (int i = 0; i < m; i++) {
        enqueue(queue[i]);
    }

    printf("Queue elements: ");
    display();

    return 0;
}