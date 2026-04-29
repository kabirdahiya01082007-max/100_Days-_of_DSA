#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

struct Node* adj[100];
int indegree[100];

// Queue
int queue[100];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        indegree[v]++; // important
    }

    // Push all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    // Kahn's Algorithm
    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);
        count++;

        struct Node* temp = adj[curr];
        while (temp) {
            indegree[temp->data]--;

            if (indegree[temp->data] == 0) {
                enqueue(temp->data);
            }

            temp = temp->next;
        }
    }

    // Cycle detection
    if (count != n) {
        printf("\nCycle exists, topological sort not possible");
    }

    return 0;
}