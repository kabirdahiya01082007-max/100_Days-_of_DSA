#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    int y[n];
    for (int i = 0; i < n; i++) {
        y[i] = x[n - i - 1];
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", y[i]);
    }
}