#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    int pos; scanf("%d", &pos);
    int num; scanf("%d", &num);

    int x1[n+1];
    for (int i = 0; i < pos - 1; i++) {x1[i] = x[i];}
    x1[pos - 1] = num;
    for (int i = pos; i < n + 1; i++) {x1[i] = x[i - 1];}

    for (int i = 0; i < n + 1; i++) {printf("%d ", x1[i]);}

    return 0;
}