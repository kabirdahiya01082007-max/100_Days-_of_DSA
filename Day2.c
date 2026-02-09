#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    int num; scanf("%d", &num);
    int x1[n-1], s;
    s = num - 1;

    for (int i = 0; i < n; i++) {
        if (i < s) {x1[i] = x[i];}
        else if (i == s) {continue;}
        else {x1[i-1] = x[i];}
    }
    
    for (int i = 0; i < n - 1; i++) {printf("%d ", x1[i]);}

    return 0;
}