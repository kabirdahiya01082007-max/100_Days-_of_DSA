#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    int num; scanf("%d", &num);
    int s, com = 0;
    for (int i = 0; i < n; i++) {
        if (num == x[i]) {
            s = i; com++;
        }
        else {
            com++;
        }
    }
    if (x[s] == num) {
        printf("index > %d, No. of Comparisons > %d", s, com);    
    } else {
        printf("Not Found");
    }
    return 0;
}