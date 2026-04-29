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
int stack[100];
int top = -1;

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void dfs(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(temp->data);
        }
        temp = temp->next;
    }

    // Push after visiting all neighbors
    push(v);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;

    // Input edges (DIRECTED)
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    // Call DFS for all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print topological order (reverse stack)
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}