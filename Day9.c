#include <stdio.h>

int main() {
    char c[999]; scanf("%s", &c);
    int n = 0;
    while (c[n] != '\0') {n++;}
    for (int i = n; i > -1; i--){
        printf("%c", c[i]);
    }

    return 0;
}