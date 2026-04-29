#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n, m;

// DFS function
void dfs(int v) {
    visited[v] = 1;

    for (int i = 1; i <= n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    int u, v;

    // Initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    int components = 0;

    // Count components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d", components);

    return 0;
}