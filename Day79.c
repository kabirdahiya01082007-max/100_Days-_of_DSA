#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX];

    // Initialize matrix
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;

    int u, v, w;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // remove if directed
    }

    int source;
    scanf("%d", &source);

    int dist[MAX], visited[MAX];

    // Initialize
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 1; count <= n; count++) {
        int min = INT_MAX, u = -1;

        // Find min distance node
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update neighbors
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !visited[v] &&
                dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}