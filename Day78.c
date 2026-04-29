#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX];

    // Initialize matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    int u, v, w;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // undirected
    }

    int key[MAX], visited[MAX];

    // Initialize
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {

        int min = INT_MAX, u = -1;

        // Find min key vertex
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // Update neighbors
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !visited[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    printf("%d", totalWeight);

    return 0;
}