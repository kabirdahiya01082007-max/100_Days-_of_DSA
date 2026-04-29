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
int recStack[100];

// DFS function
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor))
                return 1;
        }
        else if (recStack[neighbor]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    int u, v;

    // Input edges (DIRECTED)
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    // Check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}