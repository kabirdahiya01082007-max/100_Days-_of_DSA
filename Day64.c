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
int visited[100];

// Queue
int queue[100];
int front = 0, rear = 0;

// Enqueue
void enqueue(int x) {
    queue[rear++] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Check empty
int isEmpty() {
    return front == rear;
}

// BFS function
void bfs(int s) {
    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                enqueue(temp->data);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Undirected graph
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        struct Node* newNode2 = createNode(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    int s;
    scanf("%d", &s);

    // Perform BFS
    bfs(s);

    return 0;
}