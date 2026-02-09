#include <stdio.h>

int main() {
    int n;printf(">>>"); scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) {
        printf(">");
        scanf("%d", &x[i]);
    }
    int m;printf(">>>"); scanf("%d", &m);
    int y[m];
    for (int i = 0; i < m; i++) {
        printf(">");
        scanf("%d", &y[i]);
    }
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (x[i] <= y[j]) {
            printf("%d ", x[i]);
            i++;
        } else {
            printf("%d ", y[j]);
            j++;
        }
    }
    while (i < n) {printf("%d ", x[i]); i++;}
    while (j < m) {printf("%d ", y[j]); j++;}


    return 0;
}