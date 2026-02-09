#include <stdio.h>

int main() {
    int n;printf(">>>"); scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) {
        printf(">");
        scanf("%d", &x[i]);
    }
    printf("%d ", x[0]);
    for (int i = 1; i < n; i++) {
        if (x[i] != x[i-1]) {
            printf("%d ", x[i]);
        }
    }


    return 0;
}